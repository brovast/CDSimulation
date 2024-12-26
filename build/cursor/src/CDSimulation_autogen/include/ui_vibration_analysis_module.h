/********************************************************************************
** Form generated from reading UI file 'vibration_analysis_module.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIBRATION_ANALYSIS_MODULE_H
#define UI_VIBRATION_ANALYSIS_MODULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VibrationAnalysisModule
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *VibrationAnalysisModule)
    {
        if (VibrationAnalysisModule->objectName().isEmpty())
            VibrationAnalysisModule->setObjectName("VibrationAnalysisModule");
        VibrationAnalysisModule->resize(800, 600);
        verticalLayout = new QVBoxLayout(VibrationAnalysisModule);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(VibrationAnalysisModule);
        label->setObjectName("label");

        verticalLayout->addWidget(label);


        retranslateUi(VibrationAnalysisModule);

        QMetaObject::connectSlotsByName(VibrationAnalysisModule);
    } // setupUi

    void retranslateUi(QWidget *VibrationAnalysisModule)
    {
        VibrationAnalysisModule->setWindowTitle(QCoreApplication::translate("VibrationAnalysisModule", "\346\214\257\345\212\250\345\210\206\346\236\220", nullptr));
        label->setText(QCoreApplication::translate("VibrationAnalysisModule", "\346\214\257\345\212\250\345\210\206\346\236\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VibrationAnalysisModule: public Ui_VibrationAnalysisModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIBRATION_ANALYSIS_MODULE_H
