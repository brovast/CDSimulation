#include "dry_modal_analysis_module.h"
#include "ui_dry_modal_analysis_module.h"

DryModalAnalysisModule::DryModalAnalysisModule(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::DryModalAnalysisModule)
{
    ui->setupUi(this);
}

DryModalAnalysisModule::~DryModalAnalysisModule()
{
    delete ui;
} 