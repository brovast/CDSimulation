/********************************************************************************
** Form generated from reading UI file 'acoustic_analysis_module.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACOUSTIC_ANALYSIS_MODULE_H
#define UI_ACOUSTIC_ANALYSIS_MODULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AcousticAnalysisModule
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *AcousticAnalysisModule)
    {
        if (AcousticAnalysisModule->objectName().isEmpty())
            AcousticAnalysisModule->setObjectName("AcousticAnalysisModule");
        AcousticAnalysisModule->resize(800, 600);
        verticalLayout = new QVBoxLayout(AcousticAnalysisModule);
        verticalLayout->setObjectName("verticalLayout");

        retranslateUi(AcousticAnalysisModule);

        QMetaObject::connectSlotsByName(AcousticAnalysisModule);
    } // setupUi

    void retranslateUi(QWidget *AcousticAnalysisModule)
    {
        AcousticAnalysisModule->setWindowTitle(QCoreApplication::translate("AcousticAnalysisModule", "\345\243\260\345\255\246\345\210\206\346\236\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AcousticAnalysisModule: public Ui_AcousticAnalysisModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACOUSTIC_ANALYSIS_MODULE_H
