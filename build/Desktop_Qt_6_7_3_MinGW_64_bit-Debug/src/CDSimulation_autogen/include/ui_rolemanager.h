/********************************************************************************
** Form generated from reading UI file 'rolemanager.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROLEMANAGER_H
#define UI_ROLEMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoleManager
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAddRole;
    QPushButton *btnEditRole;
    QPushButton *btnDeleteRole;
    QPushButton *btnRefresh;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QGroupBox *groupBoxPermission;
    QFormLayout *formLayout;
    QLabel *labelPermission;
    QComboBox *comboBoxPermission;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnSavePermissions;

    void setupUi(QWidget *RoleManager)
    {
        if (RoleManager->objectName().isEmpty())
            RoleManager->setObjectName("RoleManager");
        verticalLayout = new QVBoxLayout(RoleManager);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnAddRole = new QPushButton(RoleManager);
        btnAddRole->setObjectName("btnAddRole");

        horizontalLayout->addWidget(btnAddRole);

        btnEditRole = new QPushButton(RoleManager);
        btnEditRole->setObjectName("btnEditRole");

        horizontalLayout->addWidget(btnEditRole);

        btnDeleteRole = new QPushButton(RoleManager);
        btnDeleteRole->setObjectName("btnDeleteRole");

        horizontalLayout->addWidget(btnDeleteRole);

        btnRefresh = new QPushButton(RoleManager);
        btnRefresh->setObjectName("btnRefresh");

        horizontalLayout->addWidget(btnRefresh);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(RoleManager);
        tableView->setObjectName("tableView");
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);

        verticalLayout->addWidget(tableView);

        groupBoxPermission = new QGroupBox(RoleManager);
        groupBoxPermission->setObjectName("groupBoxPermission");
        formLayout = new QFormLayout(groupBoxPermission);
        formLayout->setObjectName("formLayout");
        labelPermission = new QLabel(groupBoxPermission);
        labelPermission->setObjectName("labelPermission");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelPermission);

        comboBoxPermission = new QComboBox(groupBoxPermission);
        comboBoxPermission->addItem(QString());
        comboBoxPermission->addItem(QString());
        comboBoxPermission->setObjectName("comboBoxPermission");

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBoxPermission);


        verticalLayout->addWidget(groupBoxPermission);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btnSavePermissions = new QPushButton(RoleManager);
        btnSavePermissions->setObjectName("btnSavePermissions");

        horizontalLayout_2->addWidget(btnSavePermissions);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(RoleManager);

        QMetaObject::connectSlotsByName(RoleManager);
    } // setupUi

    void retranslateUi(QWidget *RoleManager)
    {
        btnAddRole->setText(QCoreApplication::translate("RoleManager", "\346\267\273\345\212\240\350\247\222\350\211\262", nullptr));
        btnEditRole->setText(QCoreApplication::translate("RoleManager", "\347\274\226\350\276\221\350\247\222\350\211\262", nullptr));
        btnDeleteRole->setText(QCoreApplication::translate("RoleManager", "\345\210\240\351\231\244\350\247\222\350\211\262", nullptr));
        btnRefresh->setText(QCoreApplication::translate("RoleManager", "\345\210\267\346\226\260", nullptr));
        groupBoxPermission->setTitle(QCoreApplication::translate("RoleManager", "\346\235\203\351\231\220\350\256\276\347\275\256", nullptr));
        labelPermission->setText(QCoreApplication::translate("RoleManager", "\347\231\273\345\275\225\346\235\203\351\231\220\357\274\232", nullptr));
        comboBoxPermission->setItemText(0, QCoreApplication::translate("RoleManager", "\345\267\245\344\275\234\345\217\260", nullptr));
        comboBoxPermission->setItemText(1, QCoreApplication::translate("RoleManager", "\347\263\273\347\273\237\347\256\241\347\220\206", nullptr));

        btnSavePermissions->setText(QCoreApplication::translate("RoleManager", "\344\277\235\345\255\230\346\235\203\351\231\220\350\256\276\347\275\256", nullptr));
        (void)RoleManager;
    } // retranslateUi

};

namespace Ui {
    class RoleManager: public Ui_RoleManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROLEMANAGER_H
