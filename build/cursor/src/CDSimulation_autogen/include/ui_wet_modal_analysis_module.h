/********************************************************************************
** Form generated from reading UI file 'wet_modal_analysis_module.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WET_MODAL_ANALYSIS_MODULE_H
#define UI_WET_MODAL_ANALYSIS_MODULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WetModalAnalysisModule
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *WetModalAnalysisModule)
    {
        if (WetModalAnalysisModule->objectName().isEmpty())
            WetModalAnalysisModule->setObjectName("WetModalAnalysisModule");
        WetModalAnalysisModule->resize(800, 600);
        verticalLayout = new QVBoxLayout(WetModalAnalysisModule);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(WetModalAnalysisModule);
        label->setObjectName("label");

        verticalLayout->addWidget(label);


        retranslateUi(WetModalAnalysisModule);

        QMetaObject::connectSlotsByName(WetModalAnalysisModule);
    } // setupUi

    void retranslateUi(QWidget *WetModalAnalysisModule)
    {
        WetModalAnalysisModule->setWindowTitle(QCoreApplication::translate("WetModalAnalysisModule", "\346\271\277\346\250\241\346\200\201\345\210\206\346\236\220", nullptr));
        label->setText(QCoreApplication::translate("WetModalAnalysisModule", "\346\271\277\346\250\241\346\200\201\345\210\206\346\236\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WetModalAnalysisModule: public Ui_WetModalAnalysisModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WET_MODAL_ANALYSIS_MODULE_H
