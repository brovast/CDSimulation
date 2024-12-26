#include "wet_modal_analysis_module.h"
#include "ui_wet_modal_analysis_module.h"

WetModalAnalysisModule::WetModalAnalysisModule(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::WetModalAnalysisModule)
{
    ui->setupUi(this);
}

WetModalAnalysisModule::~WetModalAnalysisModule()
{
    delete ui;
} 