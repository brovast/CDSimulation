#include "underwater_analysis_module.h"
#include "ui_underwater_analysis_module.h"
#include <QMessageBox>

UnderwaterAnalysisModule::UnderwaterAnalysisModule(QWidget* parent)
    : AnalysisModuleBase(parent)
    , ui(new Ui::UnderwaterAnalysisModule)
{
    ui->setupUi(this);
}

UnderwaterAnalysisModule::~UnderwaterAnalysisModule()
{
    delete ui;
}

void UnderwaterAnalysisModule::initUI()
{
    // 基类UI初始化
    AnalysisModuleBase::initUI();
}

void UnderwaterAnalysisModule::initParamsTable()
{
    // TODO: 实现参数表初始化
}

void UnderwaterAnalysisModule::startAnalysis()
{
    QMessageBox::information(this, "提示", "开始执行水下仿真分析...");
}

void UnderwaterAnalysisModule::stopAnalysis()
{
    QMessageBox::information(this, "提示", "分析已停止");
}

void UnderwaterAnalysisModule::clearOutput()
{
    AnalysisModuleBase::clearOutput();
} 