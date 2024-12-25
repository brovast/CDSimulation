#pragma once
#include <QMainWindow>
#include <QFileSystemModel>
#include <QLabel>
#include <QTextEdit>

// 添加前向声明
class UserManager;
class RoleManager;
class ApprovalManager;

namespace Ui {
class SystemManager;
}

class SystemManager : public QMainWindow
{
    Q_OBJECT
public:
    explicit SystemManager(QWidget* parent = nullptr);
    ~SystemManager();

private slots:
    // 数据管理相关槽函数
    void onBasicDataTreeClicked(const QModelIndex& index);
    void onCDDataTreeClicked(const QModelIndex& index);
    void onNewModelClicked();
    void onAddStructureTypeClicked();
    void onCopyDataClicked();
    void onDeleteClicked();

    // 任务管理相关槽函数
    void onTaskFilterChanged();
    void onTaskSearch(const QString& text);
    void onTaskSelectionChanged();
    void onTaskPublishClicked();
    void onTaskDeleteClicked();
    void onSelectWorkDirClicked();
    void onModelTypeChanged(int index);

    // 系统管理相关槽函数
    void onSystemTabChanged(int index);

    // 基础数据管理相关槽函数
    void onSelectBasicDataPath();
    void onAddBasicFolder();
    void onDeleteBasicData();
    void onBasicDataItemClicked(const QModelIndex& index);

    // 材料库相关槽函数
    void onSelectCSVClicked();
    void loadCSVData(const QString& filePath);

private:
    // 初始化和加载相关
    void initUI();
    void setupConnections();
    void loadBasicDataTree();
    void loadCDDataTree();
    void loadTaskList();
    void loadEngineerList();
    void loadModelTypeList();
    
    // 任务管理相关
    void clearTaskForm();
    
    // 文件操作相关
    void previewBasicDataFile(const QString& filePath);
    bool copyDirectory(const QString& sourcePath, const QString& targetPath);

    // 成员变量
    Ui::SystemManager* ui;
    QFileSystemModel* m_basicDataModel;
    QString m_currentBasicDataPath;
    QString m_currentMaterialCSVPath;  // 保存当前材料库CSV文件路径
}; 