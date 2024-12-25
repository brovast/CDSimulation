#include "workbench.h"
#include "ui_workbench.h"
#include "../core/database.h"
#include <QMessageBox>

Workbench::Workbench(int userId, QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::Workbench)
    , m_userId(userId)
{
    ui->setupUi(this);
    initUI();
    setupConnections();
    
    // 加载初始数据
    loadTaskList();
}

Workbench::~Workbench()
{
    delete ui;
}

void Workbench::initUI()
{
    // 设置窗口标题
    setWindowTitle("CD声学仿真平台 - 工作台");
    
    // 设置窗口大小
    resize(1200, 800);
    
    // 设置表格列宽
    ui->tableTaskList->setColumnWidth(0, 60);  // ID列
    ui->tableTaskList->setColumnWidth(1, 200); // 任务名称列
    ui->tableTaskList->setColumnWidth(2, 150); // 创建时间列
    ui->tableTaskList->setColumnWidth(3, 150); // 任务类型列
    ui->tableTaskList->setColumnWidth(4, 80);  // 状态列
    
    // 初始状态下禁用任务操作按钮
    ui->btnAcceptTask->setEnabled(false);
    ui->btnCompleteTask->setEnabled(false);
    
    // 设置任务执行标签页
    setupAnalysisModules();
}

void Workbench::setupConnections()
{
    // 任务筛选和搜索
    connect(ui->comboBoxStatus, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Workbench::onTaskFilterChanged);
    connect(ui->lineEditSearch, &QLineEdit::textChanged,
            this, &Workbench::onTaskSearch);
    
    // 任务选择
    connect(ui->tableTaskList->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &Workbench::onTaskSelectionChanged);
    
    // 任务操作按钮
    connect(ui->btnAcceptTask, &QPushButton::clicked,
            this, &Workbench::onAcceptTaskClicked);
    connect(ui->btnCompleteTask, &QPushButton::clicked,
            this, &Workbench::onCompleteTaskClicked);
}

void Workbench::loadTaskList()
{
    // 设置表头
    QStringList headers;
    headers << "ID" << "任务名称" << "创建时间" << "任务类型" << "状态" << "操作";
    ui->tableTaskList->setColumnCount(headers.size());
    ui->tableTaskList->setHorizontalHeaderLabels(headers);
    
    // 清空现有数据
    ui->tableTaskList->clearContents();
    ui->tableTaskList->setRowCount(0);
    
    // 获取状态筛选条件
    int statusFilter = ui->comboBoxStatus->currentIndex() - 1; // -1表示全部
    
    // 从数据库获取任务列表
    QList<Database::TaskInfo> tasks = Database::getInstance().getTaskList(statusFilter);
    
    // 更新表格
    for (const auto& task : tasks) {
        int row = ui->tableTaskList->rowCount();
        ui->tableTaskList->insertRow(row);
        
        // 设置各列数据
        ui->tableTaskList->setItem(row, 0, new QTableWidgetItem(QString::number(task.id)));
        ui->tableTaskList->setItem(row, 1, new QTableWidgetItem(task.name));
        ui->tableTaskList->setItem(row, 2, new QTableWidgetItem(task.createTime.toString("yyyy-MM-dd hh:mm:ss")));
        ui->tableTaskList->setItem(row, 3, new QTableWidgetItem(task.modelType));
        ui->tableTaskList->setItem(row, 4, new QTableWidgetItem(getStatusText(task.status)));
        
        // 添加操作按钮
        auto btnWidget = new QWidget(ui->tableTaskList);
        auto btnLayout = new QHBoxLayout(btnWidget);
        btnLayout->setContentsMargins(2, 2, 2, 2);
        btnLayout->setSpacing(2);
        
        auto viewBtn = new QPushButton("查看", btnWidget);
        viewBtn->setFixedSize(60, 25);
        connect(viewBtn, &QPushButton::clicked, this, [this, task]() {
            // TODO: 实现查看功能
            QMessageBox::information(this, "提示", QString("查看任务 %1").arg(task.id));
        });
        
        btnLayout->addWidget(viewBtn);
        btnLayout->addStretch();
        
        ui->tableTaskList->setCellWidget(row, 5, btnWidget);
    }
    
    // 调整列宽
    ui->tableTaskList->setColumnWidth(0, 60);  // ID列
    ui->tableTaskList->setColumnWidth(1, 200); // 任务名称列
    ui->tableTaskList->setColumnWidth(2, 150); // 创建时间列
    ui->tableTaskList->setColumnWidth(3, 150); // 任务类型列
    ui->tableTaskList->setColumnWidth(4, 80);  // 状态列
    ui->tableTaskList->setColumnWidth(5, 100); // 操作列
}

