/********************************************************************************
** Form generated from reading UI file 'approvalmanager.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPROVALMANAGER_H
#define UI_APPROVALMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ApprovalManager
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBoxStatus;
    QPushButton *btnRefresh;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnApprove;
    QPushButton *btnReject;

    void setupUi(QWidget *ApprovalManager)
    {
        if (ApprovalManager->objectName().isEmpty())
            ApprovalManager->setObjectName("ApprovalManager");
        verticalLayout = new QVBoxLayout(ApprovalManager);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(ApprovalManager);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        comboBoxStatus = new QComboBox(ApprovalManager);
        comboBoxStatus->addItem(QString());
        comboBoxStatus->addItem(QString());
        comboBoxStatus->addItem(QString());
        comboBoxStatus->addItem(QString());
        comboBoxStatus->setObjectName("comboBoxStatus");

        horizontalLayout->addWidget(comboBoxStatus);

        btnRefresh = new QPushButton(ApprovalManager);
        btnRefresh->setObjectName("btnRefresh");

        horizontalLayout->addWidget(btnRefresh);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(ApprovalManager);
        tableView->setObjectName("tableView");
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);

        verticalLayout->addWidget(tableView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btnApprove = new QPushButton(ApprovalManager);
        btnApprove->setObjectName("btnApprove");

        horizontalLayout_2->addWidget(btnApprove);

        btnReject = new QPushButton(ApprovalManager);
        btnReject->setObjectName("btnReject");

        horizontalLayout_2->addWidget(btnReject);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ApprovalManager);

        QMetaObject::connectSlotsByName(ApprovalManager);
    } // setupUi

    void retranslateUi(QWidget *ApprovalManager)
    {
        label->setText(QCoreApplication::translate("ApprovalManager", "\347\212\266\346\200\201\357\274\232", nullptr));
        comboBoxStatus->setItemText(0, QCoreApplication::translate("ApprovalManager", "\345\205\250\351\203\250", nullptr));
        comboBoxStatus->setItemText(1, QCoreApplication::translate("ApprovalManager", "\345\276\205\345\256\241\346\211\271", nullptr));
        comboBoxStatus->setItemText(2, QCoreApplication::translate("ApprovalManager", "\345\267\262\345\256\241\346\211\271", nullptr));
        comboBoxStatus->setItemText(3, QCoreApplication::translate("ApprovalManager", "\345\267\262\346\213\222\347\273\235", nullptr));

        btnRefresh->setText(QCoreApplication::translate("ApprovalManager", "\345\210\267\346\226\260", nullptr));
        btnApprove->setText(QCoreApplication::translate("ApprovalManager", "\351\200\232\350\277\207", nullptr));
        btnReject->setText(QCoreApplication::translate("ApprovalManager", "\346\213\222\347\273\235", nullptr));
        (void)ApprovalManager;
    } // retranslateUi

};

namespace Ui {
    class ApprovalManager: public Ui_ApprovalManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPROVALMANAGER_H
