#include "approvalmanager.h"
#include "ui_approvalmanager.h"
#include "../../core/database.h"
#include <QMessageBox>

ApprovalManager::ApprovalManager(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::ApprovalManager)
    , m_approvalModel(new QStandardItemModel(this))
{
    ui->setupUi(this);
    initUI();
    setupConnections();
    loadApprovalList();
}

ApprovalManager::~ApprovalManager()
{
    delete ui;
}

void ApprovalManager::initUI()
{
    // 设置表格标题
    QStringList headers;
    headers << "ID" << "申请用户" << "审批人" << "状态" << "申请时间" << "审批时间";
    m_approvalModel->setHorizontalHeaderLabels(headers);
    ui->tableView->setModel(m_approvalModel);

    // 设置列宽
    ui->tableView->setColumnWidth(0, 50);  // ID列
    ui->tableView->setColumnWidth(1, 100); // 申请用户列
    ui->tableView->setColumnWidth(2, 100); // 审批人列
    ui->tableView->setColumnWidth(3, 80);  // 状态列
    ui->tableView->setColumnWidth(4, 150); // 申请时间列
    ui->tableView->setColumnWidth(5, 150); // 审批时间列
}

void ApprovalManager::setupConnections()
{
    connect(ui->btnApprove, &QPushButton::clicked, this, &ApprovalManager::onApproveClicked);
    connect(ui->btnReject, &QPushButton::clicked, this, &ApprovalManager::onRejectClicked);
    connect(ui->btnRefresh, &QPushButton::clicked, this, &ApprovalManager::onRefreshClicked);
    connect(ui->comboBoxStatus, QOverload<int>::of(&QComboBox::currentIndexChanged), 
            this, &ApprovalManager::onFilterChanged);
}

void ApprovalManager::loadApprovalList()
{
    // 清空现有数据
    m_approvalModel->removeRows(0, m_approvalModel->rowCount());
    
    // 获取状态筛选条件
    int statusFilter = ui->comboBoxStatus->currentIndex() - 1; // -1表示全部
    
    // 从数据库获取审批列表
    QList<Database::ApprovalInfo> approvals = Database::getInstance().getApprovalList(statusFilter);
    
    // 更新表格模型
    for (const auto& approval : approvals) {
        QList<QStandardItem*> row;
        
        // ID
        row.append(new QStandardItem(QString::number(approval.id)));
        
        // 申请用户
        row.append(new QStandardItem(approval.username));
        
        // 审批人
        row.append(new QStandardItem(approval.approverName));
        
        // 状态
        QString statusText;
        switch (approval.status) {
            case 0: statusText = "待审批"; break;
            case 1: statusText = "已通过"; break;
            case 2: statusText = "已拒绝"; break;
            default: statusText = "未知";
        }
        row.append(new QStandardItem(statusText));
        
        // 申请时间
        row.append(new QStandardItem(approval.createTime.toString("yyyy-MM-dd hh:mm:ss")));
        
        // 审批时间
        row.append(new QStandardItem(approval.approveTime.isValid() ? 
                                   approval.approveTime.toString("yyyy-MM-dd hh:mm:ss") : ""));
        
        m_approvalModel->appendRow(row);
    }
}

void ApprovalManager::onApproveClicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请先选择一条审批记录！");
        return;
    }
    
    int row = index.row();
    int userId = m_approvalModel->item(row, 0)->text().toInt();
    
    if (Database::getInstance().updateUserStatus(userId, 1, 1)) { // 1表示通过，第二个1是管理员ID
        QMessageBox::information(this, "提示", "审批通过成功！");
        loadApprovalList();
    } else {
        QMessageBox::critical(this, "错误", "审批失败！");
    }
}

void ApprovalManager::onRejectClicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请先选择一条审批记录！");
        return;
    }
    
    int row = index.row();
    int userId = m_approvalModel->item(row, 0)->text().toInt();
    
    if (Database::getInstance().updateUserStatus(userId, 2, 1)) { // 2表示拒绝，1是管理员ID
        QMessageBox::information(this, "提示", "已拒绝该申请！");
        loadApprovalList();
    } else {
        QMessageBox::critical(this, "错误", "操作失败！");
    }
}

void ApprovalManager::onRefreshClicked()
{
    loadApprovalList();
}

void ApprovalManager::onFilterChanged(int index)
{
    loadApprovalList();
} 