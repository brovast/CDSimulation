#include "structure_hierarchy_dialog.h"
#include "systemmanager.h"
#include "ui_systemmanager.h"
#include "../../utils/config.h"
#include "../../core/database.h"
#include "./usermanager.h"
#include "./rolemanager.h"
#include "./approvalmanager.h"
#include <QFileSystemModel>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QTextStream>
#include <QPixmap>
#include <QDir>
#include <QFileInfo>
#include <QRegularExpression>
#include <QDateTime>
#include <QtCharts>
#include <QChart>
#include <QLineSeries>
#include <QValueAxis>

SystemManager::SystemManager(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::SystemManager)
    , m_basicDataModel(new QFileSystemModel(this))
    , m_loadChart(new QChart())
    , m_loadSeries(new QLineSeries())
{
    ui->setupUi(this);
    
    // 初始化图表
    m_loadChart->addSeries(m_loadSeries);
    m_loadChart->createDefaultAxes();
    m_loadChart->setTitle("载荷曲线");
    ui->chartLoadView->setChart(m_loadChart);
    
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
    delete m_loadChart;
    delete m_loadSeries;
}

void SystemManager::initUI()
{
    // 设置窗口标题
    setWindowTitle("CD声学仿真平台 - 系统管理");
    
    // 设置窗口大小
    resize(1200, 800);

    // 设置系统管理标签页的初始索引
    ui->tabWidgetSystemManage->setCurrentIndex(0);
    
    // 初始化基础数据路径
    m_currentBasicDataPath = Config::getInstance().getBasicDataPath();
    ui->lineEditBasicDataPath->setText(m_currentBasicDataPath);
    
    // 设置文件系统模型
    m_basicDataModel->setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot);
    //m_basicDataModel->setNameFilters({"*.txt", "*.png", "*.jpg", "*.jpeg"});
    m_basicDataModel->setNameFilterDisables(false);
    
    // 设置树形视图
    ui->treeViewBasicData->setModel(m_basicDataModel);
    ui->treeViewBasicData->setRootIndex(m_basicDataModel->index(m_currentBasicDataPath));
    
    // 隐藏不需要的列，只显示名称列
    for (int i = 1; i < m_basicDataModel->columnCount(); ++i) {
        ui->treeViewBasicData->hideColumn(i);
    }
    
    // 初始化舱段数据路径
    QString cdDataPath = Config::getInstance().getCDDataPath();
    ui->lineEditCDDataPath->setText(cdDataPath);
    
    // 初始化任务管理界面
    // 设置表格列宽
    ui->tableTaskList->setColumnWidth(0, 60);  // ID列
    ui->tableTaskList->setColumnWidth(1, 150); // 任务名称列
    ui->tableTaskList->setColumnWidth(2, 100); // 任务类型列
    ui->tableTaskList->setColumnWidth(3, 80);  // 状态列
    ui->tableTaskList->setColumnWidth(4, 100); // 派人员列
    ui->tableTaskList->setColumnWidth(5, 150); // 创建时间列
    
    // 加载工程师列表到指派下拉框
    loadEngineerList();
    
    // 加载型号列表到下拉框
    loadModelTypeList();
    
    // 设置工作目录
    QString defaultWorkDir = QDir(QCoreApplication::applicationDirPath()).filePath("tasks");
    ui->lineEditWorkDir->setText(defaultWorkDir);
    
    // 加载声学参数库CSV文件
    m_currentAcousticsCSVPath = Config::getInstance().getValue("AcousticsCSV/Path").toString();
    if (!m_currentAcousticsCSVPath.isEmpty()) {
        ui->lineEditAcousticsPath->setText(m_currentAcousticsCSVPath);
        loadAcousticsCSV(m_currentAcousticsCSVPath);
    }
    
    // 加载材料库CSV文件
    m_currentMaterialCSVPath = Config::getInstance().getValue("MaterialCSV/Path").toString();
    if (!m_currentMaterialCSVPath.isEmpty()) {
        ui->lineEditCSVPath->setText(m_currentMaterialCSVPath);
        loadCSVData(m_currentMaterialCSVPath);
    }
    
    // 加载载荷库路径
    m_currentLoadPath = Config::getInstance().getValue("LoadData/Path").toString();
    if (!m_currentLoadPath.isEmpty()) {
        ui->lineEditLoadPath->setText(m_currentLoadPath);
        loadLoadFiles();
    }
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

    // 基础数据管理相关连接
    connect(ui->btnSelectBasicDataPath, &QPushButton::clicked, 
            this, &SystemManager::onSelectBasicDataPath);
    connect(ui->btnAddBasicFolder, &QPushButton::clicked, 
            this, &SystemManager::onAddBasicFolder);
    connect(ui->btnDeleteBasicData, &QPushButton::clicked, 
            this, &SystemManager::onDeleteBasicData);
    connect(ui->treeViewBasicData, &QTreeView::clicked, 
            this, &SystemManager::onBasicDataItemClicked);

    // 添加舱段数据路径选择按钮的连接
    connect(ui->btnSelectCDDataPath, &QPushButton::clicked, this, [this]() {
        QString path = QFileDialog::getExistingDirectory(
            this,
            "选择舱段数据目录",
            ui->lineEditCDDataPath->text(),
            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
        );
        
        if (!path.isEmpty()) {
            ui->lineEditCDDataPath->setText(path);
            Config::getInstance().setCDDataPath(path);
            loadCDDataTree();  // 重新加载树形视图
        }
    });

    // 任务管理相关连接
    connect(ui->comboBoxStatusFilter, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &SystemManager::onTaskFilterChanged);
    connect(ui->comboBoxTypeFilter, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &SystemManager::onTaskFilterChanged);
    connect(ui->lineEditSearch, &QLineEdit::textChanged,
            this, &SystemManager::onTaskSearch);
    connect(ui->tableTaskList->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &SystemManager::onTaskSelectionChanged);
    connect(ui->btnSelectWorkDir, &QPushButton::clicked, this, &SystemManager::onSelectWorkDirClicked);
    connect(ui->comboBoxModelSelect, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &SystemManager::onModelTypeChanged);
    connect(ui->btnTaskPublish, &QPushButton::clicked, this, &SystemManager::onTaskPublishClicked);
    connect(ui->btnTaskDelete, &QPushButton::clicked, this, &SystemManager::onTaskDeleteClicked);

    // 声学参数库相关连接
    connect(ui->btnSelectAcousticsCSV, &QPushButton::clicked, this, &SystemManager::onSelectAcousticsPath);

    // 添加材料库相关连接
    connect(ui->btnSelectCSV, &QPushButton::clicked, this, &SystemManager::onSelectCSVClicked);

    // 添加载荷库相关连接
    connect(ui->btnSelectLoadPath, &QPushButton::clicked, 
            this, &SystemManager::onSelectLoadPathClicked);
    connect(ui->listLoadFiles, &QListWidget::itemClicked, 
            this, &SystemManager::onLoadFileSelected);

    // 添加附件相关连接
    connect(ui->btnSelectTaskAttachment, &QPushButton::clicked, this, [this]() {
        QString filePath = QFileDialog::getOpenFileName(this, "选择附件");
        if (!filePath.isEmpty()) {
            ui->lineEditTaskAttachmentPath->setText(filePath);
        }
    });
}

