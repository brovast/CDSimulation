/********************************************************************************
** Form generated from reading UI file 'user_edit_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_EDIT_DIALOG_H
#define UI_USER_EDIT_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UserEditDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelUsername;
    QLineEdit *lineEditUsername;
    QLabel *labelRole;
    QComboBox *comboBoxRole;
    QLabel *labelPassword;
    QLineEdit *lineEditPassword;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;

    void setupUi(QDialog *UserEditDialog)
    {
        if (UserEditDialog->objectName().isEmpty())
            UserEditDialog->setObjectName("UserEditDialog");
        UserEditDialog->resize(300, 200);
        verticalLayout = new QVBoxLayout(UserEditDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelUsername = new QLabel(UserEditDialog);
        labelUsername->setObjectName("labelUsername");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelUsername);

        lineEditUsername = new QLineEdit(UserEditDialog);
        lineEditUsername->setObjectName("lineEditUsername");
        lineEditUsername->setEnabled(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditUsername);

        labelRole = new QLabel(UserEditDialog);
        labelRole->setObjectName("labelRole");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelRole);

        comboBoxRole = new QComboBox(UserEditDialog);
        comboBoxRole->setObjectName("comboBoxRole");

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBoxRole);

        labelPassword = new QLabel(UserEditDialog);
        labelPassword->setObjectName("labelPassword");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelPassword);

        lineEditPassword = new QLineEdit(UserEditDialog);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditPassword);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(UserEditDialog);
        btnSave->setObjectName("btnSave");

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(UserEditDialog);
        btnCancel->setObjectName("btnCancel");

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(UserEditDialog);

        QMetaObject::connectSlotsByName(UserEditDialog);
    } // setupUi

    void retranslateUi(QDialog *UserEditDialog)
    {
        UserEditDialog->setWindowTitle(QCoreApplication::translate("UserEditDialog", "\347\274\226\350\276\221\347\224\250\346\210\267", nullptr));
        labelUsername->setText(QCoreApplication::translate("UserEditDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        labelRole->setText(QCoreApplication::translate("UserEditDialog", "\350\247\222\350\211\262\357\274\232", nullptr));
        labelPassword->setText(QCoreApplication::translate("UserEditDialog", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        lineEditPassword->setPlaceholderText(QCoreApplication::translate("UserEditDialog", "\347\225\231\347\251\272\350\241\250\347\244\272\344\270\215\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        btnSave->setText(QCoreApplication::translate("UserEditDialog", "\344\277\235\345\255\230", nullptr));
        btnCancel->setText(QCoreApplication::translate("UserEditDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserEditDialog: public Ui_UserEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_EDIT_DIALOG_H
