#ifndef MATERIALSETTINGSUI_H
#define MATERIALSETTINGSUI_H

#include <QWidget>
#include <unordered_map>
#include <GenericType.h>

struct IExternalMaterial;
class QPushButton;


class MaterialSettingsUI : public QWidget
{
	Q_OBJECT

public:
	MaterialSettingsUI(QWidget *parent, IExternalMaterial* material);
	~MaterialSettingsUI();
signals:
	void closed();
private:
	std::unordered_map<ShaderSystem::GenericType, QWidget*> m_Param;
	void closeEvent(QCloseEvent*)override;
	QPushButton* btnOK;
};

#endif // MATERIALSETTINGSUI_H
