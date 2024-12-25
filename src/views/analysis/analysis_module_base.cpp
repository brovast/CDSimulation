#include "analysis_module_base.h"
#include <QHeaderView>
#include <QFileDialog>
#include <QMessageBox>

AnalysisModuleBase::AnalysisModuleBase(QWidget* parent)
    : QWidget(parent)
{
    initUI();
    setupConnections();
}

AnalysisModuleBase::~AnalysisModuleBase()
{
}

void AnalysisModuleBase::initUI()
{
    auto mainLayout = new QVBoxLayout(this);
    
    // 创建参数设置组
    createParamsGroup();
    mainLayout->addWidget(m_paramsGroup);
    
    // 创建执行控制组
    createExecutionGroup();
    mainLayout->addWidget(m_executionGroup);
    
    // 创建结果显示组
    createResultsGroup();
    mainLayout->addWidget(m_resultsGroup);
}

void AnalysisModuleBase::createParamsGroup()
{
    m_paramsGroup = new QGroupBox("参数设置", this);
    auto layout = new QVBoxLayout(m_paramsGroup);
    
    // 创建参数表格
    m_paramsTable = new QTableWidget(this);
    m_paramsTable->setColumnCount(4);
    m_paramsTable->setHorizontalHeaderLabels({"参数名称", "参数值", "单位", "说明"});
    m_paramsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    layout->addWidget(m_paramsTable);
    
    // 创建模板按钮
    auto btnLayout = new QHBoxLayout;
    m_loadTemplateBtn = new QPushButton("加载模板", this);
    m_saveTemplateBtn = new QPushButton("保存模板", this);
    btnLayout->addWidget(m_loadTemplateBtn);
    btnLayout->addWidget(m_saveTemplateBtn);
    layout->addLayout(btnLayout);
}

void AnalysisModuleBase::createExecutionGroup()
{
    m_executionGroup = new QGroupBox("命令执行", this);
    auto layout = new QHBoxLayout(m_executionGroup);
    
    m_startBtn = new QPushButton("开始分析", this);
    m_stopBtn = new QPushButton("停止分析", this);
    m_clearBtn = new QPushButton("清除输出", this);
    
    layout->addWidget(m_startBtn);
    layout->addWidget(m_stopBtn);
    layout->addWidget(m_clearBtn);
    
    m_stopBtn->setEnabled(false);
}

void AnalysisModuleBase::createResultsGroup()
{
    m_resultsGroup = new QGroupBox("结果显示", this);
    auto layout = new QVBoxLayout(m_resultsGroup);
    
    m_resultsTree = new QTreeView(this);
    layout->addWidget(m_resultsTree);
}

void AnalysisModuleBase::setupConnections()
{
    connect(m_loadTemplateBtn, &QPushButton::clicked, this, [this]() {
        QString path = QFileDialog::getOpenFileName(this, "加载参数模板", 
            QString(), "参数模板文件 (*.json)");
        if (!path.isEmpty()) {
            loadParamTemplate(path);
        }
    });
    
    connect(m_saveTemplateBtn, &QPushButton::clicked, this, [this]() {
        QString path = QFileDialog::getSaveFileName(this, "保存参数模板",
            QString(), "参数模板文件 (*.json)");
        if (!path.isEmpty()) {
            saveParamTemplate(path);
        }
    });
    
    connect(m_startBtn, &QPushButton::clicked, this, [this]() {
        m_startBtn->setEnabled(false);
        m_stopBtn->setEnabled(true);
        startAnalysis();
    });
    
    connect(m_stopBtn, &QPushButton::clicked, this, [this]() {
        m_startBtn->setEnabled(true);
        m_stopBtn->setEnabled(false);
        stopAnalysis();
    });
    
    connect(m_clearBtn, &QPushButton::clicked, this, &AnalysisModuleBase::clearOutput);
}

void AnalysisModuleBase::loadParamTemplate(const QString& templatePath)
{
    // TODO: 实现参数模板加载逻辑
}

void AnalysisModuleBase::saveParamTemplate(const QString& templatePath)
{
    // TODO: 实现参数模板保存逻辑
}

void AnalysisModuleBase::stopAnalysis()
{
    // TODO: 实现停止分析的基本逻辑
}

void AnalysisModuleBase::clearOutput()
{
    // 清空结果树
    if (m_resultsTree->model()) {
        delete m_resultsTree->model();
        m_resultsTree->setModel(nullptr);
    }
} 