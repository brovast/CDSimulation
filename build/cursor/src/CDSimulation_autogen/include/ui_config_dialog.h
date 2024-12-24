/********************************************************************************
** Form generated from reading UI file 'config_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_DIALOG_H
#define UI_CONFIG_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConfigDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxSoftware;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableSoftware;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAddSoftware;
    QPushButton *btnDeleteSoftware;
    QPushButton *btnBrowse;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnClose;

    void setupUi(QDialog *ConfigDialog)
    {
        if (ConfigDialog->objectName().isEmpty())
            ConfigDialog->setObjectName("ConfigDialog");
        ConfigDialog->resize(500, 400);
        verticalLayout = new QVBoxLayout(ConfigDialog);
        verticalLayout->setObjectName("verticalLayout");
        groupBoxSoftware = new QGroupBox(ConfigDialog);
        groupBoxSoftware->setObjectName("groupBoxSoftware");
        verticalLayout_2 = new QVBoxLayout(groupBoxSoftware);
        verticalLayout_2->setObjectName("verticalLayout_2");
        tableSoftware = new QTableWidget(groupBoxSoftware);
        if (tableSoftware->columnCount() < 3)
            tableSoftware->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableSoftware->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableSoftware->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableSoftware->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableSoftware->setObjectName("tableSoftware");
        tableSoftware->setColumnCount(3);

        verticalLayout_2->addWidget(tableSoftware);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnAddSoftware = new QPushButton(groupBoxSoftware);
        btnAddSoftware->setObjectName("btnAddSoftware");

        horizontalLayout->addWidget(btnAddSoftware);

        btnDeleteSoftware = new QPushButton(groupBoxSoftware);
        btnDeleteSoftware->setObjectName("btnDeleteSoftware");

        horizontalLayout->addWidget(btnDeleteSoftware);

        btnBrowse = new QPushButton(groupBoxSoftware);
        btnBrowse->setObjectName("btnBrowse");

        horizontalLayout->addWidget(btnBrowse);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addWidget(groupBoxSoftware);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnSave = new QPushButton(ConfigDialog);
        btnSave->setObjectName("btnSave");

        horizontalLayout_2->addWidget(btnSave);

        btnClose = new QPushButton(ConfigDialog);
        btnClose->setObjectName("btnClose");

        horizontalLayout_2->addWidget(btnClose);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ConfigDialog);

        QMetaObject::connectSlotsByName(ConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigDialog)
    {
        ConfigDialog->setWindowTitle(QCoreApplication::translate("ConfigDialog", "\350\275\257\344\273\266\351\205\215\347\275\256", nullptr));
        groupBoxSoftware->setTitle(QCoreApplication::translate("ConfigDialog", "\350\275\257\344\273\266\351\205\215\347\275\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableSoftware->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ConfigDialog", "\350\275\257\344\273\266\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableSoftware->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ConfigDialog", "\350\275\257\344\273\266\350\267\257\345\276\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableSoftware->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ConfigDialog", "\345\221\275\344\273\244\350\241\214\345\217\202\346\225\260", nullptr));
        btnAddSoftware->setText(QCoreApplication::translate("ConfigDialog", "\346\267\273\345\212\240\350\275\257\344\273\266", nullptr));
        btnDeleteSoftware->setText(QCoreApplication::translate("ConfigDialog", "\345\210\240\351\231\244\350\275\257\344\273\266", nullptr));
        btnBrowse->setText(QCoreApplication::translate("ConfigDialog", "\346\265\217\350\247\210...", nullptr));
        btnSave->setText(QCoreApplication::translate("ConfigDialog", "\344\277\235\345\255\230", nullptr));
        btnClose->setText(QCoreApplication::translate("ConfigDialog", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfigDialog: public Ui_ConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_DIALOG_H
