#include "modal_analysis_module.h"
#include "ui_modal_analysis_module.h"
#include <QMessageBox>

ModalAnalysisModule::ModalAnalysisModule(QWidget* parent)
    : AnalysisModuleBase(parent)
    , ui(new Ui::ModalAnalysisModule)
{
    ui->setupUi(this);
}

ModalAnalysisModule::~ModalAnalysisModule()
{
    delete ui;
}

void ModalAnalysisModule::initUI()
{
    // 基类UI初始化
    AnalysisModuleBase::initUI();
}

void ModalAnalysisModule::initParamsTable()
{
    // TODO: 实现参数表初始化
}

void ModalAnalysisModule::startAnalysis()
{
    QMessageBox::information(this, "提示", "开始执行模态分析...");
}

void ModalAnalysisModule::stopAnalysis()
{
    QMessageBox::information(this, "提示", "分析已停止");
}

void ModalAnalysisModule::clearOutput()
{
    AnalysisModuleBase::clearOutput();
} 