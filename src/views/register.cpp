#include "register.h"
#include "ui_register.h"
#include "../core/database.h"
#include <QMessageBox>

Register::Register(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::Register)
{
    ui->setupUi(this);
    
    connect(ui->btnRegister, &QPushButton::clicked, this, &Register::onRegisterClicked);
    connect(ui->btnCancel, &QPushButton::clicked, this, &Register::onCancelClicked);
}

Register::~Register()
{
    delete ui;
}

void Register::onRegisterClicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    QString confirmPassword = ui->lineEditConfirmPassword->text();
    
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "警告", "用户名和密码不能为空！");
        return;
    }
    
    if (password != confirmPassword) {
        QMessageBox::warning(this, "警告", "两次输入的密码不一致！");
        return;
    }
    
    // 默认注册为工程师角色(roleId=2)
    if (Database::getInstance().addUser(username, password, 2)) {
        QMessageBox::information(this, "提示", "注册成功，请等待管理员审批！");
        accept();
    } else {
        QMessageBox::warning(this, "错误", "注册失败，用户名可能已存在！");
    }
}

void Register::onCancelClicked()
{
    reject();
} 