void SystemManager::loadBasicDataTree()
{
    m_basicDataModel->setRootPath(m_currentBasicDataPath);
    ui->treeViewBasicData->setRootIndex(
        m_basicDataModel->index(m_currentBasicDataPath)
    );
}

void SystemManager::loadCDDataTree()
{
    // 加载左侧基础数据树
    QFileSystemModel* basicModel = new QFileSystemModel(this);
    basicModel->setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot);
    basicModel->setRootPath(Config::getInstance().getBasicDataPath());
    ui->treeViewCDBasicData->setModel(basicModel);
    ui->treeViewCDBasicData->setRootIndex(basicModel->index(Config::getInstance().getBasicDataPath()));
    
    // 隐藏左侧树的不需要的列
    for (int i = 1; i < basicModel->columnCount(); ++i) {
        ui->treeViewCDBasicData->hideColumn(i);
    }
    
    // 加载右侧舱段数据树
    QString cdDataPath = Config::getInstance().getCDDataPath();
    QFileSystemModel* cdModel = new QFileSystemModel(this);
    cdModel->setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot);
    cdModel->setRootPath(cdDataPath);
    ui->treeViewCDData->setModel(cdModel);
    ui->treeViewCDData->setRootIndex(cdModel->index(cdDataPath));
    
    // 隐藏右侧树的不需要的列
    for (int i = 1; i < cdModel->columnCount(); ++i) {
        ui->treeViewCDData->hideColumn(i);
    }
}

