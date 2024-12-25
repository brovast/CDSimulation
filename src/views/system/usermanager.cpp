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
    headers << "ID" << "用户名" << "角色" << "状态";
    m_userModel->setHorizontalHeaderLabels(headers);
    ui->tableView->setModel(m_userModel);

    // 设置列宽
    ui->tableView->setColumnWidth(0, 50);  // ID列
    ui->tableView->setColumnWidth(1, 150); // 用户名列
    ui->tableView->setColumnWidth(2, 100); // 角色列
    ui->tableView->setColumnWidth(3, 100); // 状态列

    // 设置表格属性
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 根据当前登录用户角色设置按钮状态
    bool isAdmin = true; // TODO: 根据实际登录用户角色设置
    ui->btnEdit->setEnabled(isAdmin);
    ui->btnDelete->setEnabled(isAdmin);
    ui->btnApprove->setEnabled(isAdmin);
    ui->btnReject->setEnabled(isAdmin);
    ui->groupBoxEdit->setEnabled(isAdmin);

    // 当选择用户时更新角色下拉框
    connect(ui->tableView->selectionModel(), &QItemSelectionModel::currentRowChanged,
            this, [this](const QModelIndex& current, const QModelIndex&) {
                if (current.isValid()) {
                    QString role = m_userModel->item(current.row(), 2)->text();
                    ui->comboBoxRole->setCurrentText(role);
                }
            });
}

void UserManager::setupConnections()
{
    connect(ui->btnRefresh, &QPushButton::clicked, this, &UserManager::onRefreshClicked);
    connect(ui->btnEdit, &QPushButton::clicked, this, &UserManager::onEditClicked);
    connect(ui->btnDelete, &QPushButton::clicked, this, &UserManager::onDeleteClicked);
    connect(ui->btnApprove, &QPushButton::clicked, this, &UserManager::onApproveClicked);
    connect(ui->btnReject, &QPushButton::clicked, this, &UserManager::onRejectClicked);
    connect(ui->comboBoxStatus, QOverload<int>::of(&QComboBox::currentIndexChanged), 
            this, &UserManager::onRefreshClicked);
}

void UserManager::loadUserList()
{
    m_userModel->removeRows(0, m_userModel->rowCount());
    
    int statusFilter = ui->comboBoxStatus->currentIndex() - 1;
    QList<Database::UserInfo> users = Database::getInstance().getUserList(statusFilter);
    
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
        
        // 设置每列的对齐方式
        for (auto* item : row) {
            item->setTextAlignment(Qt::AlignCenter);
        }
        
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
    QString username = m_userModel->item(row, 1)->text();
    QString status = m_userModel->item(row, 3)->text();
    
    // 只能编辑已审批的用户
    if (status != "已审批") {
        QMessageBox::warning(this, "警告", "只能编辑已审批的用户！");
        return;
    }
    
    // 不能修改admin用户的角色
    if (username == "admin") {
        QMessageBox::warning(this, "警告", "不能修改管理员账户的角色！");
        return;
    }

    // 获取新的角色ID
    int roleId = ui->comboBoxRole->currentText() == "管理员" ? 1 : 2;
    
    if (Database::getInstance().updateUserRole(userId, roleId)) {
        QMessageBox::information(this, "提示", "角色修改成功！");
        loadUserList();
    } else {
        QMessageBox::critical(this, "错误", "角色修改失败！");
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
    QString username = m_userModel->item(row, 1)->text();
    
    // 不能删除admin用户
    if (username == "admin") {
        QMessageBox::warning(this, "警告", "不能删除管理员账户！");
        return;
    }
    
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
    QString status = m_userModel->item(row, 3)->text();
    
    // 只能审批待审批的用户
    if (status != "待审批") {
        QMessageBox::warning(this, "警告", "只能审批待审批状态的用户！");
        return;
    }
    
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
    QString status = m_userModel->item(row, 3)->text();
    
    // 只能拒绝待审批的用户
    if (status != "待审批") {
        QMessageBox::warning(this, "警告", "只能拒绝待审批状态的用户！");
        return;
    }
    
    if (Database::getInstance().updateUserStatus(userId, 2, 1)) { // 2表示拒绝，1是管理员ID
        QMessageBox::information(this, "提示", "已拒绝该用户！");
        loadUserList();
    } else {
        QMessageBox::critical(this, "错误", "操作失败！");
    }
} 