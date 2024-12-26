#pragma once
#include <QWidget>

namespace Ui {
class VibrationAnalysisModule;
}

class VibrationAnalysisModule : public QWidget
{
    Q_OBJECT
public:
    explicit VibrationAnalysisModule(QWidget* parent = nullptr);
    ~VibrationAnalysisModule();

private:
    Ui::VibrationAnalysisModule* ui;
}; 