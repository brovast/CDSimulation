#pragma once
#include <QMainWindow>
#include <QFileSystemModel>
#include <QLabel>
#include <QTextEdit>
#include <QtCharts>
#include <QChart>
#include <QLineSeries>
#include <QValueAxis>

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

    // 载荷库相关槽函数
    void onSelectLoadPathClicked();  // 选择载荷库路径
    void onLoadFileSelected(QListWidgetItem* item);  // 文件列表选择改变

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
    QString m_currentLoadPath;  // 当前载荷库路径
    QChart* m_loadChart;  // 载荷曲线图
    QLineSeries* m_loadSeries;  // 载荷数据序列

    // 基础数据管理相关槽函数
    void loadLoadFiles();  // 加载文件列表
    void loadLoadData(const QString& filePath);  // 加载CSV数据
    void updateLoadChart(const QVector<QPointF>& points);  // 更新曲线图
}; 