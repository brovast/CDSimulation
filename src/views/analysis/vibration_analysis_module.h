#pragma once
#include "analysis_module_base.h"

namespace Ui {
class VibrationAnalysisModule;
}

class VibrationAnalysisModule : public AnalysisModuleBase
{
    Q_OBJECT
public:
    explicit VibrationAnalysisModule(QWidget* parent = nullptr);
    ~VibrationAnalysisModule();

protected:
    void initUI() override;
    void initParamsTable() override;
    void startAnalysis() override;
    void stopAnalysis() override;
    void clearOutput() override;

private:
    Ui::VibrationAnalysisModule* ui;
}; 