void SystemManager::loadTaskList()
{
    ui->tableTaskList->clearContents();
    ui->tableTaskList->setRowCount(0);
    
    // 获取筛选条件
    int statusFilter = ui->comboBoxStatusFilter->currentIndex() - 1; // -1表示全部
    QString typeFilter = ui->comboBoxTypeFilter->currentIndex() == 0 ? 
                        QString() : ui->comboBoxTypeFilter->currentText();
    
    // 从数据库加载任务列表
    QList<Database::TaskInfo> tasks = Database::getInstance().getTaskList(statusFilter, typeFilter);
    
    for (const auto& task : tasks) {
        int row = ui->tableTaskList->rowCount();
        ui->tableTaskList->insertRow(row);
        
        // 设置任务ID
        ui->tableTaskList->setItem(row, 0, new QTableWidgetItem(QString::number(task.id)));
        
        // 设置任务名称
        ui->tableTaskList->setItem(row, 1, new QTableWidgetItem(task.name));
        
        // 设置任务类型（从任务分析类型表中获取）
        QList<Database::TaskAnalysisType> analysisTypes = Database::getInstance().getTaskAnalysisTypes(task.id);
        QStringList types;
        for (const auto& type : analysisTypes) {
            types << type.analysisType;
        }
        ui->tableTaskList->setItem(row, 2, new QTableWidgetItem(types.join(";")));
        
        // 设置任务状态
        QString status;
        switch (task.status) {
            case 0: status = "待处理"; break;
            case 1: status = "进行中"; break;
            case 2: status = "已完成"; break;
            case 3: status = "已取消"; break;
            default: status = "未知"; break;
        }
        ui->tableTaskList->setItem(row, 3, new QTableWidgetItem(status));
        
        // 设置指派人员
        QString username;
        int roleId;
        if (Database::getInstance().getUserInfo(task.assignedTo, username, roleId)) {
            ui->tableTaskList->setItem(row, 4, new QTableWidgetItem(username));
        } else {
            ui->tableTaskList->setItem(row, 4, new QTableWidgetItem("未知"));
        }
        
        // 设置创建时间
        ui->tableTaskList->setItem(row, 5, 
            new QTableWidgetItem(task.createTime.toString("yyyy-MM-dd hh:mm:ss")));
    }
    
    // 调整列宽
    ui->tableTaskList->resizeColumnsToContents();
    // 保持ID列和状态列的固定宽度
    ui->tableTaskList->setColumnWidth(0, 60);  // ID列
    ui->tableTaskList->setColumnWidth(3, 80);  // 状态列
}

void SystemManager::onBasicDataTreeClicked(const QModelIndex& index)
{
    // TODO: 实现基础数据树点击事件处理
}

void SystemManager::onCDDataTreeClicked(const QModelIndex& index)
{
    QFileSystemModel* model = qobject_cast<QFileSystemModel*>(ui->treeViewCDData->model());
    if (!model) return;
    
    QString path = model->filePath(index);
    previewBasicDataFile(path); // 复用基础数据预览功能
}

void SystemManager::onNewModelClicked()
{
    bool ok;
    QString modelName = QInputDialog::getText(this, "新建型号",
                                            "请输入型号名称：", QLineEdit::Normal,
                                            "", &ok);
    if (!ok || modelName.isEmpty()) {
        return;
    }
    
    // 获取CD数据路径和模板路径
    QString cdDataPath = Config::getInstance().getCDDataPath();
    QString templatePath = QDir(cdDataPath).filePath("_template");
    QString modelPath = QDir(cdDataPath).filePath(modelName);
    
    // 检查型号是否已存在
    if (QDir(modelPath).exists()) {
        QMessageBox::warning(this, "警告", "该型号已存在！");
        return;
    }
    
    // 复制模板目录结构到新型号目录
    if (!copyDirectory(templatePath, modelPath)) {
        QMessageBox::critical(this, "错误", "创建型号目录失败！");
        return;
    }
    
    // 刷新树形视图
    loadCDDataTree();
}

void SystemManager::onAddStructureTypeClicked()
{
    // 获取模板目录路径
    QString templatePath = QDir(Config::getInstance().getCDDataPath()).filePath("_template");
    
    // 确保模板目录存在
    QDir().mkpath(templatePath);
    
    // 显示结构层级维护对话框
    StructureHierarchyDialog dialog(templatePath, this);
    dialog.exec();
}