void Workbench::loadTaskDetails(int taskId)
{
    // 清空现有显示
    clearTaskDetails();
    
    // 获取任务信息
    Database::TaskInfo taskInfo;
    if (!Database::getInstance().getTaskInfo(taskId, taskInfo)) {
        QMessageBox::critical(this, "错误", "获取任务信息失败！");
        return;
    }
    
    // 显示基本信息
    ui->labelTaskNameValue->setText(taskInfo.name);
    ui->labelCreateTimeValue->setText(taskInfo.createTime.toString("yyyy-MM-dd hh:mm:ss"));
    ui->textBrowserDescription->setText(taskInfo.description);
    
    // 显示分析类型列表
    QList<Database::TaskAnalysisType> analysisTypes = 
        Database::getInstance().getTaskAnalysisTypes(taskId);
    for (const auto& type : analysisTypes) {
        ui->listWidgetAnalysisTypes->addItem(type.analysisType);
    }
    
    // 根据任务状态设置按钮状态
    ui->btnAcceptTask->setEnabled(taskInfo.status == 0);  // 只有待接收状态可以接收
    ui->btnCompleteTask->setEnabled(taskInfo.status == 1);  // 只有进行中状态可以完成
}

void Workbench::updateTaskStatus(int taskId, int status)
{
    // 更新数据库中的任务状态
    Database::TaskInfo taskInfo;
    if (!Database::getInstance().getTaskInfo(taskId, taskInfo)) {
        QMessageBox::critical(this, "错误", "获取任务信息失败！");
        return;
    }
    
    taskInfo.status = status;
    taskInfo.updateTime = QDateTime::currentDateTime();
    
    if (!Database::getInstance().updateTaskStatus(taskId, status)) {
        QMessageBox::critical(this, "错误", "更新任务状态失败！");
        return;
    }
    
    // 刷新任务列表和详情显示
    loadTaskList();
    loadTaskDetails(taskId);
}

QString Workbench::getStatusText(int status) const
{
    switch (status) {
        case 0: return "待接收";
        case 1: return "进行中";
        case 2: return "已完成";
        case 3: return "已取消";
        default: return "未知";
    }
}

void Workbench::clearTaskDetails()
{
    ui->labelTaskNameValue->clear();
    ui->labelCreateTimeValue->clear();
    ui->textBrowserDescription->clear();
    ui->listWidgetAnalysisTypes->clear();
    ui->btnAcceptTask->setEnabled(false);
    ui->btnCompleteTask->setEnabled(false);
}

// 实现槽函数
void Workbench::onTaskFilterChanged()
{
    loadTaskList();
}

void Workbench::onTaskSearch(const QString& text)
{
    // 在当前显示的任务中搜索
    for (int row = 0; row < ui->tableTaskList->rowCount(); ++row) {
        bool match = false;
        for (int col = 0; col < ui->tableTaskList->columnCount(); ++col) {
            QTableWidgetItem* item = ui->tableTaskList->item(row, col);
            if (item && item->text().contains(text, Qt::CaseInsensitive)) {
                match = true;
                break;
            }
        }
        ui->tableTaskList->setRowHidden(row, !match);
    }
}

void Workbench::onTaskSelectionChanged()
{
    QList<QTableWidgetItem*> selectedItems = ui->tableTaskList->selectedItems();
    if (!selectedItems.isEmpty()) {
        int row = selectedItems.first()->row();
        int taskId = ui->tableTaskList->item(row, 0)->text().toInt();
        loadTaskDetails(taskId);
    }
}

void Workbench::onAcceptTaskClicked()
{
    QList<QTableWidgetItem*> selectedItems = ui->tableTaskList->selectedItems();
    if (!selectedItems.isEmpty()) {
        int row = selectedItems.first()->row();
        int taskId = ui->tableTaskList->item(row, 0)->text().toInt();
        updateTaskStatus(taskId, 1);  // 更新为进行中状态
    }
}

void Workbench::onCompleteTaskClicked()
{
    QList<QTableWidgetItem*> selectedItems = ui->tableTaskList->selectedItems();
    if (!selectedItems.isEmpty()) {
        int row = selectedItems.first()->row();
        int taskId = ui->tableTaskList->item(row, 0)->text().toInt();
        updateTaskStatus(taskId, 2);  // 更改为已完成状态
    }
}

void Workbench::setupAnalysisModules()
{
    // 创建分析模块
    m_modalModule = new ModalAnalysisModule(this);
    m_staticModule = new StaticAnalysisModule(this);
    m_vibrationModule = new VibrationAnalysisModule(this);
    m_acousticModule = new AcousticAnalysisModule(this);
    m_underwaterModule = new UnderwaterAnalysisModule(this);

    // 获取任务执行标签页中的分析模块选择器
    QTabWidget* analysisModules = ui->tabTaskExecution->findChild<QTabWidget*>("tabAnalysisModules");
    if (!analysisModules) {
        analysisModules = new QTabWidget(ui->tabTaskExecution);
        auto layout = new QVBoxLayout(ui->tabTaskExecution);
        layout->addWidget(analysisModules);
    }

    // 添加各个分析模块
    analysisModules->addTab(m_modalModule, "模态分析");
    analysisModules->addTab(m_staticModule, "静力学分析");
    analysisModules->addTab(m_vibrationModule, "振动分析");
    analysisModules->addTab(m_acousticModule, "声学分析");
    analysisModules->addTab(m_underwaterModule, "水下仿真");
} 