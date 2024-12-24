#pragma once
#include <QDialog>
#include <QPair>

namespace Ui {
class UserEditDialog;
}

class UserEditDialog : public QDialog
{
    Q_OBJECT
public:
    explicit UserEditDialog(int userId, QWidget* parent = nullptr);
    ~UserEditDialog();

private slots:
    void onSaveClicked();
    void onCancelClicked();

private:
    void initUI();
    void loadRoles();
    void loadUserInfo();

    Ui::UserEditDialog* ui;
    int m_userId;
}; 