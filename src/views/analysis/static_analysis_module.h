#pragma once
#include "analysis_module_base.h"

namespace Ui {
class StaticAnalysisModule;
}

class StaticAnalysisModule : public AnalysisModuleBase
{
    Q_OBJECT
public:
    explicit StaticAnalysisModule(QWidget* parent = nullptr);
    ~StaticAnalysisModule();

protected:
    void initUI() override;
    void initParamsTable() override;
    void startAnalysis() override;
    void stopAnalysis() override;
    void clearOutput() override;

private:
    Ui::StaticAnalysisModule* ui;
}; 