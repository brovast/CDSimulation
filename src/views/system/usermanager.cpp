#include "usermanager.h"
#include "ui_usermanager.h"
#include "../../core/database.h"
#include "./user_edit_dialog.h"
#include <QMessageBox>
#include <QDateTime>

UserManager::UserManager(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::UserManager)
    , m_userModel(new QStandardItemModel(this))
{
    ui->setupUi(this);
    initUI();
    setupConnections();
    loadUserList();
}

UserManager::~UserManager()
{
    delete ui;
}

void UserManager::initUI()
{
    // 设置表格标题
    QStringList headers;
    headers << "ID" << "用户名" << "角色" << "状态" << "创建时间";
    m_userModel->setHorizontalHeaderLabels(headers);
    ui->tableView->setModel(m_userModel);

    // 设置列宽
    ui->tableView->setColumnWidth(0, 50);  // ID列
    ui->tableView->setColumnWidth(1, 150); // 用户名列
    ui->tableView->setColumnWidth(2, 100); // 角色列
    ui->tableView->setColumnWidth(3, 100); // 状态列
    ui->tableView->setColumnWidth(4, 200); // 创建时间列
}

void UserManager::setupConnections()
{
    connect(ui->btnRefresh, &QPushButton::clicked, this, &UserManager::onRefreshClicked);
    connect(ui->btnEdit, &QPushButton::clicked, this, &UserManager::onEditClicked);
    connect(ui->btnDelete, &QPushButton::clicked, this, &UserManager::onDeleteClicked);
    connect(ui->btnApprove, &QPushButton::clicked, this, &UserManager::onApproveClicked);
    connect(ui->btnReject, &QPushButton::clicked, this, &UserManager::onRejectClicked);
    connect(ui->comboBoxStatus, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &UserManager::onRefreshClicked);
}

void UserManager::loadUserList()
{
    // 清空现有数据
    m_userModel->removeRows(0, m_userModel->rowCount());
    
    // 获取状态筛选条件
    int statusFilter = ui->comboBoxStatus->currentIndex() - 1; // -1表示全部
    
    // 从数据库获取用户列表
    QList<Database::UserInfo> users = Database::getInstance().getUserList(statusFilter);
    
    // 更新表格模型
    for (const auto& user : users) {
        QList<QStandardItem*> row;
        
        // ID
        row.append(new QStandardItem(QString::number(user.id)));
        
        // 用户名
        row.append(new QStandardItem(user.username));
        
        // 角色
        row.append(new QStandardItem(user.roleName));
        
        // 状态
        QString statusText;
        switch (user.status) {
            case 0: statusText = "待审批"; break;
            case 1: statusText = "已审批"; break;
            case 2: statusText = "已拒绝"; break;
            default: statusText = "未知";
        }
        row.append(new QStandardItem(statusText));
        
        // 创建时间
        row.append(new QStandardItem(user.createTime.toString("yyyy-MM-dd hh:mm:ss")));
        
        m_userModel->appendRow(row);
    }
}

void UserManager::onRefreshClicked()
{
    loadUserList();
}

void UserManager::onEditClicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请先选择一个用户！");
        return;
    }
    
    int row = index.row();
    int userId = m_userModel->item(row, 0)->text().toInt();
    
    UserEditDialog dialog(userId, this);
    if (dialog.exec() == QDialog::Accepted) {
        loadUserList();
    }
}

void UserManager::onDeleteClicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请先选择一个用户！");
        return;
    }
    
    int row = index.row();
    int userId = m_userModel->item(row, 0)->text().toInt();
    
    if (QMessageBox::question(this, "确认", "确定要删除该用户吗？") == QMessageBox::Yes) {
        if (Database::getInstance().deleteUser(userId)) {
            QMessageBox::information(this, "提示", "删除成功！");
            loadUserList();
        } else {
            QMessageBox::critical(this, "错误", "删除失败！");
        }
    }
}

void UserManager::onApproveClicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请先选择一个用户！");
        return;
    }
    
    int row = index.row();
    int userId = m_userModel->item(row, 0)->text().toInt();
    
    if (Database::getInstance().updateUserStatus(userId, 1, 1)) { // 1表示通过，第二个1是管理员ID
        QMessageBox::information(this, "提示", "审批通过成功！");
        loadUserList();
    } else {
        QMessageBox::critical(this, "错误", "审批失败！");
    }
}

void UserManager::onRejectClicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请先选择一个用户！");
        return;
    }
    
    int row = index.row();
    int userId = m_userModel->item(row, 0)->text().toInt();
    
    if (Database::getInstance().updateUserStatus(userId, 2, 1)) { // 2表示拒绝，1是管理员ID
        QMessageBox::information(this, "提示", "已拒绝该用户！");
        loadUserList();
    } else {
        QMessageBox::critical(this, "错误", "操作失败！");
    }
} 