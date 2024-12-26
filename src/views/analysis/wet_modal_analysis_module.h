#pragma once
#include <QWidget>

namespace Ui {
class WetModalAnalysisModule;
}

class WetModalAnalysisModule : public QWidget
{
    Q_OBJECT
public:
    explicit WetModalAnalysisModule(QWidget* parent = nullptr);
    ~WetModalAnalysisModule();

private:
    Ui::WetModalAnalysisModule* ui;
}; 