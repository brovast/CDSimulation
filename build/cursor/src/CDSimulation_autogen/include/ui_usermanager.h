/********************************************************************************
** Form generated from reading UI file 'usermanager.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMANAGER_H
#define UI_USERMANAGER_H

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

class Ui_UserManager
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
    QPushButton *btnEdit;
    QPushButton *btnDelete;
    QPushButton *btnApprove;
    QPushButton *btnReject;

    void setupUi(QWidget *UserManager)
    {
        if (UserManager->objectName().isEmpty())
            UserManager->setObjectName("UserManager");
        verticalLayout = new QVBoxLayout(UserManager);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(UserManager);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        comboBoxStatus = new QComboBox(UserManager);
        comboBoxStatus->addItem(QString());
        comboBoxStatus->addItem(QString());
        comboBoxStatus->addItem(QString());
        comboBoxStatus->addItem(QString());
        comboBoxStatus->setObjectName("comboBoxStatus");

        horizontalLayout->addWidget(comboBoxStatus);

        btnRefresh = new QPushButton(UserManager);
        btnRefresh->setObjectName("btnRefresh");

        horizontalLayout->addWidget(btnRefresh);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(UserManager);
        tableView->setObjectName("tableView");
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);

        verticalLayout->addWidget(tableView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnEdit = new QPushButton(UserManager);
        btnEdit->setObjectName("btnEdit");

        horizontalLayout_2->addWidget(btnEdit);

        btnDelete = new QPushButton(UserManager);
        btnDelete->setObjectName("btnDelete");

        horizontalLayout_2->addWidget(btnDelete);

        btnApprove = new QPushButton(UserManager);
        btnApprove->setObjectName("btnApprove");

        horizontalLayout_2->addWidget(btnApprove);

        btnReject = new QPushButton(UserManager);
        btnReject->setObjectName("btnReject");

        horizontalLayout_2->addWidget(btnReject);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(UserManager);

        QMetaObject::connectSlotsByName(UserManager);
    } // setupUi

    void retranslateUi(QWidget *UserManager)
    {
        label->setText(QCoreApplication::translate("UserManager", "\347\212\266\346\200\201\357\274\232", nullptr));
        comboBoxStatus->setItemText(0, QCoreApplication::translate("UserManager", "\345\205\250\351\203\250", nullptr));
        comboBoxStatus->setItemText(1, QCoreApplication::translate("UserManager", "\345\276\205\345\256\241\346\211\271", nullptr));
        comboBoxStatus->setItemText(2, QCoreApplication::translate("UserManager", "\345\267\262\345\256\241\346\211\271", nullptr));
        comboBoxStatus->setItemText(3, QCoreApplication::translate("UserManager", "\345\267\262\346\213\222\347\273\235", nullptr));

        btnRefresh->setText(QCoreApplication::translate("UserManager", "\345\210\267\346\226\260", nullptr));
        btnEdit->setText(QCoreApplication::translate("UserManager", "\347\274\226\350\276\221", nullptr));
        btnDelete->setText(QCoreApplication::translate("UserManager", "\345\210\240\351\231\244", nullptr));
        btnApprove->setText(QCoreApplication::translate("UserManager", "\345\256\241\346\211\271\351\200\232\350\277\207", nullptr));
        btnReject->setText(QCoreApplication::translate("UserManager", "\346\213\222\347\273\235", nullptr));
        (void)UserManager;
    } // retranslateUi

};

namespace Ui {
    class UserManager: public Ui_UserManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGER_H
