#include "Editor.h"
#include <QStatusBar>
#include <IApproxShaderLabExternalControl.h>
#include <IApproxShaderLabControl.h>
#include "rendererwrapper.h"
#include "MaterialSettingsUI.h"

#include <Promise.h>
#include <ApproxSystemErrors.h>

/*#define DECL_Q_OBJECT(className, memberClass) class className : public QObject\
				{\
				public:\
				memberClass memberName;\
				template<class ...Ts> className(QObject *parent,Ts... args):QObject(parent),memberName(args...){}\
				}
				*/
static const int maxTabWidth = 200;

using namespace std;

Q_DECLARE_METATYPE(IExternalRenderObject*);
Q_DECLARE_METATYPE(MaterialSettingsUI*);

//typedef DECL_Q_OBJECT(threadWrapper, std::thread) QObjectThread;

Editor::Editor(QWidget *parent)
	: ApproxWindow(), m_rendererWrp(nullptr), m_modelLoader(this), m_renderingWindowX(7), m_renderingWindowY(65)
{
	ui.setupUi(client);
	InitUI();
	m_asl = ASL::GetASLControl();
	m_StatusBarText = new QLabel(client);
	m_rendererWrp = new RendererWrapper(client);
	m_statusBar = new QStatusBar(client);
	m_rendererWrp->hide();
	m_menuBar = new QMenuBar(client);
	QMenu* subMenu1 = m_menuBar->addMenu(QStringLiteral("Действия"));
	QMenu* subMenu2 = m_menuBar->addMenu(QStringLiteral("Инструменты"));

	actRunEngine = subMenu1->addAction(QStringLiteral("Запустить графику"));
	actLoadModel = subMenu1->addAction(QStringLiteral("Загрузить модель"));
	actShaderLab = subMenu2->addAction(QStringLiteral("Редактор шейдеров"));

	actLoadModel->setEnabled(false);

	connect(actRunEngine, SIGNAL(triggered()), SLOT(sl_RunEngine()));
	connect(actShaderLab, SIGNAL(triggered()), SLOT(sl_RunShaderLab()));
	connect(actLoadModel, SIGNAL(triggered()), &m_modelLoader, SLOT(show()));
	connect(&m_modelLoader, SIGNAL(accepted()), SLOT(sl_LoadModel()));
	connect(ui.treeWidget, &QTreeWidget::itemClicked, this, &Editor::on_SceneItemClick);
	client->layout()->addWidget(m_statusBar);
	m_statusBar->addPermanentWidget(m_StatusBarText);
	done = false;
}

void Editor::sl_RunEngine()
{
	m_rendererWrp->show();
	m_rendererWrp->Initialize();
	m_rendererWrp->Run();
	m_rendererWrp->move(0, 35);
	start_update_thread();
	resize(m_rendererWrp->width() + ui.treeWidget->width(), m_rendererWrp->height() + 100);
	ui.tabWidget->move(m_rendererWrp->width(), 0);
    m_rendererWrp->NativeInterface()->GetRendererEx()->get_scene()->SetASLInterface(dynamic_cast<ASL::IApproxShaderLabExternalControl*>(m_asl));
	actRunEngine->setEnabled(false);
	actLoadModel->setEnabled(true);
	m_modelLoader.SetAvailableShaders(m_rendererWrp->NativeInterface()->GetRendererEx()->AvailableShadersDesc());
}


void Editor::start_update_thread() {
	done = false;
	update_thread = make_unique<std::thread>(&Editor::Update, this);
}

void Editor::stop_update_thread() {
	if (!update_thread)
		return;

	done = true;
	if (update_thread->joinable())
		update_thread->join();
	update_thread = nullptr;
}

void Editor::sl_LoadModel()
{
	int ShaderID;
	string objFile;
	vector<string> ddsFiles;
	m_modelLoader.GetInitData(objFile, ddsFiles, ShaderID);
	m_rendererWrp->LoadModel(objFile, ShaderID).then([&](IExternalRenderObject* object){
		for (unsigned short i = 0; i < ddsFiles.size(); i++)
		{
			object->material(0).lock()->LoadTexture(ddsFiles[i].c_str(), i);
		}
		m_objects.push_back(object);
		QTreeWidgetItem *item = new QTreeWidgetItem();
		item->setData(0, Qt::UserRole, QVariant::fromValue<IExternalRenderObject*>(object));
		item->setText(0, QString("RenderObject"));
		ui.treeWidget->addTopLevelItem(item);
	});
}

void Editor::sl_RunShaderLab()
{
	m_asl->Run();
}

void Editor::on_SceneItemClick(QTreeWidgetItem* item, int col)
{
	if (!item->data(1, Qt::UserRole).value<MaterialSettingsUI*>())
	{
		auto object = item->data(0, Qt::UserRole).value<IExternalRenderObject*>();
		MaterialSettingsUI* dialog = new MaterialSettingsUI(this, object->material(0).lock().get());
		item->setData(1, Qt::UserRole, QVariant::fromValue<MaterialSettingsUI*>(dialog));
		connect(dialog, &MaterialSettingsUI::closed, [=]()
		{
			item->setData(1, Qt::UserRole, QVariant::fromValue<MaterialSettingsUI*>(nullptr));
		});
		dialog->show();
	}
}

bool Editor::nativeEvent(const QByteArray& event_type, void* message, long* result)
{
	if (event_type == "windows_generic_MSG")
	{
		if (m_rendererWrp)
		{
			return m_rendererWrp->ExternalNativeEvent(event_type, message, result);
		}
		return false;
	}
	return false;
}

void Editor::Update()
{
	while (!done)
	{
		if (m_rendererWrp->NativeInterface()->State().Renderer != SYS_NOT_INITIALIZED)
		{
			float x, y, z;
			m_rendererWrp->GetCameraPos(x, y, z);
			m_StatusBarText->setText("Camera position X=" + QString().setNum(x) + "  Y=" + QString().setNum(y) + "  Z=" + QString().setNum(z));
			m_statusBar->update();
		}
		this_thread::sleep_for(chrono::milliseconds(16));
	}
}

void Editor::moveEvent(QMoveEvent *event)
{
	if (m_rendererWrp)
		m_rendererWrp->PosUpdate();
}

void Editor::closeEvent(QCloseEvent* event)
{
	done = true;
	if (m_rendererWrp)
		m_rendererWrp->Shutdown();
	if (m_asl)
		m_asl->Shutdown();

	stop_update_thread();
	QApplication::quit();
}

void Editor::resizeEvent(QResizeEvent* e)
{
	int tabWidth = width() - m_rendererWrp->x() - m_rendererWrp->width();
	if (tabWidth > maxTabWidth){ tabWidth = maxTabWidth; }

	ui.tabWidget->setGeometry(width() - tabWidth, ButtonSize(), tabWidth, height() - ButtonSize() - m_menuBar->height());

	ApproxWindow::resizeEvent(e);
}

Editor::~Editor()
{

}
