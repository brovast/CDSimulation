/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *radioGroupRole;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioAdmin;
    QRadioButton *radioEngineer;
    QFormLayout *formLayout;
    QLabel *labelUsername;
    QLineEdit *lineEditUsername;
    QLabel *labelPassword;
    QLineEdit *lineEditPassword;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnConfig;
    QPushButton *btnRegister;
    QPushButton *btnLogin;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(400, 300);
        verticalLayout = new QVBoxLayout(Login);
        verticalLayout->setObjectName("verticalLayout");
        radioGroupRole = new QGroupBox(Login);
        radioGroupRole->setObjectName("radioGroupRole");
        horizontalLayout = new QHBoxLayout(radioGroupRole);
        horizontalLayout->setObjectName("horizontalLayout");
        radioAdmin = new QRadioButton(radioGroupRole);
        radioAdmin->setObjectName("radioAdmin");

        horizontalLayout->addWidget(radioAdmin);

        radioEngineer = new QRadioButton(radioGroupRole);
        radioEngineer->setObjectName("radioEngineer");

        horizontalLayout->addWidget(radioEngineer);


        verticalLayout->addWidget(radioGroupRole);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelUsername = new QLabel(Login);
        labelUsername->setObjectName("labelUsername");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelUsername);

        lineEditUsername = new QLineEdit(Login);
        lineEditUsername->setObjectName("lineEditUsername");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditUsername);

        labelPassword = new QLabel(Login);
        labelPassword->setObjectName("labelPassword");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelPassword);

        lineEditPassword = new QLineEdit(Login);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditPassword);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnConfig = new QPushButton(Login);
        btnConfig->setObjectName("btnConfig");

        horizontalLayout_2->addWidget(btnConfig);

        btnRegister = new QPushButton(Login);
        btnRegister->setObjectName("btnRegister");

        horizontalLayout_2->addWidget(btnRegister);

        btnLogin = new QPushButton(Login);
        btnLogin->setObjectName("btnLogin");

        horizontalLayout_2->addWidget(btnLogin);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        radioGroupRole->setTitle(QCoreApplication::translate("Login", "\350\247\222\350\211\262\351\200\211\346\213\251", nullptr));
        radioAdmin->setText(QCoreApplication::translate("Login", "\347\256\241\347\220\206\345\221\230", nullptr));
        radioEngineer->setText(QCoreApplication::translate("Login", "\345\267\245\347\250\213\345\270\210", nullptr));
        labelUsername->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        labelPassword->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201\357\274\232", nullptr));
        btnConfig->setText(QCoreApplication::translate("Login", "\351\205\215\347\275\256", nullptr));
        btnRegister->setText(QCoreApplication::translate("Login", "\346\263\250\345\206\214", nullptr));
        btnLogin->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
