#include "shaderlabgui.h"
#include "Controller.h"
#include "ShaderEditor.h"
#include "GlobalSettingsForm.h"
#include "ApproxGUIMenuButton.h"
#include "ApproxGUIMenuBar.h"

using namespace ApproxGUI;

namespace ASL
{
	ShaderLabGUI::ShaderLabGUI(IControllerSession* ctrl)
		:ApproxWindow(), m_ctrl(ctrl), m_rendererOnline(false)
	{
		ui.setupUi(client);
		InitUI();
		
		m_Menu = new ApproxGUIMenuBar(client);
		m_btnSettings = new ApproxGUIMenuButton;
		m_btnAddView = new ApproxGUIMenuButton;
		m_settings = new GlobalSettingsForm(client);

		connect(m_btnSettings, SIGNAL(clicked()), SLOT(on_Settings()));
		connect(m_btnAddView, SIGNAL(clicked()), SLOT(on_NewView()));

		m_Menu->addWidget(m_btnSettings);
		m_Menu->addWidget(m_btnAddView);
		m_Menu->move(0, 0);
		m_Menu->setStyleSheet("background-color : rgb(30,30,30);");

		m_btnSettings->setText(QStringLiteral("����� ���������"));

		m_btnAddView->move(m_btnAddView->width(), 0);
		m_btnAddView->setText(QStringLiteral("����� ������"));

		m_settings->setGeometry(0, 25, m_settings->width(), client->height() - 50);
		m_settings->hide();

		ShaderEditor* newView = new ShaderEditor(m_ctrl, client);
		m_Views.insert(std::pair<QString, ShaderEditor*>(generateViewName(), newView));

		for (auto elem : m_Views)
		{
			elem.second->show();
		}
	}

	void ShaderLabGUI::on_Settings()
	{
		if (m_settings->isHidden())
		{
			m_settings->setGeometry(0, 25, m_settings->width(), client->height() - 50);
			m_settings->show();
			m_settings->raise();
			for (auto view : m_Views)
			{
				view.second->FadeIn();
			}
		}
		else
		{
			m_settings->hide();
			for (auto view : m_Views)
			{
				view.second->FadeOut();
			}
		}
	}

	void ShaderLabGUI::on_NewView()
	{
		ShaderEditor* newView = new ShaderEditor(m_ctrl, client);
		m_Views.insert(std::pair<QString, ShaderEditor*>(generateViewName(), newView));
		newView->SetMaterialVariables(m_varInfo,m_mi_version);
		newView->RendererOnline(m_rendererOnline);
		newView->show();
	}

	ShaderLabGUI::~ShaderLabGUI()
	{

	}

	void ShaderLabGUI::SetMaterialInterfaceInfo(std::vector<MaterialVarInfo>& info, const QString& ver)
	{
		m_rendererOnline = true;
		m_varInfo = info;
		m_mi_version =  ver;
		for (auto view : m_Views)
		{
			view.second->SetMaterialVariables(m_varInfo, m_mi_version);
			view.second->RendererOnline(true);
		}
	}

	void ShaderLabGUI::resizeEvent(QResizeEvent* e)
	{
		ApproxWindow::resizeEvent(e);
		m_Menu->resize(client->width(), 25);
	}

	QString ShaderLabGUI::generateViewName()
	{
		static int number(1);
		char num[2] = "0";
		QString newName("View_");
		auto res = m_Views.find(newName + "0\0");
		while (res != m_Views.end())
		{
			_itoa_s(number, num, 2, 10);
			res = m_Views.find(newName + num);
			number++;
		}
		return newName + num;
	}

	void ShaderLabGUI::hideEvent(QHideEvent* e)
	{
		ApproxWindow::hideEvent(e);
	}
}