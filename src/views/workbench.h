#pragma once
#include <QMainWindow>

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
    void onTaskDoubleClicked(const QModelIndex& index);
    void onTaskStatusChanged(int status);
    void onRefreshClicked();

private:
    void initUI();
    void setupConnections();
    void loadTasks();
    void loadTaskDetails(int taskId);

    Ui::Workbench* ui;
    int m_userId;
}; 