/********************************************************************************
** Form generated from reading UI file 'static_analysis_module.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATIC_ANALYSIS_MODULE_H
#define UI_STATIC_ANALYSIS_MODULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StaticAnalysisModule
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *StaticAnalysisModule)
    {
        if (StaticAnalysisModule->objectName().isEmpty())
            StaticAnalysisModule->setObjectName("StaticAnalysisModule");
        StaticAnalysisModule->resize(800, 600);
        verticalLayout = new QVBoxLayout(StaticAnalysisModule);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(StaticAnalysisModule);
        label->setObjectName("label");

        verticalLayout->addWidget(label);


        retranslateUi(StaticAnalysisModule);

        QMetaObject::connectSlotsByName(StaticAnalysisModule);
    } // setupUi

    void retranslateUi(QWidget *StaticAnalysisModule)
    {
        StaticAnalysisModule->setWindowTitle(QCoreApplication::translate("StaticAnalysisModule", "\351\235\231\345\212\233\345\255\246\345\210\206\346\236\220", nullptr));
        label->setText(QCoreApplication::translate("StaticAnalysisModule", "\351\235\231\345\212\233\345\255\246\345\210\206\346\236\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StaticAnalysisModule: public Ui_StaticAnalysisModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATIC_ANALYSIS_MODULE_H
