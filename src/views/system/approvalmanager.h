#pragma once
#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class ApprovalManager;
}

class ApprovalManager : public QWidget
{
    Q_OBJECT
public:
    explicit ApprovalManager(QWidget* parent = nullptr);
    ~ApprovalManager();

private slots:
    void onApproveClicked();
    void onRejectClicked();
    void onRefreshClicked();
    void onFilterChanged(int index);

private:
    void initUI();
    void setupConnections();
    void loadApprovalList();

    Ui::ApprovalManager* ui;
    QStandardItemModel* m_approvalModel;
}; 