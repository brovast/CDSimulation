/********************************************************************************
** Form generated from reading UI file 'modal_analysis_module.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODAL_ANALYSIS_MODULE_H
#define UI_MODAL_ANALYSIS_MODULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModalAnalysisModule
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *ModalAnalysisModule)
    {
        if (ModalAnalysisModule->objectName().isEmpty())
            ModalAnalysisModule->setObjectName("ModalAnalysisModule");
        ModalAnalysisModule->resize(800, 600);
        verticalLayout = new QVBoxLayout(ModalAnalysisModule);
        verticalLayout->setObjectName("verticalLayout");

        retranslateUi(ModalAnalysisModule);

        QMetaObject::connectSlotsByName(ModalAnalysisModule);
    } // setupUi

    void retranslateUi(QWidget *ModalAnalysisModule)
    {
        ModalAnalysisModule->setWindowTitle(QCoreApplication::translate("ModalAnalysisModule", "\346\250\241\346\200\201\345\210\206\346\236\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModalAnalysisModule: public Ui_ModalAnalysisModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODAL_ANALYSIS_MODULE_H