void SystemManager::onCopyDataClicked()
{
    // 获取源路径（左侧树）
    QModelIndex sourceIndex = ui->treeViewCDBasicData->currentIndex();
    if (!sourceIndex.isValid()) {
        QMessageBox::warning(this, "警告", "请先选择要复制的源文件夹！");
        return;
    }
    
    // 获取目标路径（右侧树）
    QModelIndex targetIndex = ui->treeViewCDData->currentIndex();
    if (!targetIndex.isValid()) {
        QMessageBox::warning(this, "警告", "请先选择目标文件夹！");
        return;
    }
    
    QFileSystemModel* sourceModel = qobject_cast<QFileSystemModel*>(ui->treeViewCDBasicData->model());
    QFileSystemModel* targetModel = qobject_cast<QFileSystemModel*>(ui->treeViewCDData->model());
    
    QString sourcePath = sourceModel->filePath(sourceIndex);
    QString targetPath = targetModel->filePath(targetIndex);
    
    // 确认源是文件夹
    QFileInfo sourceInfo(sourcePath);
    if (!sourceInfo.isDir()) {
        QMessageBox::warning(this, "警告", "请选择一个文件夹进行复制！");
        return;
    }
    
    // 确认操作
    if (QMessageBox::question(
            this,
            "确认复制",
            QString("确定要将 %1 复制到 %2 吗？")
                .arg(sourceInfo.fileName())
                .arg(QDir(targetPath).dirName()),
            QMessageBox::Yes | QMessageBox::No
        ) != QMessageBox::Yes) 
    {
        return;
    }
    
    // 执行复制
    QDir sourceDir(sourcePath);
    QDir targetDir(targetPath);
    QString newFolderPath = targetDir.filePath(sourceInfo.fileName());
    
    // 如果目标文件夹已存在，先删除
    if (targetDir.exists(sourceInfo.fileName())) {
        QDir(newFolderPath).removeRecursively();
    }
    
    // 复制文件夹及其内容
    if (!copyDirectory(sourcePath, newFolderPath)) {
        QMessageBox::critical(this, "错误", "复制失败！");
        return;
    }
    
    QMessageBox::information(this, "提示", "复制成功！");
}

void SystemManager::onDeleteClicked()
{
    QModelIndex currentIndex = ui->treeViewCDData->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::warning(this, "警告", "请先选择要删除的项目！");
        return;
    }
    
    QFileSystemModel* model = qobject_cast<QFileSystemModel*>(ui->treeViewCDData->model());
    QString path = model->filePath(currentIndex);
    QFileInfo fileInfo(path);
    
    // 确认删除
    if (QMessageBox::question(
            this,
            "确认删除",
            QString("确定要删除 %1 吗？\n此操作将删除所有子文件夹和文件！").arg(fileInfo.fileName()),
            QMessageBox::Yes | QMessageBox::No
        ) == QMessageBox::Yes) 
    {
        QDir dir(path);
        if (!dir.removeRecursively()) {
            QMessageBox::critical(this, "错误", "删除失败！");
            return;
        }
        QMessageBox::information(this, "提示", "删除成功！");
    }
}

void SystemManager::onTaskFilterChanged()
{
    loadTaskList();
}

