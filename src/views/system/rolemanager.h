#pragma once
#include <QWidget>
#include <QStandardItemModel>
#include <QTreeWidgetItem>
#include <QString>
#include <QStringList>

namespace Ui {
class RoleManager;
}

class RoleManager : public QWidget
{
    Q_OBJECT
public:
    explicit RoleManager(QWidget* parent = nullptr);
    ~RoleManager();

private slots:
    void onAddRoleClicked();
    void onEditRoleClicked();
    void onDeleteRoleClicked();
    void onSavePermissionsClicked();
    void onRefreshClicked();

private:
    void initUI();
    void setupConnections();
    void loadRoleList();
    void loadPermissionList(int roleId);
    void collectPermissions(QTreeWidgetItem* item, QStringList& permissions, const QString& parentPath);
    void setPermissionChecked(QTreeWidgetItem* item, const QStringList& permissions);

    Ui::RoleManager* ui;
    QStandardItemModel* m_roleModel;
}; 