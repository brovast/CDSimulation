#pragma once
#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class UserManager;
}

class UserManager : public QWidget
{
    Q_OBJECT
public:
    explicit UserManager(QWidget* parent = nullptr);
    ~UserManager();

private slots:
    void onRefreshClicked();
    void onEditClicked();
    void onDeleteClicked();
    void onApproveClicked();
    void onRejectClicked();

private:
    void initUI();
    void setupConnections();
    void loadUserList();
    void loadRoleComboBox();

    Ui::UserManager* ui;
    QStandardItemModel* m_userModel;
}; 