#include "structure_hierarchy_dialog.h"
#include "ui_structure_hierarchy_dialog.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QDir>

StructureHierarchyDialog::StructureHierarchyDialog(const QString& templatePath, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::StructureHierarchyDialog)
    , m_templatePath(templatePath)
{
    ui->setupUi(this);
    
    // 设置文件系统模型
    m_model = new QFileSystemModel(this);
    m_model->setRootPath(templatePath);
    m_model->setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
    
    ui->treeView->setModel(m_model);
    ui->treeView->setRootIndex(m_model->index(templatePath));
    
    // 隐藏不需要的列
    for (int i = 1; i < m_model->columnCount(); ++i) {
        ui->treeView->hideColumn(i);
    }
    
    // 连接信号槽
    connect(ui->btnAddFolder, &QPushButton::clicked, this, &StructureHierarchyDialog::onAddFolderClicked);
    connect(ui->btnDeleteFolder, &QPushButton::clicked, this, &StructureHierarchyDialog::onDeleteFolderClicked);
}

StructureHierarchyDialog::~StructureHierarchyDialog()
{
    delete ui;
}

void StructureHierarchyDialog::onAddFolderClicked()
{
    QModelIndex currentIndex = ui->treeView->currentIndex();
    QString currentPath = currentIndex.isValid() ? 
                         m_model->filePath(currentIndex) : 
                         m_templatePath;
    
    bool ok;
    QString folderName = QInputDialog::getText(this, "新建文件夹",
                                             "请输入文件夹名称：", QLineEdit::Normal,
                                             "", &ok);
    if (ok && !folderName.isEmpty()) {
        QDir dir(currentPath);
        if (!dir.mkdir(folderName)) {
            QMessageBox::critical(this, "错误", "创建文件夹失败！");
        }
    }
}

void StructureHierarchyDialog::onDeleteFolderClicked()
{
    QModelIndex currentIndex = ui->treeView->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::warning(this, "警告", "请先选择一个文件夹！");
        return;
    }
    
    QString path = m_model->filePath(currentIndex);
    if (QMessageBox::question(this, "确认", "确定要删除该文件夹吗？") == QMessageBox::Yes) {
        QDir dir(path);
        if (!dir.removeRecursively()) {
            QMessageBox::critical(this, "错误", "删除文件夹失败！");
        }
    }
} 