void SystemManager::onTaskSearch(const QString& text)
{
    // 实现任务搜索功能
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

void SystemManager::onTaskSelectionChanged()
{
    // TODO: 当选中任务时更新任务详情显示
    // 这部分将在实现任务详情界面后完成
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

void SystemManager::onSelectBasicDataPath()
{
    QString path = QFileDialog::getExistingDirectory(
        this, 
        "选择基础数据目录",
        m_currentBasicDataPath,
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
    );
    
    if (!path.isEmpty()) {
        m_currentBasicDataPath = path;
        ui->lineEditBasicDataPath->setText(path);
        Config::getInstance().setBasicDataPath(path);
        loadBasicDataTree();
    }
}

void SystemManager::onAddBasicFolder()
{
    QModelIndex currentIndex = ui->treeViewBasicData->currentIndex();
    QString currentPath = m_basicDataModel->filePath(currentIndex);
    
    if (currentPath.isEmpty()) {
        currentPath = m_currentBasicDataPath;
    }
    
    bool ok;
    QString folderName = QInputDialog::getText(
        this, 
        "新建文件夹",
        "请输入文件夹名称：",
        QLineEdit::Normal,
        "",
        &ok
    );
    
    if (ok && !folderName.isEmpty()) {
        QDir dir(currentPath);
        if (!dir.mkdir(folderName)) {
            QMessageBox::critical(this, "错误", "创建文件夹失败！");
        }
    }
}

void SystemManager::onDeleteBasicData()
{
    QModelIndex currentIndex = ui->treeViewBasicData->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::warning(this, "警告", "请先选择要删除的项目！");
        return;
    }
    
    QString path = m_basicDataModel->filePath(currentIndex);
    QFileInfo fileInfo(path);
    
    if (QMessageBox::question(
            this,
            "确认删除",
            QString("确定要删除 %1 吗？").arg(fileInfo.fileName()),
            QMessageBox::Yes | QMessageBox::No
        ) == QMessageBox::Yes) 
    {
        bool success;
        if (fileInfo.isDir()) {
            QDir dir(path);
            success = dir.removeRecursively();
        } else {
            QFile file(path);
            success = file.remove();
        }
        
        if (!success) {
            QMessageBox::critical(this, "错误", "删除失败！");
        }
    }
}

void SystemManager::onBasicDataItemClicked(const QModelIndex& index)
{
    QString path = m_basicDataModel->filePath(index);
    previewBasicDataFile(path);
}

void SystemManager::previewBasicDataFile(const QString& filePath)
{
    QFileInfo fileInfo(filePath);
    
    // 清空预览区
    ui->labelImagePreview->clear();
    ui->textEditContentPreview->clear();
    
    // 如果是文件夹，显示文件夹内容预览
    if (fileInfo.isDir()) {
        QDir dir(filePath);
        
        // 获取所有图片文件
        QStringList imageFilters;
        imageFilters << "*.png" << "*.jpg" << "*.jpeg" << "*.bmp";
        QStringList imageFiles = dir.entryList(imageFilters, QDir::Files);
        
        // 获取所有文本文件
        QStringList textFiles = dir.entryList(QStringList() << "*.txt", QDir::Files);
        
        // 如果有图片文件，显示第一张图片的预览
        if (!imageFiles.isEmpty()) {
            QString firstImagePath = dir.filePath(imageFiles.first());
            QPixmap pixmap(firstImagePath);
            if (!pixmap.isNull()) {
                ui->labelImagePreview->setPixmap(
                    pixmap.scaled(
                        ui->labelImagePreview->size(),
                        Qt::KeepAspectRatio,
                        Qt::SmoothTransformation
                    )
                );
            }
        }
        
        // 显示文件夹内容概览和文本文件预览
        QString preview = "文件夹内容：\n";
        preview += QString("图片文件(%1)：\n").arg(imageFiles.size());
        for (const QString& file : imageFiles) {
            preview += "  " + file + "\n";
        }
        
        preview += QString("\n本文件(%1)：\n").arg(textFiles.size());
        for (const QString& file : textFiles) {
            preview += "  " + file + "\n";
            
            // 添加文本文件内容预览（显示前几行）
            QFile txtFile(dir.filePath(file));
            if (txtFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&txtFile);
                QString content;
                for (int i = 0; i < 5 && !in.atEnd(); ++i) { // 显示前5行
                    content += in.readLine() + "\n";
                }
                if (!in.atEnd()) {
                    content += "...\n";
                }
                preview += "内容预览：\n" + content + "\n";
                txtFile.close();
            }
        }
        
        ui->textEditContentPreview->setText(preview);
        return;
    }
    
    // 如果是图片文件
    QString suffix = fileInfo.suffix().toLower();
    if (suffix == "png" || suffix == "jpg" || suffix == "jpeg" || suffix == "bmp") {
        QPixmap pixmap(filePath);
        if (!pixmap.isNull()) {
            ui->labelImagePreview->setPixmap(
                pixmap.scaled(
                    ui->labelImagePreview->size(),
                    Qt::KeepAspectRatio,
                    Qt::SmoothTransformation
                )
            );
        }
    }
    // 如果是文本文件
    else if (fileInfo.suffix().toLower() == "txt") {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            ui->textEditContentPreview->setText(in.readAll());
            file.close();
        }
    }
}

// 添加辅助函数用于复制目录
bool SystemManager::copyDirectory(const QString& sourcePath, const QString& targetPath)
{
    QDir sourceDir(sourcePath);
    QDir targetDir(targetPath);
    
    // 如果目标目录不存在，创建它
    if (!targetDir.exists()) {
        if (!targetDir.mkpath(".")) {
            return false;
        }
    }
    
    // 复制所有文件和子目录
    foreach(const QFileInfo& info, sourceDir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot)) {
        QString srcItemPath = sourcePath + "/" + info.fileName();
        QString dstItemPath = targetPath + "/" + info.fileName();
        if (info.isDir()) {
            // 递归复制子目录
            if (!copyDirectory(srcItemPath, dstItemPath)) {
                return false;
            }
        } else {
            // 复制文件
            if (!QFile::copy(srcItemPath, dstItemPath)) {
                return false;
            }
        }
    }
    
    return true;
}

// 加载工程师列表
void SystemManager::loadEngineerList()
{
    ui->comboBoxUserSelect->clear();
    
    // 获取角色工程师的用户列表
    QList<Database::UserInfo> users = Database::getInstance().getUserList(1); // 1表示已审批状态
    for (const auto& user : users) {
        if (user.roleId == 2) { // 2表示工程师角色
            ui->comboBoxUserSelect->addItem(user.username, user.id);
        }
    }
}

// 加载型号列表
void SystemManager::loadModelTypeList()
{
    ui->comboBoxModelSelect->clear();
    
    QString cdDataPath = Config::getInstance().getCDDataPath();
    QDir dir(cdDataPath);
    QStringList modelTypes = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    
    ui->comboBoxModelSelect->addItems(modelTypes);
}

