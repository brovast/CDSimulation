#include "acoustic_analysis_module.h"
#include "ui_acoustic_analysis_module.h"
#include <QMessageBox>

AcousticAnalysisModule::AcousticAnalysisModule(QWidget* parent)
    : AnalysisModuleBase(parent)
    , ui(new Ui::AcousticAnalysisModule)
{
    ui->setupUi(this);
}

AcousticAnalysisModule::~AcousticAnalysisModule()
{
    delete ui;
}

void AcousticAnalysisModule::initUI()
{
    // 基类UI初始化
    AnalysisModuleBase::initUI();
}

void AcousticAnalysisModule::initParamsTable()
{
    // TODO: 实现参数表初始化
}

void AcousticAnalysisModule::startAnalysis()
{
    QMessageBox::information(this, "提示", "开始执行声学分析...");
}

void AcousticAnalysisModule::stopAnalysis()
{
    QMessageBox::information(this, "提示", "分析已停止");
}

void AcousticAnalysisModule::clearOutput()
{
    AnalysisModuleBase::clearOutput();
} 