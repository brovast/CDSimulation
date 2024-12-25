/********************************************************************************
** Form generated from reading UI file 'underwater_analysis_module.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNDERWATER_ANALYSIS_MODULE_H
#define UI_UNDERWATER_ANALYSIS_MODULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UnderwaterAnalysisModule
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *UnderwaterAnalysisModule)
    {
        if (UnderwaterAnalysisModule->objectName().isEmpty())
            UnderwaterAnalysisModule->setObjectName("UnderwaterAnalysisModule");
        UnderwaterAnalysisModule->resize(800, 600);
        verticalLayout = new QVBoxLayout(UnderwaterAnalysisModule);
        verticalLayout->setObjectName("verticalLayout");

        retranslateUi(UnderwaterAnalysisModule);

        QMetaObject::connectSlotsByName(UnderwaterAnalysisModule);
    } // setupUi

    void retranslateUi(QWidget *UnderwaterAnalysisModule)
    {
        UnderwaterAnalysisModule->setWindowTitle(QCoreApplication::translate("UnderwaterAnalysisModule", "\346\260\264\344\270\213\344\273\277\347\234\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UnderwaterAnalysisModule: public Ui_UnderwaterAnalysisModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNDERWATER_ANALYSIS_MODULE_H
