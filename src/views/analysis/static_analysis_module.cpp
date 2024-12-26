#include "static_analysis_module.h"
#include "ui_static_analysis_module.h"

StaticAnalysisModule::StaticAnalysisModule(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::StaticAnalysisModule)
{
    ui->setupUi(this);
}

StaticAnalysisModule::~StaticAnalysisModule()
{
    delete ui;
} 