#include "static_analysis_module.h"
#include "ui_static_analysis_module.h"
#include <QMessageBox>

StaticAnalysisModule::StaticAnalysisModule(QWidget* parent)
    : AnalysisModuleBase(parent)
    , ui(new Ui::StaticAnalysisModule)
{
    ui->setupUi(this);
}

StaticAnalysisModule::~StaticAnalysisModule()
{
    delete ui;
}

void StaticAnalysisModule::initUI()
{
    // 基类UI初始化
    AnalysisModuleBase::initUI();
}

void StaticAnalysisModule::initParamsTable()
{
    // TODO: 实现参数表初始化
}

void StaticAnalysisModule::startAnalysis()
{
    QMessageBox::information(this, "提示", "开始执行静力学分析...");
}

void StaticAnalysisModule::stopAnalysis()
{
    QMessageBox::information(this, "提示", "分析已停止");
}

void StaticAnalysisModule::clearOutput()
{
    AnalysisModuleBase::clearOutput();
} 