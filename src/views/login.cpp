#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "../core/database.h"
#include "register.h"
#include "config_dialog.h"
#include "./system/systemmanager.h"
#include "workbench.h"

Login::Login(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    
    // 连接信号槽
    connect(ui->btnLogin, &QPushButton::clicked, this, &Login::onLoginClicked);
    connect(ui->btnRegister, &QPushButton::clicked, this, &Login::onRegisterClicked);
    connect(ui->btnConfig, &QPushButton::clicked, this, &Login::onConfigClicked);
    
    // 设置默认选中管理员
    ui->radioAdmin->setChecked(true);
}

Login::~Login()
{
    delete ui;
}

void Login::onLoginClicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "警告", "用户名和密码不能为空！");
        return;
    }
    
    int roleId, status, userId;
    if (Database::getInstance().validateUser(username, password, roleId, status, userId)) {
        if (status == 0) {
            QMessageBox::warning(this, "警告", "账号待审批，请等待管理员审批！");
            return;
        } else if (status == 2) {
            QMessageBox::warning(this, "警告", "账号已被拒绝！");
            return;
        }
        
        // 获取用户权限
        QList<Database::RoleInfo> roles = Database::getInstance().getRoleList();
        QString permissions;
        for (const auto& role : roles) {
            if (role.id == roleId) {
                permissions = role.permissions;
                break;
            }
        }
        
        // 检查登录权限
        bool canSystemLogin = permissions.contains("登录权限/系统管理登录");
        bool canWorkbenchLogin = permissions.contains("登录权限/工作台登录");
        bool isAdminLogin = ui->radioAdmin->isChecked();
        
        if (isAdminLogin && !canSystemLogin) {
            QMessageBox::warning(this, "警告", "您没有系统管理登录权限！");
            return;
        }
        
        // 根据选择的登录方式打开相应界面
        if (isAdminLogin && canSystemLogin) {
            SystemManager* systemManager = new SystemManager();
            systemManager->show();
        } else if (canWorkbenchLogin) {
            Workbench* workbench = new Workbench(userId);
            workbench->show();
        } else {
            QMessageBox::warning(this, "警告", "您没有登录权限！");
            return;
        }
        
        // 隐藏登录界面
        hide();
    } else {
        QMessageBox::warning(this, "错误", "用户名或密码错误！");
    }
}

void Login::onRegisterClicked()
{
    Register registerDialog(this);
    registerDialog.exec();
}

void Login::onConfigClicked()
{
    ConfigDialog configDialog(this);
    configDialog.exec();
} 