/********************************************************************************
** Form generated from reading UI file 'dry_modal_analysis_module.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRY_MODAL_ANALYSIS_MODULE_H
#define UI_DRY_MODAL_ANALYSIS_MODULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DryModalAnalysisModule
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *DryModalAnalysisModule)
    {
        if (DryModalAnalysisModule->objectName().isEmpty())
            DryModalAnalysisModule->setObjectName("DryModalAnalysisModule");
        DryModalAnalysisModule->resize(800, 600);
        verticalLayout = new QVBoxLayout(DryModalAnalysisModule);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(DryModalAnalysisModule);
        label->setObjectName("label");

        verticalLayout->addWidget(label);


        retranslateUi(DryModalAnalysisModule);

        QMetaObject::connectSlotsByName(DryModalAnalysisModule);
    } // setupUi

    void retranslateUi(QWidget *DryModalAnalysisModule)
    {
        DryModalAnalysisModule->setWindowTitle(QCoreApplication::translate("DryModalAnalysisModule", "\345\271\262\346\250\241\346\200\201\345\210\206\346\236\220", nullptr));
        label->setText(QCoreApplication::translate("DryModalAnalysisModule", "\345\271\262\346\250\241\346\200\201\345\210\206\346\236\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DryModalAnalysisModule: public Ui_DryModalAnalysisModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRY_MODAL_ANALYSIS_MODULE_H
