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
    loadTasks();
}

Workbench::~Workbench()
{
    delete ui;
}

void Workbench::initUI()
{
    setWindowTitle("CD声学仿真平台 - 工作台");
    resize(1200, 800);

    // 设置表格属性
    ui->tableTask->horizontalHeader()->setStretchLastSection(true);
    ui->tableTask->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableTask->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableTask->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void Workbench::setupConnections()
{
    connect(ui->tableTask, &QTableWidget::doubleClicked, this, &Workbench::onTaskDoubleClicked);
    connect(ui->comboBoxStatus, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Workbench::onTaskStatusChanged);
    connect(ui->btnRefresh, &QPushButton::clicked, this, &Workbench::onRefreshClicked);
}

void Workbench::loadTasks()
{
    // TODO: 从数据库加载任务列表
}

void Workbench::loadTaskDetails(int taskId)
{
    // TODO: 加载任务详细信息
}

void Workbench::onTaskDoubleClicked(const QModelIndex& index)
{
    int taskId = ui->tableTask->item(index.row(), 0)->text().toInt();
    loadTaskDetails(taskId);
}

void Workbench::onTaskStatusChanged(int status)
{
    loadTasks();
}

void Workbench::onRefreshClicked()
{
    loadTasks();
} 