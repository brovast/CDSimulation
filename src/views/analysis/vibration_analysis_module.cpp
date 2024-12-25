#include "vibration_analysis_module.h"
#include "ui_vibration_analysis_module.h"
#include <QMessageBox>

VibrationAnalysisModule::VibrationAnalysisModule(QWidget* parent)
    : AnalysisModuleBase(parent)
    , ui(new Ui::VibrationAnalysisModule)
{
    ui->setupUi(this);
}

VibrationAnalysisModule::~VibrationAnalysisModule()
{
    delete ui;
}

void VibrationAnalysisModule::initUI()
{
    // 基类UI初始化
    AnalysisModuleBase::initUI();
}

void VibrationAnalysisModule::initParamsTable()
{
    // TODO: 实现参数表初始化
}

void VibrationAnalysisModule::startAnalysis()
{
    QMessageBox::information(this, "提示", "开始执行振动分析...");
}

void VibrationAnalysisModule::stopAnalysis()
{
    QMessageBox::information(this, "提示", "分析已停止");
}

void VibrationAnalysisModule::clearOutput()
{
    AnalysisModuleBase::clearOutput();
} 