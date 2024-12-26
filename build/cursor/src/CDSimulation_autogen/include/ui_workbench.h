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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Workbench
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidgetMain;
    QWidget *tabTaskReceive;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *labelStatus;
    QComboBox *comboBoxStatus;
    QLineEdit *lineEditSearch;
    QSpacerItem *horizontalSpacer;
    QSplitter *splitter;
    QTableWidget *tableTaskList;
    QWidget *widgetTaskDetails;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBoxBasicInfo;
    QFormLayout *formLayout;
    QLabel *labelTaskName;
    QLabel *labelTaskNameValue;
    QLabel *labelCreateTime;
    QLabel *labelCreateTimeValue;
    QLabel *labelDescription;
    QTextBrowser *textBrowserDescription;
    QLabel *labelAttachment;
    QHBoxLayout *horizontalLayout_attachment;
    QLineEdit *lineEditAttachmentPath;
    QPushButton *btnViewAttachment;
    QGroupBox *groupBoxAnalysisTypes;
    QVBoxLayout *verticalLayout_4;
    QListWidget *listWidgetAnalysisTypes;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnAcceptTask;
    QPushButton *btnCompleteTask;
    QWidget *tabTaskExecution;
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
        tabWidgetMain = new QTabWidget(centralwidget);
        tabWidgetMain->setObjectName("tabWidgetMain");
        tabTaskReceive = new QWidget();
        tabTaskReceive->setObjectName("tabTaskReceive");
        verticalLayout_2 = new QVBoxLayout(tabTaskReceive);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        labelStatus = new QLabel(tabTaskReceive);
        labelStatus->setObjectName("labelStatus");

        horizontalLayout->addWidget(labelStatus);

        comboBoxStatus = new QComboBox(tabTaskReceive);
        comboBoxStatus->addItem(QString());
        comboBoxStatus->addItem(QString());
        comboBoxStatus->addItem(QString());
        comboBoxStatus->addItem(QString());
        comboBoxStatus->setObjectName("comboBoxStatus");

        horizontalLayout->addWidget(comboBoxStatus);

        lineEditSearch = new QLineEdit(tabTaskReceive);
        lineEditSearch->setObjectName("lineEditSearch");

        horizontalLayout->addWidget(lineEditSearch);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        splitter = new QSplitter(tabTaskReceive);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Orientation::Vertical);
        tableTaskList = new QTableWidget(splitter);
        if (tableTaskList->columnCount() < 5)
            tableTaskList->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableTaskList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableTaskList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableTaskList->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableTaskList->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableTaskList->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableTaskList->setObjectName("tableTaskList");
        tableTaskList->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tableTaskList->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        splitter->addWidget(tableTaskList);
        widgetTaskDetails = new QWidget(splitter);
        widgetTaskDetails->setObjectName("widgetTaskDetails");
        verticalLayout_3 = new QVBoxLayout(widgetTaskDetails);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBoxBasicInfo = new QGroupBox(widgetTaskDetails);
        groupBoxBasicInfo->setObjectName("groupBoxBasicInfo");
        formLayout = new QFormLayout(groupBoxBasicInfo);
        formLayout->setObjectName("formLayout");
        labelTaskName = new QLabel(groupBoxBasicInfo);
        labelTaskName->setObjectName("labelTaskName");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelTaskName);

        labelTaskNameValue = new QLabel(groupBoxBasicInfo);
        labelTaskNameValue->setObjectName("labelTaskNameValue");

        formLayout->setWidget(0, QFormLayout::FieldRole, labelTaskNameValue);

        labelCreateTime = new QLabel(groupBoxBasicInfo);
        labelCreateTime->setObjectName("labelCreateTime");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelCreateTime);

        labelCreateTimeValue = new QLabel(groupBoxBasicInfo);
        labelCreateTimeValue->setObjectName("labelCreateTimeValue");

        formLayout->setWidget(1, QFormLayout::FieldRole, labelCreateTimeValue);

        labelDescription = new QLabel(groupBoxBasicInfo);
        labelDescription->setObjectName("labelDescription");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelDescription);

        textBrowserDescription = new QTextBrowser(groupBoxBasicInfo);
        textBrowserDescription->setObjectName("textBrowserDescription");

        formLayout->setWidget(2, QFormLayout::FieldRole, textBrowserDescription);

        labelAttachment = new QLabel(groupBoxBasicInfo);
        labelAttachment->setObjectName("labelAttachment");

        formLayout->setWidget(3, QFormLayout::LabelRole, labelAttachment);

        horizontalLayout_attachment = new QHBoxLayout();
        horizontalLayout_attachment->setObjectName("horizontalLayout_attachment");
        lineEditAttachmentPath = new QLineEdit(groupBoxBasicInfo);
        lineEditAttachmentPath->setObjectName("lineEditAttachmentPath");
        lineEditAttachmentPath->setReadOnly(true);

        horizontalLayout_attachment->addWidget(lineEditAttachmentPath);

        btnViewAttachment = new QPushButton(groupBoxBasicInfo);
        btnViewAttachment->setObjectName("btnViewAttachment");

        horizontalLayout_attachment->addWidget(btnViewAttachment);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_attachment);


        verticalLayout_3->addWidget(groupBoxBasicInfo);

        groupBoxAnalysisTypes = new QGroupBox(widgetTaskDetails);
        groupBoxAnalysisTypes->setObjectName("groupBoxAnalysisTypes");
        verticalLayout_4 = new QVBoxLayout(groupBoxAnalysisTypes);
        verticalLayout_4->setObjectName("verticalLayout_4");
        listWidgetAnalysisTypes = new QListWidget(groupBoxAnalysisTypes);
        listWidgetAnalysisTypes->setObjectName("listWidgetAnalysisTypes");

        verticalLayout_4->addWidget(listWidgetAnalysisTypes);


        verticalLayout_3->addWidget(groupBoxAnalysisTypes);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btnAcceptTask = new QPushButton(widgetTaskDetails);
        btnAcceptTask->setObjectName("btnAcceptTask");

        horizontalLayout_2->addWidget(btnAcceptTask);

        btnCompleteTask = new QPushButton(widgetTaskDetails);
        btnCompleteTask->setObjectName("btnCompleteTask");

        horizontalLayout_2->addWidget(btnCompleteTask);


        verticalLayout_3->addLayout(horizontalLayout_2);

        splitter->addWidget(widgetTaskDetails);

        verticalLayout_2->addWidget(splitter);

        tabWidgetMain->addTab(tabTaskReceive, QString());
        tabTaskExecution = new QWidget();
        tabTaskExecution->setObjectName("tabTaskExecution");
        tabWidgetMain->addTab(tabTaskExecution, QString());

        verticalLayout->addWidget(tabWidgetMain);

        Workbench->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Workbench);
        statusbar->setObjectName("statusbar");
        Workbench->setStatusBar(statusbar);

        retranslateUi(Workbench);

        tabWidgetMain->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Workbench);
    } // setupUi

    void retranslateUi(QMainWindow *Workbench)
    {
        Workbench->setWindowTitle(QCoreApplication::translate("Workbench", "\345\267\245\344\275\234\345\217\260", nullptr));
        labelStatus->setText(QCoreApplication::translate("Workbench", "\347\212\266\346\200\201\357\274\232", nullptr));
        comboBoxStatus->setItemText(0, QCoreApplication::translate("Workbench", "\345\205\250\351\203\250", nullptr));
        comboBoxStatus->setItemText(1, QCoreApplication::translate("Workbench", "\345\276\205\346\216\245\346\224\266", nullptr));
        comboBoxStatus->setItemText(2, QCoreApplication::translate("Workbench", "\350\277\233\350\241\214\344\270\255", nullptr));
        comboBoxStatus->setItemText(3, QCoreApplication::translate("Workbench", "\345\267\262\345\256\214\346\210\220", nullptr));

        lineEditSearch->setPlaceholderText(QCoreApplication::translate("Workbench", "\346\220\234\347\264\242\344\273\273\345\212\241...", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableTaskList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Workbench", "\344\273\273\345\212\241ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableTaskList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Workbench", "\344\273\273\345\212\241\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableTaskList->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Workbench", "\345\210\233\345\273\272\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableTaskList->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Workbench", "\344\273\273\345\212\241\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableTaskList->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Workbench", "\344\273\273\345\212\241\347\212\266\346\200\201", nullptr));
        groupBoxBasicInfo->setTitle(QCoreApplication::translate("Workbench", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        labelTaskName->setText(QCoreApplication::translate("Workbench", "\344\273\273\345\212\241\345\220\215\347\247\260\357\274\232", nullptr));
        labelTaskNameValue->setText(QString());
        labelCreateTime->setText(QCoreApplication::translate("Workbench", "\345\210\233\345\273\272\346\227\266\351\227\264\357\274\232", nullptr));
        labelCreateTimeValue->setText(QString());
        labelDescription->setText(QCoreApplication::translate("Workbench", "\344\273\273\345\212\241\346\217\217\350\277\260\357\274\232", nullptr));
        labelAttachment->setText(QCoreApplication::translate("Workbench", "\351\231\204\344\273\266\357\274\232", nullptr));
        btnViewAttachment->setText(QCoreApplication::translate("Workbench", "\346\237\245\347\234\213\351\231\204\344\273\266", nullptr));
        groupBoxAnalysisTypes->setTitle(QCoreApplication::translate("Workbench", "\345\210\206\346\236\220\347\261\273\345\236\213", nullptr));
        btnAcceptTask->setText(QCoreApplication::translate("Workbench", "\346\216\245\346\224\266\344\273\273\345\212\241", nullptr));
        btnCompleteTask->setText(QCoreApplication::translate("Workbench", "\345\256\214\346\210\220\344\273\273\345\212\241", nullptr));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tabTaskReceive), QCoreApplication::translate("Workbench", "\344\273\273\345\212\241\346\216\245\346\224\266", nullptr));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tabTaskExecution), QCoreApplication::translate("Workbench", "\344\273\273\345\212\241\346\211\247\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Workbench: public Ui_Workbench {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKBENCH_H
