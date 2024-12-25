#pragma once
#include "analysis_module_base.h"

namespace Ui {
class UnderwaterAnalysisModule;
}

class UnderwaterAnalysisModule : public AnalysisModuleBase
{
    Q_OBJECT
public:
    explicit UnderwaterAnalysisModule(QWidget* parent = nullptr);
    ~UnderwaterAnalysisModule();

protected:
    void initUI() override;
    void initParamsTable() override;
    void startAnalysis() override;
    void stopAnalysis() override;
    void clearOutput() override;

private:
    Ui::UnderwaterAnalysisModule* ui;
}; 