// 选择工作目录
void SystemManager::onSelectWorkDirClicked()
{
    QString dir = QFileDialog::getExistingDirectory(
        this,
        "选择工作目录",
        ui->lineEditWorkDir->text(),
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
    );
    
    if (!dir.isEmpty()) {
        ui->lineEditWorkDir->setText(dir);
    }
}

// 型号选择改变时更新模型路径
void SystemManager::onModelTypeChanged(int index)
{
    if (index >= 0) {
        QString modelType = ui->comboBoxModelSelect->currentText();
        QString cdDataPath = Config::getInstance().getCDDataPath();
        QString modelPath = QDir(cdDataPath).filePath(modelType);
        ui->lineEditModelPath->setText(modelPath);
    }
}

// 清空任务表单
void SystemManager::clearTaskForm()
{
    ui->lineEditTaskName->clear();
    ui->textEditTaskDescription->clear();
    ui->lineEditAssignDescription->clear();
    
    // 清空所有分析类型复选框
    ui->checkBoxDryModalAnalysis->setChecked(false);
    ui->checkBoxWetModalAnalysis->setChecked(false);
    ui->checkBoxStaticAnalysis->setChecked(false);
    ui->checkBoxVibrationAnalysis->setChecked(false);
    ui->checkBoxAcousticAnalysis->setChecked(false);
    
    // 重置下拉框选择
    if (ui->comboBoxModelSelect->count() > 0) {
        ui->comboBoxModelSelect->setCurrentIndex(0);
    }
    if (ui->comboBoxUserSelect->count() > 0) {
        ui->comboBoxUserSelect->setCurrentIndex(0);
    }
}

void SystemManager::onTaskPublishClicked()
{
    // 1. 获取并验证所有必要的输入
    QString taskName = ui->lineEditTaskName->text().trimmed();
    QString workDir = ui->lineEditWorkDir->text();
    QString modelPath = ui->lineEditModelPath->text();
    int assignedTo = ui->comboBoxUserSelect->currentData().toInt();
    QString userName = ui->comboBoxUserSelect->currentText();

    // 2. 验证输入
    if (taskName.isEmpty()) {
        QMessageBox::warning(this, "警告", "请输入任务名称！");
        return;
    }

    if (workDir.isEmpty()) {
        QMessageBox::warning(this, "警告", "请选择工作目录！");
        return;
    }

    if (modelPath.isEmpty()) {
        QMessageBox::warning(this, "警告", "请选择模型文件！");
        return;
    }

    if (assignedTo == 0) {
        QMessageBox::warning(this, "警告", "请选择指派人员！");
        return;
    }

    // 3. 获取分析类型
    QList<Database::TaskAnalysisType> analysisTypes;
    if (ui->checkBoxDryModalAnalysis->isChecked()) {
        Database::TaskAnalysisType type;
        type.analysisType = "干模态分析";
        type.parameters = "{}";
        analysisTypes.append(type);
    }
    if (ui->checkBoxWetModalAnalysis->isChecked()) {
        Database::TaskAnalysisType type;
        type.analysisType = "湿模态分析";
        type.parameters = "{}";
        analysisTypes.append(type);
    }
    if (ui->checkBoxStaticAnalysis->isChecked()) {
        Database::TaskAnalysisType type;
        type.analysisType = "静力学分析";
        type.parameters = "{}";
        analysisTypes.append(type);
    }
    if (ui->checkBoxVibrationAnalysis->isChecked()) {
        Database::TaskAnalysisType type;
        type.analysisType = "振动分析";
        type.parameters = "{}";
        analysisTypes.append(type);
    }
    if (ui->checkBoxAcousticAnalysis->isChecked()) {
        Database::TaskAnalysisType type;
        type.analysisType = "声学分析";
        type.parameters = "{}";
        analysisTypes.append(type);
    }

    if (analysisTypes.isEmpty()) {
        QMessageBox::warning(this, "警告", "请至少选择一种分析类型！");
        return;
    }

    // 4. 创建任务目录
    QString folderName = QString("%1_%2").arg(userName).arg(taskName);
    QDir dir(workDir);
    QString taskDir = dir.filePath(folderName);

    // 检查目录是否已存在
    if (QDir(taskDir).exists()) {
        QMessageBox::warning(this, "警告", "该任务目录已存在！");
        return;
    }

    // 创建任务目录及其子目录
    if (!QDir().mkpath(taskDir)) {
        QMessageBox::critical(this, "错误", "创建任务目录失败！");
        return;
    }

    // 创建分析类型子目录
    QStringList subDirs = {"model", "drymodal/results", "wetmodal/results", 
                          "static/results", "vibration/results", "acoustics/results"};
    for (const QString& subDir : subDirs) {
        if (!QDir().mkpath(QDir(taskDir).filePath(subDir))) {
            QMessageBox::critical(this, "错误", "创建子目录失败！");
            return;
        }
    }

    // 5. 复制模型文件
    if (!copyDirectory(modelPath, QDir(taskDir).filePath("model"))) {
        QMessageBox::critical(this, "错误", "复制模型文件失败！");
        return;
    }
    
    // 6. 创建任务记录
    Database::TaskInfo task;
    task.name = taskName;
    task.description = ui->textEditTaskDescription->toPlainText();
    task.workDir = taskDir;
    task.modelPath = QDir(taskDir).filePath("model");
    task.modelType = ui->comboBoxModelSelect->currentText();
    task.assignedTo = assignedTo;
    task.assignDescription = ui->lineEditAssignDescription->text();
    task.status = 0;  // 待处理
    task.createdBy = 1;  // TODO: 使用当前登录用户ID
    task.createTime = QDateTime::currentDateTime();
    task.updateTime = task.createTime;
    
    // 7. 保存到数据库
    if (Database::getInstance().addTask(task, analysisTypes)) {
        QMessageBox::information(this, "提示", "任务发布成功！");
        clearTaskForm();
        loadTaskList();
    } else {
        QMessageBox::critical(this, "错误", "任务发布失败！");
        // TODO: 清理已创建的目录
    }

    // 复制附件
    QString attachmentPath = ui->lineEditTaskAttachmentPath->text();
    if (!attachmentPath.isEmpty()) {
        // 获取原始文件名
        QFileInfo fileInfo(attachmentPath);
        QString fileName = fileInfo.fileName();
        
        // 在任务目录下创建附件目录
        QString attachmentDir = QDir(taskDir).filePath("attachments");
        QDir().mkpath(attachmentDir);
        
        // 使用原始文件名复制
        QString targetPath = QDir(attachmentDir).filePath(fileName);
        if (!QFile::copy(attachmentPath, targetPath)) {
            QMessageBox::warning(this, "警告", "附件复制失败！");
            return;
        }
    }
}

