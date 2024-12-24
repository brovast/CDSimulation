#pragma once
#include <QDialog>

namespace Ui {
class ConfigDialog;
}

class ConfigDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ConfigDialog(QWidget* parent = nullptr);
    ~ConfigDialog();

private slots:
    void onBrowseClicked();
    void onSaveClicked();
    void onAddSoftwareClicked();
    void onDeleteSoftwareClicked();

private:
    void loadConfig();
    void saveConfig();

    Ui::ConfigDialog* ui;
}; 