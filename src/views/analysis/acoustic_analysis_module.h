#pragma once
#include "analysis_module_base.h"

namespace Ui {
class AcousticAnalysisModule;
}

class AcousticAnalysisModule : public AnalysisModuleBase
{
    Q_OBJECT
public:
    explicit AcousticAnalysisModule(QWidget* parent = nullptr);
    ~AcousticAnalysisModule();

protected:
    void initUI() override;
    void initParamsTable() override;
    void startAnalysis() override;
    void stopAnalysis() override;
    void clearOutput() override;

private:
    Ui::AcousticAnalysisModule* ui;
}; 