void SystemManager::onTaskDeleteClicked()
{
    QModelIndex index = ui->tableTaskList->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请先选择一个任务！");
        return;
    }
    
    int row = index.row();
    int taskId = ui->tableTaskList->item(row, 0)->text().toInt();
    QString status = ui->tableTaskList->item(row, 3)->text();
    
    // 只能删除已完成或已取消的任务
    if (status != "已完成" && status != "已取消") {
        QMessageBox::warning(this, "警告", "只能删除已完成或已取消的任务！");
        return;
    }
    
    if (QMessageBox::question(this, "确认", "确定要删除该任务吗？\n注意：任务相关的所有文件也会被删除！",
                            QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) 
    {
        // 1. 获取任务信息
        Database::TaskInfo taskInfo;
        if (!Database::getInstance().getTaskInfo(taskId, taskInfo)) {
            QMessageBox::critical(this, "错误", "获取任务信息失败！");
            return;
        }
        
        // 2. 删除任务目录
        QDir dir(taskInfo.workDir);
        if (dir.exists() && !dir.removeRecursively()) {
            QMessageBox::critical(this, "错误", "删除任务文件失败！");
            return;
        }
        
        // 3. 从数据库删除任务
        if (Database::getInstance().deleteTask(taskId)) {
            QMessageBox::information(this, "提示", "任务删除成功！");
            loadTaskList();
        } else {
            QMessageBox::critical(this, "错误", "任务删除失败！");
        }
    }
}
//声学参数库函数实现
void SystemManager::onSelectAcousticsPath()
{
    QString filePath = QFileDialog::getOpenFileName(
        this,
        "选择声学参数库文件",
        QString(),
        "CSV文件 (*.csv)"
    );
    
    if (!filePath.isEmpty()) {
        m_currentMaterialCSVPath = filePath;
        ui->lineEditCSVPath->setText(filePath);
        loadCSVData(filePath);
        
        // 保存声学参数库CSV文件路径到配置文件
        Config::getInstance().setValue("AcousticsCSV/Path", filePath);
    }
}

void SystemManager::loadAcousticsCSV(const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "错误", "无法打开CSV文件！");
        return;
    }
    
    QTextStream in(&file);
    
    // 读取表头
    QString headerLine = in.readLine();
    QStringList headers = headerLine.split(",");
    
    ui->tableAcoustics->clear();
    ui->tableAcoustics->setColumnCount(headers.size());
    ui->tableAcoustics->setHorizontalHeaderLabels(headers);
    
    // 读取数据
    int row = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        
        ui->tableAcoustics->insertRow(row);
        for (int col = 0; col < fields.size(); ++col) {
            ui->tableAcoustics->setItem(row, col, new QTableWidgetItem(fields[col]));
        }
        row++;
    }
    
    file.close();
    
    // 调整列宽以适应内容
    ui->tableAcoustics->resizeColumnsToContents();
}


