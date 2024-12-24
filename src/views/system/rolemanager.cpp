#include "rolemanager.h"
#include "ui_rolemanager.h"
#include "../../core/database.h"
#include <QMessageBox>
#include <QInputDialog>

RoleManager::RoleManager(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::RoleManager)
    , m_roleModel(new QStandardItemModel(this))
{
    ui->setupUi(this);
    initUI();
    setupConnections();
    loadRoleList();
}

RoleManager::~RoleManager()
{
    delete ui;
}

void RoleManager::initUI()
{
    // 设置表格标题
    QStringList headers;
    headers << "ID" << "角色名称" << "权限";
    m_roleModel->setHorizontalHeaderLabels(headers);
    ui->tableView->setModel(m_roleModel);
    
    // 设置列宽
    ui->tableView->setColumnWidth(0, 50);  // ID列
    ui->tableView->setColumnWidth(1, 150); // 角色名称列
    ui->tableView->setColumnWidth(2, 200); // 权限列
    
    // 设置权限树
    QTreeWidgetItem* dataManage = new QTreeWidgetItem(ui->treePermissions);
    dataManage->setText(0, "数据管理");
    dataManage->setFlags(dataManage->flags() | Qt::ItemIsUserCheckable);
    dataManage->setCheckState(0, Qt::Unchecked);
    
    QTreeWidgetItem* taskManage = new QTreeWidgetItem(ui->treePermissions);
    taskManage->setText(0, "任务管理");
    taskManage->setFlags(taskManage->flags() | Qt::ItemIsUserCheckable);
    taskManage->setCheckState(0, Qt::Unchecked);
    
    QTreeWidgetItem* systemManage = new QTreeWidgetItem(ui->treePermissions);
    systemManage->setText(0, "系统管理");
    systemManage->setFlags(systemManage->flags() | Qt::ItemIsUserCheckable);
    systemManage->setCheckState(0, Qt::Unchecked);
}

void RoleManager::setupConnections()
{
    connect(ui->btnAddRole, &QPushButton::clicked, this, &RoleManager::onAddRoleClicked);
    connect(ui->btnEditRole, &QPushButton::clicked, this, &RoleManager::onEditRoleClicked);
    connect(ui->btnDeleteRole, &QPushButton::clicked, this, &RoleManager::onDeleteRoleClicked);
    connect(ui->btnSavePermissions, &QPushButton::clicked, this, &RoleManager::onSavePermissionsClicked);
    connect(ui->btnRefresh, &QPushButton::clicked, this, &RoleManager::onRefreshClicked);
    
    // 当选择角色时加载对应的权限
    connect(ui->tableView->selectionModel(), &QItemSelectionModel::currentRowChanged,
            this, [this](const QModelIndex& current, const QModelIndex&) {
                if (current.isValid()) {
                    int roleId = m_roleModel->item(current.row(), 0)->text().toInt();
                    loadPermissionList(roleId);
                }
            });
}

void RoleManager::loadRoleList()
{
    m_roleModel->removeRows(0, m_roleModel->rowCount());
    
    QList<Database::RoleInfo> roles = Database::getInstance().getRoleList();
    for (const auto& role : roles) {
        QList<QStandardItem*> items;
        items << new QStandardItem(QString::number(role.id))
              << new QStandardItem(role.name)
              << new QStandardItem(role.permissions);
        m_roleModel->appendRow(items);
    }
}

void RoleManager::loadPermissionList(int roleId)
{
    // 获取角色权限
    QList<Database::RoleInfo> roles = Database::getInstance().getRoleList();
    QString permissions;
    for (const auto& role : roles) {
        if (role.id == roleId) {
            permissions = role.permissions;
            break;
        }
    }
    
    // 更新权限树的选中状态
    for (int i = 0; i < ui->treePermissions->topLevelItemCount(); ++i) {
        QTreeWidgetItem* item = ui->treePermissions->topLevelItem(i);
        QString permName = item->text(0);
        if (permissions.contains(permName)) {
            item->setCheckState(0, Qt::Checked);
        } else {
            item->setCheckState(0, Qt::Unchecked);
        }
    }
}

void RoleManager::onAddRoleClicked()
{
    bool ok;
    QString name = QInputDialog::getText(this, "添加角色",
                                       "请输入角色名称：", QLineEdit::Normal,
                                       "", &ok);
    if (ok && !name.isEmpty()) {
        if (Database::getInstance().addRole(name, "")) {
            loadRoleList();
        } else {
            QMessageBox::critical(this, "错误", "添加角色失败！");
        }
    }
}

void RoleManager::onEditRoleClicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请先选择一个角色！");
        return;
    }
    
    int row = index.row();
    int roleId = m_roleModel->item(row, 0)->text().toInt();
    QString oldName = m_roleModel->item(row, 1)->text();
    
    bool ok;
    QString newName = QInputDialog::getText(this, "编辑角色",
                                          "请输入新的角色名称：", QLineEdit::Normal,
                                          oldName, &ok);
    if (ok && !newName.isEmpty()) {
        QString permissions = m_roleModel->item(row, 2)->text();
        if (Database::getInstance().updateRole(roleId, newName, permissions)) {
            loadRoleList();
        } else {
            QMessageBox::critical(this, "错误", "更新角色失败！");
        }
    }
}

void RoleManager::onDeleteRoleClicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请先选择一个角色！");
        return;
    }
    
    int row = index.row();
    int roleId = m_roleModel->item(row, 0)->text().toInt();
    
    if (QMessageBox::question(this, "确认", "确定要删除该角色吗？") == QMessageBox::Yes) {
        if (Database::getInstance().deleteRole(roleId)) {
            loadRoleList();
        } else {
            QMessageBox::critical(this, "错误", "删除角色失败！");
        }
    }
}

void RoleManager::onSavePermissionsClicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请先选择一个角色！");
        return;
    }
    
    int row = index.row();
    int roleId = m_roleModel->item(row, 0)->text().toInt();
    QString roleName = m_roleModel->item(row, 1)->text();
    
    // 收集选中的权限
    QStringList permissions;
    for (int i = 0; i < ui->treePermissions->topLevelItemCount(); ++i) {
        QTreeWidgetItem* item = ui->treePermissions->topLevelItem(i);
        if (item->checkState(0) == Qt::Checked) {
            permissions << item->text(0);
        }
    }
    
    // 更新角色权限
    if (Database::getInstance().updateRole(roleId, roleName, permissions.join(","))) {
        loadRoleList();
        QMessageBox::information(this, "提示", "权限保存成功！");
    } else {
        QMessageBox::critical(this, "错误", "权限保存失败！");
    }
}

void RoleManager::onRefreshClicked()
{
    loadRoleList();
} 