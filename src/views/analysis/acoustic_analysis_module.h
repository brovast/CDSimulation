#pragma once
#include <QWidget>

namespace Ui {
class AcousticAnalysisModule;
}

class AcousticAnalysisModule : public QWidget
{
    Q_OBJECT
public:
    explicit AcousticAnalysisModule(QWidget* parent = nullptr);
    ~AcousticAnalysisModule();

private:
    Ui::AcousticAnalysisModule* ui;
}; 