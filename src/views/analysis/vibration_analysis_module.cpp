#include "vibration_analysis_module.h"
#include "ui_vibration_analysis_module.h"

VibrationAnalysisModule::VibrationAnalysisModule(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::VibrationAnalysisModule)
{
    ui->setupUi(this);
}

VibrationAnalysisModule::~VibrationAnalysisModule()
{
    delete ui;
} 