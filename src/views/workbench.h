#pragma once
#include <QMainWindow>
#include <QTableWidgetItem>
#include "analysis/modal_analysis_module.h"
#include "analysis/static_analysis_module.h"
#include "analysis/vibration_analysis_module.h"
#include "analysis/acoustic_analysis_module.h"
#include "analysis/underwater_analysis_module.h"

namespace Ui {
class Workbench;
}

class Workbench : public QMainWindow
{
    Q_OBJECT
public:
    explicit Workbench(int userId, QWidget* parent = nullptr);
    ~Workbench();

private slots:
    // 任务接收标签页槽函数
    void onTaskFilterChanged();
    void onTaskSearch(const QString& text);
    void onTaskSelectionChanged();
    void onAcceptTaskClicked();
    void onCompleteTaskClicked();

private:
    // 初始化函数
    void initUI();
    void setupConnections();
    
    // 数据加载函数
    void loadTaskList();
    void loadTaskDetails(int taskId);
    void updateTaskStatus(int taskId, int status);
    
    // 辅助函数
    QString getStatusText(int status) const;
    void clearTaskDetails();

    Ui::Workbench* ui;
    int m_userId;  // 当前登录的工程师ID

    // 分析模块
    ModalAnalysisModule* m_modalModule;
    StaticAnalysisModule* m_staticModule;
    VibrationAnalysisModule* m_vibrationModule;
    AcousticAnalysisModule* m_acousticModule;
    UnderwaterAnalysisModule* m_underwaterModule;

    void setupAnalysisModules();
}; 