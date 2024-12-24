#include "config_dialog.h"
#include "ui_config_dialog.h"
#include "../utils/config.h"
#include <QFileDialog>
#include <QMessageBox>

ConfigDialog::ConfigDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::ConfigDialog)
{
    ui->setupUi(this);
    
    // 设置表格属性
    ui->tableSoftware->horizontalHeader()->setStretchLastSection(true);
    ui->tableSoftware->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableSoftware->setSelectionMode(QAbstractItemView::SingleSelection);
    
    // 连接信号槽
    connect(ui->btnBrowse, &QPushButton::clicked, this, &ConfigDialog::onBrowseClicked);
    connect(ui->btnSave, &QPushButton::clicked, this, &ConfigDialog::onSaveClicked);
    connect(ui->btnClose, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->btnAddSoftware, &QPushButton::clicked, this, &ConfigDialog::onAddSoftwareClicked);
    connect(ui->btnDeleteSoftware, &QPushButton::clicked, this, &ConfigDialog::onDeleteSoftwareClicked);
    
    // 加载配置
    loadConfig();
}

ConfigDialog::~ConfigDialog()
{
    delete ui;
}

void ConfigDialog::onBrowseClicked()
{
    int currentRow = ui->tableSoftware->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "警告", "请先选择一个软件！");
        return;
    }
    
    QString filePath = QFileDialog::getOpenFileName(this, "选择软件", "", "可执行文件 (*.exe)");
    if (!filePath.isEmpty()) {
        ui->tableSoftware->item(currentRow, 1)->setText(filePath);
    }
}

void ConfigDialog::onSaveClicked()
{
    saveConfig();
    QMessageBox::information(this, "提示", "配置保存成功！");
}

void ConfigDialog::onAddSoftwareClicked()
{
    int row = ui->tableSoftware->rowCount();
    ui->tableSoftware->insertRow(row);
    
    ui->tableSoftware->setItem(row, 0, new QTableWidgetItem(""));
    ui->tableSoftware->setItem(row, 1, new QTableWidgetItem(""));
    ui->tableSoftware->setItem(row, 2, new QTableWidgetItem(""));
}

void ConfigDialog::onDeleteSoftwareClicked()
{
    int currentRow = ui->tableSoftware->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "警告", "请先选择一个软件！");
        return;
    }
    
    if (QMessageBox::question(this, "确认", "确定要删除选中的软件配置吗？") == QMessageBox::Yes) {
        ui->tableSoftware->removeRow(currentRow);
    }
}

void ConfigDialog::loadConfig()
{
    // 清空表格
    ui->tableSoftware->setRowCount(0);
    
    // 加载所有软件配置
    QStringList softwareList = Config::getInstance().getSoftwareList();
    for (const QString& software : softwareList) {
        int row = ui->tableSoftware->rowCount();
        ui->tableSoftware->insertRow(row);
        
        // 设置软件名称
        ui->tableSoftware->setItem(row, 0, new QTableWidgetItem(software));
        // 设置软件路径
        ui->tableSoftware->setItem(row, 1, new QTableWidgetItem(Config::getInstance().getSoftwarePath(software)));
        // 设置命令行参数
        ui->tableSoftware->setItem(row, 2, new QTableWidgetItem(Config::getInstance().getSoftwareParams(software)));
    }
}

void ConfigDialog::saveConfig()
{
    // 保存所有软件配置
    for (int row = 0; row < ui->tableSoftware->rowCount(); ++row) {
        QString name = ui->tableSoftware->item(row, 0)->text();
        QString path = ui->tableSoftware->item(row, 1)->text();
        QString params = ui->tableSoftware->item(row, 2)->text();
        
        if (!name.isEmpty()) {
            Config::getInstance().setSoftwarePath(name, path);
            Config::getInstance().setSoftwareParams(name, params);
        }
    }
} 