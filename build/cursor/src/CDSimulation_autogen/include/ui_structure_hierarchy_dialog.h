/********************************************************************************
** Form generated from reading UI file 'structure_hierarchy_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STRUCTURE_HIERARCHY_DIALOG_H
#define UI_STRUCTURE_HIERARCHY_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StructureHierarchyDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTreeView *treeView;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAddFolder;
    QPushButton *btnDeleteFolder;
    QPushButton *btnClose;

    void setupUi(QDialog *StructureHierarchyDialog)
    {
        if (StructureHierarchyDialog->objectName().isEmpty())
            StructureHierarchyDialog->setObjectName("StructureHierarchyDialog");
        StructureHierarchyDialog->resize(400, 500);
        verticalLayout = new QVBoxLayout(StructureHierarchyDialog);
        verticalLayout->setObjectName("verticalLayout");
        treeView = new QTreeView(StructureHierarchyDialog);
        treeView->setObjectName("treeView");

        verticalLayout->addWidget(treeView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnAddFolder = new QPushButton(StructureHierarchyDialog);
        btnAddFolder->setObjectName("btnAddFolder");

        horizontalLayout->addWidget(btnAddFolder);

        btnDeleteFolder = new QPushButton(StructureHierarchyDialog);
        btnDeleteFolder->setObjectName("btnDeleteFolder");

        horizontalLayout->addWidget(btnDeleteFolder);

        btnClose = new QPushButton(StructureHierarchyDialog);
        btnClose->setObjectName("btnClose");

        horizontalLayout->addWidget(btnClose);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(StructureHierarchyDialog);
        QObject::connect(btnClose, &QPushButton::clicked, StructureHierarchyDialog, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(StructureHierarchyDialog);
    } // setupUi

    void retranslateUi(QDialog *StructureHierarchyDialog)
    {
        StructureHierarchyDialog->setWindowTitle(QCoreApplication::translate("StructureHierarchyDialog", "\347\273\223\346\236\204\345\261\202\347\272\247\347\273\264\346\212\244", nullptr));
        btnAddFolder->setText(QCoreApplication::translate("StructureHierarchyDialog", "\346\226\260\345\273\272\346\226\207\344\273\266\345\244\271", nullptr));
        btnDeleteFolder->setText(QCoreApplication::translate("StructureHierarchyDialog", "\345\210\240\351\231\244\346\226\207\344\273\266\345\244\271", nullptr));
        btnClose->setText(QCoreApplication::translate("StructureHierarchyDialog", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StructureHierarchyDialog: public Ui_StructureHierarchyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRUCTURE_HIERARCHY_DIALOG_H
