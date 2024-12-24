/********************************************************************************
** Form generated from reading UI file 'workbench.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKBENCH_H
#define UI_WORKBENCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Workbench
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBoxStatus;
    QPushButton *btnRefresh;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableTask;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Workbench)
    {
        if (Workbench->objectName().isEmpty())
            Workbench->setObjectName("Workbench");
        Workbench->resize(1200, 800);
        centralwidget = new QWidget(Workbench);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        comboBoxStatus = new QComboBox(centralwidget);
        comboBoxStatus->addItem(QString());
        comboBoxStatus->addItem(QString());
        comboBoxStatus->addItem(QString());
        comboBoxStatus->addItem(QString());
        comboBoxStatus->setObjectName("comboBoxStatus");

        horizontalLayout->addWidget(comboBoxStatus);

        btnRefresh = new QPushButton(centralwidget);
        btnRefresh->setObjectName("btnRefresh");

        horizontalLayout->addWidget(btnRefresh);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableTask = new QTableWidget(centralwidget);
        if (tableTask->columnCount() < 5)
            tableTask->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableTask->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableTask->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableTask->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableTask->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableTask->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableTask->setObjectName("tableTask");
        tableTask->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(tableTask);

        Workbench->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Workbench);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 22));
        Workbench->setMenuBar(menubar);
        statusbar = new QStatusBar(Workbench);
        statusbar->setObjectName("statusbar");
        Workbench->setStatusBar(statusbar);

        retranslateUi(Workbench);

        QMetaObject::connectSlotsByName(Workbench);
    } // setupUi

    void retranslateUi(QMainWindow *Workbench)
    {
        Workbench->setWindowTitle(QCoreApplication::translate("Workbench", "\345\267\245\344\275\234\345\217\260", nullptr));
        label->setText(QCoreApplication::translate("Workbench", "\344\273\273\345\212\241\347\212\266\346\200\201\357\274\232", nullptr));
        comboBoxStatus->setItemText(0, QCoreApplication::translate("Workbench", "\345\205\250\351\203\250", nullptr));
        comboBoxStatus->setItemText(1, QCoreApplication::translate("Workbench", "\345\276\205\345\244\204\347\220\206", nullptr));
        comboBoxStatus->setItemText(2, QCoreApplication::translate("Workbench", "\350\277\233\350\241\214\344\270\255", nullptr));
        comboBoxStatus->setItemText(3, QCoreApplication::translate("Workbench", "\345\267\262\345\256\214\346\210\220", nullptr));

        btnRefresh->setText(QCoreApplication::translate("Workbench", "\345\210\267\346\226\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableTask->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Workbench", "\344\273\273\345\212\241ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableTask->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Workbench", "\344\273\273\345\212\241\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableTask->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Workbench", "\344\273\273\345\212\241\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableTask->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Workbench", "\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableTask->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Workbench", "\345\210\233\345\273\272\346\227\266\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Workbench: public Ui_Workbench {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKBENCH_H