// 材料库实现函数实现
void SystemManager::onSelectCSVClicked()
{
    QString filePath = QFileDialog::getOpenFileName(
        this,
        "选择CSV文件",
        QString(),
        "CSV文件 (*.csv)"
    );
    
    if (!filePath.isEmpty()) {
        m_currentMaterialCSVPath = filePath;
        ui->lineEditCSVPath->setText(filePath);
        loadCSVData(filePath);
        
        // 保存CSV文件路径到配置文件
        Config::getInstance().setValue("MaterialCSV/Path", filePath);
    }
}

void SystemManager::loadCSVData(const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "错误", "无法打开CSV文件！");
        return;
    }
    
    QTextStream in(&file);
    
    // 读取表头
    QString headerLine = in.readLine();
    QStringList headers = headerLine.split(",");
    
    ui->tableMaterial->clear();
    ui->tableMaterial->setColumnCount(headers.size());
    ui->tableMaterial->setHorizontalHeaderLabels(headers);
    
    // 读取数据
    int row = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        
        ui->tableMaterial->insertRow(row);
        for (int col = 0; col < fields.size(); ++col) {
            ui->tableMaterial->setItem(row, col, new QTableWidgetItem(fields[col]));
        }
        row++;
    }
    
    file.close();
    
    // 调整列宽以适应内容
    ui->tableMaterial->resizeColumnsToContents();
}

void SystemManager::onSelectLoadPathClicked()
{
    QString path = QFileDialog::getExistingDirectory(
        this,
        "选择载荷库目录",
        QString(),
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
    );
    
    if (!path.isEmpty()) {
        m_currentLoadPath = path;
        ui->lineEditLoadPath->setText(path);
        Config::getInstance().setValue("LoadData/Path", path);
        loadLoadFiles();
    }
}

void SystemManager::loadLoadFiles()
{
    ui->listLoadFiles->clear();
    
    if (m_currentLoadPath.isEmpty()) return;
    
    QDir dir(m_currentLoadPath);
    QStringList filters;
    filters << "*.csv";
    QFileInfoList files = dir.entryInfoList(filters, QDir::Files);
    
    for (const QFileInfo& file : files) {
        ui->listLoadFiles->addItem(file.fileName());
    }
}

void SystemManager::onLoadFileSelected(QListWidgetItem* item)
{
    if (!item) return;
    
    QString filePath = QDir(m_currentLoadPath).filePath(item->text());
    loadLoadData(filePath);
}

void SystemManager::loadLoadData(const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "错误", "无法打开CSV文件！");
        return;
    }
    
    QTextStream in(&file);
    QVector<QPointF> points;
    
    // 读取表头
    QString headerLine = in.readLine();
    QStringList headers = headerLine.split(",");
    
    if (headers.size() != 2) {
        QMessageBox::warning(this, "警告", "CSV文件格式不正确，需要两列数据！");
        file.close();
        return;
    }
    
    ui->tableLoadData->clear();
    ui->tableLoadData->setColumnCount(2);
    ui->tableLoadData->setHorizontalHeaderLabels(headers);
    
    // 读取数据
    int row = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        
        if (fields.size() == 2) {
            bool ok1, ok2;
            double x = fields[0].toDouble(&ok1);
            double y = fields[1].toDouble(&ok2);
            
            if (ok1 && ok2) {
                points.append(QPointF(x, y));
                
                ui->tableLoadData->insertRow(row);
                ui->tableLoadData->setItem(row, 0, new QTableWidgetItem(fields[0]));
                ui->tableLoadData->setItem(row, 1, new QTableWidgetItem(fields[1]));
                row++;
            }
        }
    }
    
    file.close();
    
    // 调整列宽以适应内容
    ui->tableLoadData->resizeColumnsToContents();
    
    // 更新曲线图
    updateLoadChart(points);
}

void SystemManager::updateLoadChart(const QVector<QPointF>& points)
{
    m_loadSeries->clear();
    m_loadSeries->replace(points);
    
    // 自动调整坐标轴范围
    m_loadChart->createDefaultAxes();
    
    // 设置坐标轴标题
    QValueAxis* axisX = qobject_cast<QValueAxis*>(m_loadChart->axes(Qt::Horizontal).first());
    QValueAxis* axisY = qobject_cast<QValueAxis*>(m_loadChart->axes(Qt::Vertical).first());
    if (axisX && axisY) {
        axisX->setTitleText("X轴");
        axisY->setTitleText("Y轴");
    }
}

// 其他槽函数的实现将在后续加... 