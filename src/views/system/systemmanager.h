#pragma once
#include <QMainWindow>

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
    void onTaskPublishClicked();
    void onTaskDeleteClicked();

    // 系统管理相关槽函数
    void onSystemTabChanged(int index);

private:
    void initUI();
    void setupConnections();
    void loadBasicDataTree();
    void loadCDDataTree();
    void loadTaskList();

    Ui::SystemManager* ui;
}; 