#include "rolemanager.h"
#include "ui_rolemanager.h"
#include "../../core/database.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QTreeWidgetItem>

// 先实现辅助函数
void RoleManager::collectPermissions(QTreeWidgetItem* item, QStringList& permissions, const QString& parentPath)
{
    if (!item) return;
    
    QString currentPath = parentPath.isEmpty() ? 
                         item->text(0) : 
                         parentPath + "/" + item->text(0);
    
    if (item->checkState(0) == Qt::Checked) {
        permissions << currentPath;
    }
    
    for (int i = 0; i < item->childCount(); ++i) {
        collectPermissions(item->child(i), permissions, currentPath);
    }
}

void RoleManager::setPermissionChecked(QTreeWidgetItem* item, const QStringList& permissions)
{
    if (!item) return;
    
    QString path = item->text(0);
    QTreeWidgetItem* parent = item->parent();
    while (parent) {
        path = parent->text(0) + "/" + path;
        parent = parent->parent();
    }
    
    if (permissions.contains(path)) {
        item->setCheckState(0, Qt::Checked);
    } else {
        item->setCheckState(0, Qt::Unchecked);
    }
    
    for (int i = 0; i < item->childCount(); ++i) {
        setPermissionChecked(item->child(i), permissions);
    }
}

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
        
        // ID列
        items << new QStandardItem(QString::number(role.id));
        
        // 角色名称列
        items << new QStandardItem(role.name);
        
        // 权限列 - 格式化显示权限
        QStringList permList = role.permissions.split(",", Qt::SkipEmptyParts);
        QString displayPerms;
        for (const QString& perm : permList) {
            if (!displayPerms.isEmpty()) {
                displayPerms += "\n";
            }
            // 将路径形式的权限转换为更易读的形式
            QString displayPerm = perm;
            if (perm.contains("/")) {
                QStringList parts = perm.split("/");
                displayPerm = "  " + parts.last();  // 添加缩进
            }
            displayPerms += displayPerm;
        }
        items << new QStandardItem(displayPerms);
        
        m_roleModel->appendRow(items);
    }
    
    // 自动选中第一行并加载其权限
    if (m_roleModel->rowCount() > 0) {
        ui->tableView->selectRow(0);
        loadPermissionList(m_roleModel->item(0, 0)->text().toInt());
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
    
    // 根据权限设置下拉框
    if (permissions.contains("登录权限/系统管理登录")) {
        ui->comboBoxPermission->setCurrentText("系统管理");
    } else {
        ui->comboBoxPermission->setCurrentText("工作台");
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
    
    // 根据下拉框选择设置权限
    QString permissions;
    if (ui->comboBoxPermission->currentText() == "系统管理") {
        permissions = "登录权限/系统管理登录,登录权限/工作台登录";
    } else {
        permissions = "登录权限/工作台登录";
    }
    
    // 更新角色权限
    if (Database::getInstance().updateRole(roleId, roleName, permissions)) {
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