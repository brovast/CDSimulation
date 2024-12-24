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
        
        // 根据角色打开相应的主界面
        if (roleId == 1) { // 管理员
            SystemManager* systemManager = new SystemManager();
            systemManager->show();
        } else { // 工程师
            Workbench* workbench = new Workbench(userId);
            workbench->show();
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