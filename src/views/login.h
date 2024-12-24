#pragma once
#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT
public:
    explicit Login(QWidget* parent = nullptr);
    ~Login();

private slots:
    void onLoginClicked();
    void onRegisterClicked();
    void onConfigClicked();

private:
    Ui::Login* ui;
}; 