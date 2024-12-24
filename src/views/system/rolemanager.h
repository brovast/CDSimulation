#pragma once
#include <QWidget>
#include <QStandardItemModel>

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

    Ui::RoleManager* ui;
    QStandardItemModel* m_roleModel;
}; 