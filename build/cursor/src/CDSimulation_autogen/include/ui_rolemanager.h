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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoleManager
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnAddRole;
    QPushButton *btnEditRole;
    QPushButton *btnDeleteRole;
    QPushButton *btnRefresh;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTreeWidget *treePermissions;
    QPushButton *btnSavePermissions;

    void setupUi(QWidget *RoleManager)
    {
        if (RoleManager->objectName().isEmpty())
            RoleManager->setObjectName("RoleManager");
        horizontalLayout = new QHBoxLayout(RoleManager);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnAddRole = new QPushButton(RoleManager);
        btnAddRole->setObjectName("btnAddRole");

        horizontalLayout_2->addWidget(btnAddRole);

        btnEditRole = new QPushButton(RoleManager);
        btnEditRole->setObjectName("btnEditRole");

        horizontalLayout_2->addWidget(btnEditRole);

        btnDeleteRole = new QPushButton(RoleManager);
        btnDeleteRole->setObjectName("btnDeleteRole");

        horizontalLayout_2->addWidget(btnDeleteRole);

        btnRefresh = new QPushButton(RoleManager);
        btnRefresh->setObjectName("btnRefresh");

        horizontalLayout_2->addWidget(btnRefresh);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        tableView = new QTableView(RoleManager);
        tableView->setObjectName("tableView");
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);

        verticalLayout->addWidget(tableView);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(RoleManager);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        treePermissions = new QTreeWidget(RoleManager);
        treePermissions->setObjectName("treePermissions");

        verticalLayout_2->addWidget(treePermissions);

        btnSavePermissions = new QPushButton(RoleManager);
        btnSavePermissions->setObjectName("btnSavePermissions");

        verticalLayout_2->addWidget(btnSavePermissions);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(RoleManager);

        QMetaObject::connectSlotsByName(RoleManager);
    } // setupUi

    void retranslateUi(QWidget *RoleManager)
    {
        btnAddRole->setText(QCoreApplication::translate("RoleManager", "\346\267\273\345\212\240\350\247\222\350\211\262", nullptr));
        btnEditRole->setText(QCoreApplication::translate("RoleManager", "\347\274\226\350\276\221\350\247\222\350\211\262", nullptr));
        btnDeleteRole->setText(QCoreApplication::translate("RoleManager", "\345\210\240\351\231\244\350\247\222\350\211\262", nullptr));
        btnRefresh->setText(QCoreApplication::translate("RoleManager", "\345\210\267\346\226\260", nullptr));
        label->setText(QCoreApplication::translate("RoleManager", "\346\235\203\351\231\220\350\256\276\347\275\256\357\274\232", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treePermissions->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("RoleManager", "\346\235\203\351\231\220\351\241\271", nullptr));
        btnSavePermissions->setText(QCoreApplication::translate("RoleManager", "\344\277\235\345\255\230\346\235\203\351\231\220\350\256\276\347\275\256", nullptr));
        (void)RoleManager;
    } // retranslateUi

};

namespace Ui {
    class RoleManager: public Ui_RoleManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROLEMANAGER_H
