#pragma once
#include "analysis_module_base.h"

namespace Ui {
class ModalAnalysisModule;
}

class ModalAnalysisModule : public AnalysisModuleBase
{
    Q_OBJECT
public:
    explicit ModalAnalysisModule(QWidget* parent = nullptr);
    ~ModalAnalysisModule();

protected:
    void initUI() override;
    void initParamsTable() override;
    void startAnalysis() override;
    void stopAnalysis() override;
    void clearOutput() override;

private:
    Ui::ModalAnalysisModule* ui;
}; 