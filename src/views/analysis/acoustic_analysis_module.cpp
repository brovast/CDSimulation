#include "acoustic_analysis_module.h"
#include "ui_acoustic_analysis_module.h"

AcousticAnalysisModule::AcousticAnalysisModule(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::AcousticAnalysisModule)
{
    ui->setupUi(this);
}

AcousticAnalysisModule::~AcousticAnalysisModule()
{
    delete ui;
} 