#include "user_edit_dialog.h"
#include "ui_user_edit_dialog.h"
#include "../../core/database.h"
#include <QMessageBox>

UserEditDialog::UserEditDialog(int userId, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::UserEditDialog)
    , m_userId(userId)
{
    ui->setupUi(this);
    initUI();
    loadRoles();
    loadUserInfo();
    
    connect(ui->btnSave, &QPushButton::clicked, this, &UserEditDialog::onSaveClicked);
    connect(ui->btnCancel, &QPushButton::clicked, this, &UserEditDialog::onCancelClicked);
}

UserEditDialog::~UserEditDialog()
{
    delete ui;
}

void UserEditDialog::initUI()
{
    setWindowTitle("编辑用户");
    setFixedSize(300, 200);
}

void UserEditDialog::loadRoles()
{
    QList<Database::RoleInfo> roles = Database::getInstance().getRoleList();
    for (const auto& role : roles) {
        ui->comboBoxRole->addItem(role.name, role.id);
    }
}

void UserEditDialog::loadUserInfo()
{
    // TODO: 从数据库加载用户信息
    // 设置用户名和角色
}

void UserEditDialog::onSaveClicked()
{
    int roleId = ui->comboBoxRole->currentData().toInt();
    QString newPassword = ui->lineEditPassword->text();
    
    // TODO: 更新用户信息
    // 1. 如果密码不为空，更新密码
    // 2. 更新角色
    
    accept();
}

void UserEditDialog::onCancelClicked()
{
    reject();
} 