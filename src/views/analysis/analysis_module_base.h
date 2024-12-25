#pragma once
#include <QWidget>
#include <QTableWidget>
#include <QTreeView>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>

class AnalysisModuleBase : public QWidget
{
    Q_OBJECT
public:
    explicit AnalysisModuleBase(QWidget* parent = nullptr);
    virtual ~AnalysisModuleBase();

protected:
    // 初始化界面
    virtual void initUI();
    virtual void setupConnections();
    
    // 参数相关
    virtual void initParamsTable() = 0;  // 纯虚函数，子类必须实现
    virtual void loadParamTemplate(const QString& templatePath);
    virtual void saveParamTemplate(const QString& templatePath);
    
    // 分析控制
    virtual void startAnalysis() = 0;    // 纯虚函数，子类必须实现
    virtual void stopAnalysis();
    virtual void clearOutput();
    
    // UI组件
    QGroupBox* m_paramsGroup;
    QTableWidget* m_paramsTable;
    QPushButton* m_loadTemplateBtn;
    QPushButton* m_saveTemplateBtn;
    
    QGroupBox* m_executionGroup;
    QPushButton* m_startBtn;
    QPushButton* m_stopBtn;
    QPushButton* m_clearBtn;
    
    QGroupBox* m_resultsGroup;
    QTreeView* m_resultsTree;

private:
    void createParamsGroup();
    void createExecutionGroup();
    void createResultsGroup();
}; 