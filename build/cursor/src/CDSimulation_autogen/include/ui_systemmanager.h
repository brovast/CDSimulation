/********************************************************************************
** Form generated from reading UI file 'systemmanager.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMMANAGER_H
#define UI_SYSTEMMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "views/system/approvalmanager.h"
#include "views/system/rolemanager.h"
#include "views/system/usermanager.h"

QT_BEGIN_NAMESPACE

class Ui_SystemManager
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidgetMain;
    QWidget *tabDataManage;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidgetDataManage;
    QWidget *tabBasicData;
    QHBoxLayout *horizontalLayout;
    QTreeView *treeViewBasicData;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelImagePreview;
    QTextEdit *textEditContentPreview;
    QWidget *tabCompartmentData;
    QHBoxLayout *horizontalLayout_2;
    QTreeView *treeViewCDBasicData;
    QVBoxLayout *verticalLayout_4;
    QTreeView *treeViewCDData;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnNewModel;
    QPushButton *btnAddStructureType;
    QPushButton *btnCopyData;
    QPushButton *btnDelete;
    QWidget *tabTaskManage;
    QWidget *tabSystemManage;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tabWidgetSystemManage;
    QWidget *tabUserManage;
    QVBoxLayout *verticalLayout_6;
    UserManager *widgetUserManager;
    QWidget *tabRoleManage;
    QVBoxLayout *verticalLayout_7;
    RoleManager *widgetRoleManager;
    QWidget *tabApprovalManage;
    QVBoxLayout *verticalLayout_8;
    ApprovalManager *widgetApprovalManager;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SystemManager)
    {
        if (SystemManager->objectName().isEmpty())
            SystemManager->setObjectName("SystemManager");
        SystemManager->resize(1200, 800);
        centralwidget = new QWidget(SystemManager);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidgetMain = new QTabWidget(centralwidget);
        tabWidgetMain->setObjectName("tabWidgetMain");
        tabDataManage = new QWidget();
        tabDataManage->setObjectName("tabDataManage");
        verticalLayout_2 = new QVBoxLayout(tabDataManage);
        verticalLayout_2->setObjectName("verticalLayout_2");
        tabWidgetDataManage = new QTabWidget(tabDataManage);
        tabWidgetDataManage->setObjectName("tabWidgetDataManage");
        tabBasicData = new QWidget();
        tabBasicData->setObjectName("tabBasicData");
        horizontalLayout = new QHBoxLayout(tabBasicData);
        horizontalLayout->setObjectName("horizontalLayout");
        treeViewBasicData = new QTreeView(tabBasicData);
        treeViewBasicData->setObjectName("treeViewBasicData");

        horizontalLayout->addWidget(treeViewBasicData);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        labelImagePreview = new QLabel(tabBasicData);
        labelImagePreview->setObjectName("labelImagePreview");
        labelImagePreview->setMinimumSize(QSize(400, 300));
        labelImagePreview->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labelImagePreview);

        textEditContentPreview = new QTextEdit(tabBasicData);
        textEditContentPreview->setObjectName("textEditContentPreview");
        textEditContentPreview->setMinimumSize(QSize(400, 200));
        textEditContentPreview->setReadOnly(true);

        verticalLayout_3->addWidget(textEditContentPreview);


        horizontalLayout->addLayout(verticalLayout_3);

        tabWidgetDataManage->addTab(tabBasicData, QString());
        tabCompartmentData = new QWidget();
        tabCompartmentData->setObjectName("tabCompartmentData");
        horizontalLayout_2 = new QHBoxLayout(tabCompartmentData);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        treeViewCDBasicData = new QTreeView(tabCompartmentData);
        treeViewCDBasicData->setObjectName("treeViewCDBasicData");

        horizontalLayout_2->addWidget(treeViewCDBasicData);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        treeViewCDData = new QTreeView(tabCompartmentData);
        treeViewCDData->setObjectName("treeViewCDData");

        verticalLayout_4->addWidget(treeViewCDData);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        btnNewModel = new QPushButton(tabCompartmentData);
        btnNewModel->setObjectName("btnNewModel");

        horizontalLayout_3->addWidget(btnNewModel);

        btnAddStructureType = new QPushButton(tabCompartmentData);
        btnAddStructureType->setObjectName("btnAddStructureType");

        horizontalLayout_3->addWidget(btnAddStructureType);

        btnCopyData = new QPushButton(tabCompartmentData);
        btnCopyData->setObjectName("btnCopyData");

        horizontalLayout_3->addWidget(btnCopyData);

        btnDelete = new QPushButton(tabCompartmentData);
        btnDelete->setObjectName("btnDelete");

        horizontalLayout_3->addWidget(btnDelete);


        verticalLayout_4->addLayout(horizontalLayout_3);


        horizontalLayout_2->addLayout(verticalLayout_4);

        tabWidgetDataManage->addTab(tabCompartmentData, QString());

        verticalLayout_2->addWidget(tabWidgetDataManage);

        tabWidgetMain->addTab(tabDataManage, QString());
        tabTaskManage = new QWidget();
        tabTaskManage->setObjectName("tabTaskManage");
        tabWidgetMain->addTab(tabTaskManage, QString());
        tabSystemManage = new QWidget();
        tabSystemManage->setObjectName("tabSystemManage");
        verticalLayout_5 = new QVBoxLayout(tabSystemManage);
        verticalLayout_5->setObjectName("verticalLayout_5");
        tabWidgetSystemManage = new QTabWidget(tabSystemManage);
        tabWidgetSystemManage->setObjectName("tabWidgetSystemManage");
        tabUserManage = new QWidget();
        tabUserManage->setObjectName("tabUserManage");
        verticalLayout_6 = new QVBoxLayout(tabUserManage);
        verticalLayout_6->setObjectName("verticalLayout_6");
        widgetUserManager = new UserManager(tabUserManage);
        widgetUserManager->setObjectName("widgetUserManager");

        verticalLayout_6->addWidget(widgetUserManager);

        tabWidgetSystemManage->addTab(tabUserManage, QString());
        tabRoleManage = new QWidget();
        tabRoleManage->setObjectName("tabRoleManage");
        verticalLayout_7 = new QVBoxLayout(tabRoleManage);
        verticalLayout_7->setObjectName("verticalLayout_7");
        widgetRoleManager = new RoleManager(tabRoleManage);
        widgetRoleManager->setObjectName("widgetRoleManager");

        verticalLayout_7->addWidget(widgetRoleManager);

        tabWidgetSystemManage->addTab(tabRoleManage, QString());
        tabApprovalManage = new QWidget();
        tabApprovalManage->setObjectName("tabApprovalManage");
        verticalLayout_8 = new QVBoxLayout(tabApprovalManage);
        verticalLayout_8->setObjectName("verticalLayout_8");
        widgetApprovalManager = new ApprovalManager(tabApprovalManage);
        widgetApprovalManager->setObjectName("widgetApprovalManager");

        verticalLayout_8->addWidget(widgetApprovalManager);

        tabWidgetSystemManage->addTab(tabApprovalManage, QString());

        verticalLayout_5->addWidget(tabWidgetSystemManage);

        tabWidgetMain->addTab(tabSystemManage, QString());

        verticalLayout->addWidget(tabWidgetMain);

        SystemManager->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SystemManager);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 22));
        SystemManager->setMenuBar(menubar);
        statusbar = new QStatusBar(SystemManager);
        statusbar->setObjectName("statusbar");
        SystemManager->setStatusBar(statusbar);

        retranslateUi(SystemManager);

        QMetaObject::connectSlotsByName(SystemManager);
    } // setupUi

    void retranslateUi(QMainWindow *SystemManager)
    {
        SystemManager->setWindowTitle(QCoreApplication::translate("SystemManager", "\347\263\273\347\273\237\347\256\241\347\220\206", nullptr));
        labelImagePreview->setText(QCoreApplication::translate("SystemManager", "\345\233\276\347\211\207\351\242\204\350\247\210", nullptr));
        tabWidgetDataManage->setTabText(tabWidgetDataManage->indexOf(tabBasicData), QCoreApplication::translate("SystemManager", "\345\237\272\347\241\200\346\225\260\346\215\256\345\272\223", nullptr));
        btnNewModel->setText(QCoreApplication::translate("SystemManager", "\346\226\260\345\273\272\345\236\213\345\217\267", nullptr));
        btnAddStructureType->setText(QCoreApplication::translate("SystemManager", "\346\267\273\345\212\240\347\273\223\346\236\204\347\261\273\345\236\213", nullptr));
        btnCopyData->setText(QCoreApplication::translate("SystemManager", "\346\225\260\346\215\256\345\244\215\345\210\266", nullptr));
        btnDelete->setText(QCoreApplication::translate("SystemManager", "\345\210\240\351\231\244", nullptr));
        tabWidgetDataManage->setTabText(tabWidgetDataManage->indexOf(tabCompartmentData), QCoreApplication::translate("SystemManager", "\350\210\261\346\256\265\346\225\260\346\215\256\345\272\223", nullptr));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tabDataManage), QCoreApplication::translate("SystemManager", "\346\225\260\346\215\256\347\256\241\347\220\206", nullptr));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tabTaskManage), QCoreApplication::translate("SystemManager", "\344\273\273\345\212\241\347\256\241\347\220\206", nullptr));
        tabWidgetSystemManage->setTabText(tabWidgetSystemManage->indexOf(tabUserManage), QCoreApplication::translate("SystemManager", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        tabWidgetSystemManage->setTabText(tabWidgetSystemManage->indexOf(tabRoleManage), QCoreApplication::translate("SystemManager", "\350\247\222\350\211\262\347\256\241\347\220\206", nullptr));
        tabWidgetSystemManage->setTabText(tabWidgetSystemManage->indexOf(tabApprovalManage), QCoreApplication::translate("SystemManager", "\345\256\241\346\211\271\347\256\241\347\220\206", nullptr));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tabSystemManage), QCoreApplication::translate("SystemManager", "\347\263\273\347\273\237\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemManager: public Ui_SystemManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMMANAGER_H
