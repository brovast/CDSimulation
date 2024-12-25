/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelUsername;
    QLineEdit *lineEditUsername;
    QLabel *labelPassword;
    QLineEdit *lineEditPassword;
    QLabel *labelConfirmPassword;
    QLineEdit *lineEditConfirmPassword;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnRegister;
    QPushButton *btnCancel;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName("Register");
        Register->resize(300, 200);
        verticalLayout = new QVBoxLayout(Register);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelUsername = new QLabel(Register);
        labelUsername->setObjectName("labelUsername");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelUsername);

        lineEditUsername = new QLineEdit(Register);
        lineEditUsername->setObjectName("lineEditUsername");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditUsername);

        labelPassword = new QLabel(Register);
        labelPassword->setObjectName("labelPassword");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelPassword);

        lineEditPassword = new QLineEdit(Register);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditPassword);

        labelConfirmPassword = new QLabel(Register);
        labelConfirmPassword->setObjectName("labelConfirmPassword");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelConfirmPassword);

        lineEditConfirmPassword = new QLineEdit(Register);
        lineEditConfirmPassword->setObjectName("lineEditConfirmPassword");
        lineEditConfirmPassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditConfirmPassword);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnRegister = new QPushButton(Register);
        btnRegister->setObjectName("btnRegister");

        horizontalLayout->addWidget(btnRegister);

        btnCancel = new QPushButton(Register);
        btnCancel->setObjectName("btnCancel");

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "\347\224\250\346\210\267\346\263\250\345\206\214", nullptr));
        labelUsername->setText(QCoreApplication::translate("Register", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        labelPassword->setText(QCoreApplication::translate("Register", "\345\257\206\347\240\201\357\274\232", nullptr));
        labelConfirmPassword->setText(QCoreApplication::translate("Register", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        btnRegister->setText(QCoreApplication::translate("Register", "\346\263\250\345\206\214", nullptr));
        btnCancel->setText(QCoreApplication::translate("Register", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
