#include "systemmanager.h"
#include "ui_systemmanager.h"
#include "../../utils/config.h"
#include "./usermanager.h"
#include "./rolemanager.h"
#include "./approvalmanager.h"
#include <QFileSystemModel>
#include <QMessageBox>

SystemManager::SystemManager(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::SystemManager)
{
    ui->setupUi(this);
    initUI();
    setupConnections();
    
    // 加载初始数据
    loadBasicDataTree();
    loadCDDataTree();
    loadTaskList();
}

SystemManager::~SystemManager()
{
    delete ui;
}

void SystemManager::initUI()
{
    // 设置窗口标题
    setWindowTitle("CD声学仿真平台 - 系统管理");
    
    // 设置窗口大小
    resize(1200, 800);

    // 设置系统管理标签页的初始索引
    ui->tabWidgetSystemManage->setCurrentIndex(0);
}

void SystemManager::setupConnections()
{
    // 数据管理相关连接
    connect(ui->treeViewBasicData, &QTreeView::clicked, this, &SystemManager::onBasicDataTreeClicked);
    connect(ui->treeViewCDData, &QTreeView::clicked, this, &SystemManager::onCDDataTreeClicked);
    connect(ui->btnNewModel, &QPushButton::clicked, this, &SystemManager::onNewModelClicked);
    connect(ui->btnAddStructureType, &QPushButton::clicked, this, &SystemManager::onAddStructureTypeClicked);
    connect(ui->btnCopyData, &QPushButton::clicked, this, &SystemManager::onCopyDataClicked);
    connect(ui->btnDelete, &QPushButton::clicked, this, &SystemManager::onDeleteClicked);

    // 系统管理相关连接
    connect(ui->tabWidgetSystemManage, &QTabWidget::currentChanged, this, &SystemManager::onSystemTabChanged);
}

void SystemManager::loadBasicDataTree()
{
    QFileSystemModel* model = new QFileSystemModel(this);
    model->setRootPath(Config::getInstance().getBasicDataPath());
    ui->treeViewBasicData->setModel(model);
    ui->treeViewBasicData->setRootIndex(model->index(Config::getInstance().getBasicDataPath()));
}

void SystemManager::loadCDDataTree()
{
    // 加载左侧基础数据树
    QFileSystemModel* basicModel = new QFileSystemModel(this);
    basicModel->setRootPath(Config::getInstance().getBasicDataPath());
    ui->treeViewCDBasicData->setModel(basicModel);
    ui->treeViewCDBasicData->setRootIndex(basicModel->index(Config::getInstance().getBasicDataPath()));
    
    // 加载右侧舱段数据树
    QFileSystemModel* cdModel = new QFileSystemModel(this);
    cdModel->setRootPath(Config::getInstance().getCDDataPath());
    ui->treeViewCDData->setModel(cdModel);
    ui->treeViewCDData->setRootIndex(cdModel->index(Config::getInstance().getCDDataPath()));
}

void SystemManager::loadTaskList()
{
    // TODO: 实现任务列表加载
}

void SystemManager::onBasicDataTreeClicked(const QModelIndex& index)
{
    // TODO: 实现基础数据树点击事��处理
}

void SystemManager::onCDDataTreeClicked(const QModelIndex& index)
{
    // TODO: 实现舱段数据树点击事件处理
}

void SystemManager::onNewModelClicked()
{
    // TODO: 实现新建型号功能
}

void SystemManager::onAddStructureTypeClicked()
{
    // TODO: 实现添加结构类型功能
}

void SystemManager::onCopyDataClicked()
{
    // TODO: 实现数据复制功能
}

void SystemManager::onDeleteClicked()
{
    // TODO: 实现删除功能
}

void SystemManager::onTaskFilterChanged()
{
    // TODO: 实现任务筛选功能
}

void SystemManager::onTaskSearch(const QString& text)
{
    // TODO: 实现任务搜索功能
}

void SystemManager::onTaskPublishClicked()
{
    // TODO: 实现任务发布功能
}

void SystemManager::onTaskDeleteClicked()
{
    // TODO: 实现任务删除功能
}

void SystemManager::onSystemTabChanged(int index)
{
    // 当切换到不同的系统管理标签页时刷新数据
    switch (index) {
        case 0: // 用户管理
            // UserManager widget会自动刷新
            break;
        case 1: // 角色管理
            // TODO: 刷新角色列表
            break;
        case 2: // 审批管理
            // TODO: 刷新审批列表
            break;
    }
}

// 其他槽函数的实现将在后续添加... 