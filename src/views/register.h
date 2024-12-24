#pragma once
#include <QDialog>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT
public:
    explicit Register(QWidget* parent = nullptr);
    ~Register();

private slots:
    void onRegisterClicked();
    void onCancelClicked();

private:
    Ui::Register* ui;
}; 