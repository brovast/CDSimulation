#pragma once
#include <QWidget>

namespace Ui {
class StaticAnalysisModule;
}

class StaticAnalysisModule : public QWidget
{
    Q_OBJECT
public:
    explicit StaticAnalysisModule(QWidget* parent = nullptr);
    ~StaticAnalysisModule();

private:
    Ui::StaticAnalysisModule* ui;
}; 