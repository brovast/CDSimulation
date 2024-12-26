#pragma once
#include <QWidget>

namespace Ui {
class DryModalAnalysisModule;
}

class DryModalAnalysisModule : public QWidget
{
    Q_OBJECT
public:
    explicit DryModalAnalysisModule(QWidget* parent = nullptr);
    ~DryModalAnalysisModule();

private:
    Ui::DryModalAnalysisModule* ui;
}; 