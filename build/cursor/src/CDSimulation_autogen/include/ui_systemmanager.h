/********************************************************************************
** Form generated from reading UI file 'systemmanager.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMMANAGER_H
#define UI_SYSTEMMANAGER_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "views/system/approvalmanager.h"
#include "views/system/rolemanager.h"
#include "views/system/usermanager.h"

QT_BEGIN_NAMESPACE

class Ui_SystemManager
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidgetMain;
    QWidget *tabDataManage;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidgetDataManage;
    QWidget *tabBasicData;
    QVBoxLayout *verticalLayout_basic;
    QHBoxLayout *horizontalLayout_path;
    QLabel *labelBasicDataPath;
    QLineEdit *lineEditBasicDataPath;
    QPushButton *btnSelectBasicDataPath;
    QHBoxLayout *horizontalLayout_content;
    QVBoxLayout *verticalLayout_tree;
    QTreeView *treeViewBasicData;
    QHBoxLayout *horizontalLayout_buttons;
    QPushButton *btnAddBasicFolder;
    QPushButton *btnDeleteBasicData;
    QVBoxLayout *verticalLayout_preview;
    QLabel *labelImagePreview;
    QTextEdit *textEditContentPreview;
    QLabel *labelAttachment;
    QHBoxLayout *horizontalLayout_attachment;
    QLineEdit *lineEditAttachmentPath;
    QPushButton *btnSelectAttachment;
    QWidget *tabCompartmentData;
    QVBoxLayout *verticalLayout_cd;
    QHBoxLayout *horizontalLayout_cdpath;
    QLabel *labelCDDataPath;
    QLineEdit *lineEditCDDataPath;
    QPushButton *btnSelectCDDataPath;
    QHBoxLayout *horizontalLayout_2;
    QTreeView *treeViewCDBasicData;
    QVBoxLayout *verticalLayout_4;
    QTreeView *treeViewCDData;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnNewModel;
    QPushButton *btnAddStructureType;
    QPushButton *btnCopyData;
    QPushButton *btnDelete;
    QWidget *tabUnderwaterData;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_csv_2;
    QLabel *labelAcousticsPath;
    QLineEdit *lineEditAcousticsPath;
    QPushButton *btnSelectAcousticsCSV;
    QTableWidget *tableAcoustics;
    QWidget *tabMaterialData;
    QVBoxLayout *verticalLayout_material;
    QHBoxLayout *horizontalLayout_csv;
    QLabel *labelCSVPath;
    QLineEdit *lineEditCSVPath;
    QPushButton *btnSelectCSV;
    QTableWidget *tableMaterial;
    QWidget *tabLoadData;
    QHBoxLayout *horizontalLayout_load;
    QVBoxLayout *verticalLayout_load_left;
    QHBoxLayout *horizontalLayout_load_path;
    QLabel *labelLoadPath;
    QLineEdit *lineEditLoadPath;
    QPushButton *btnSelectLoadPath;
    QListWidget *listLoadFiles;
    QTableWidget *tableLoadData;
    QChartView *chartLoadView;
    QWidget *tabTaskManage;
    QVBoxLayout *verticalLayout_task;
    QHBoxLayout *horizontalLayout_filter;
    QLabel *labelStatus;
    QComboBox *comboBoxStatusFilter;
    QLabel *labelType;
    QComboBox *comboBoxTypeFilter;
    QLineEdit *lineEditSearch;
    QSpacerItem *horizontalSpacer_task;
    QTableWidget *tableTaskList;
    QSplitter *splitterTask;
    QWidget *widgetTaskDefine;
    QVBoxLayout *verticalLayout_taskDefine;
    QGroupBox *groupBoxBasicInfo;
    QFormLayout *formLayout_basic;
    QLabel *labelTaskName;
    QLineEdit *lineEditTaskName;
    QLabel *labelWorkDir;
    QHBoxLayout *horizontalLayout_workDir;
    QLineEdit *lineEditWorkDir;
    QPushButton *btnSelectWorkDir;
    QLabel *labelTaskDesc;
    QTextEdit *textEditTaskDescription;
    QLabel *labelTaskAttachment;
    QHBoxLayout *horizontalLayout_taskAttachment;
    QLineEdit *lineEditTaskAttachmentPath;
    QPushButton *btnSelectTaskAttachment;
    QGroupBox *groupBoxModel;
    QFormLayout *formLayout_model;
    QLabel *labelModelType;
    QComboBox *comboBoxModelSelect;
    QLabel *labelModelPath;
    QLineEdit *lineEditModelPath;
    QGroupBox *groupBoxAnalysisType;
    QHBoxLayout *horizontalLayout_analysis;
    QCheckBox *checkBoxDryModalAnalysis;
    QCheckBox *checkBoxWetModalAnalysis;
    QCheckBox *checkBoxStaticAnalysis;
    QCheckBox *checkBoxVibrationAnalysis;
    QCheckBox *checkBoxAcousticAnalysis;
    QGroupBox *groupBoxAssign;
    QFormLayout *formLayout_assign;
    QLabel *labelAssignTo;
    QComboBox *comboBoxUserSelect;
    QLabel *labelAssignDesc;
    QLineEdit *lineEditAssignDescription;
    QHBoxLayout *horizontalLayout_buttons1;
    QSpacerItem *horizontalSpacer_buttons;
    QPushButton *btnTaskPublish;
    QPushButton *btnTaskDelete;
    QWidget *tabSystemManage;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tabWidgetSystemManage;
    QWidget *tabUserManage;
    QVBoxLayout *verticalLayout_6;
    UserManager *widgetUserManager;
    QWidget *tabRoleManage;
    QVBoxLayout *verticalLayout_7;
    RoleManager *widgetRoleManager;
    QWidget *tabApprovalManage;
    QVBoxLayout *verticalLayout_8;
    ApprovalManager *widgetApprovalManager;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SystemManager)
    {
        if (SystemManager->objectName().isEmpty())
            SystemManager->setObjectName("SystemManager");
        SystemManager->resize(1200, 934);
        centralwidget = new QWidget(SystemManager);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidgetMain = new QTabWidget(centralwidget);
        tabWidgetMain->setObjectName("tabWidgetMain");
        tabDataManage = new QWidget();
        tabDataManage->setObjectName("tabDataManage");
        verticalLayout_2 = new QVBoxLayout(tabDataManage);
        verticalLayout_2->setObjectName("verticalLayout_2");
        tabWidgetDataManage = new QTabWidget(tabDataManage);
        tabWidgetDataManage->setObjectName("tabWidgetDataManage");
        tabBasicData = new QWidget();
        tabBasicData->setObjectName("tabBasicData");
        verticalLayout_basic = new QVBoxLayout(tabBasicData);
        verticalLayout_basic->setObjectName("verticalLayout_basic");
        horizontalLayout_path = new QHBoxLayout();
        horizontalLayout_path->setObjectName("horizontalLayout_path");
        labelBasicDataPath = new QLabel(tabBasicData);
        labelBasicDataPath->setObjectName("labelBasicDataPath");

        horizontalLayout_path->addWidget(labelBasicDataPath);

        lineEditBasicDataPath = new QLineEdit(tabBasicData);
        lineEditBasicDataPath->setObjectName("lineEditBasicDataPath");
        lineEditBasicDataPath->setReadOnly(true);

        horizontalLayout_path->addWidget(lineEditBasicDataPath);

        btnSelectBasicDataPath = new QPushButton(tabBasicData);
        btnSelectBasicDataPath->setObjectName("btnSelectBasicDataPath");

        horizontalLayout_path->addWidget(btnSelectBasicDataPath);


        verticalLayout_basic->addLayout(horizontalLayout_path);

        horizontalLayout_content = new QHBoxLayout();
        horizontalLayout_content->setObjectName("horizontalLayout_content");
        verticalLayout_tree = new QVBoxLayout();
        verticalLayout_tree->setObjectName("verticalLayout_tree");
        treeViewBasicData = new QTreeView(tabBasicData);
        treeViewBasicData->setObjectName("treeViewBasicData");

        verticalLayout_tree->addWidget(treeViewBasicData);

        horizontalLayout_buttons = new QHBoxLayout();
        horizontalLayout_buttons->setObjectName("horizontalLayout_buttons");
        btnAddBasicFolder = new QPushButton(tabBasicData);
        btnAddBasicFolder->setObjectName("btnAddBasicFolder");

        horizontalLayout_buttons->addWidget(btnAddBasicFolder);

        btnDeleteBasicData = new QPushButton(tabBasicData);
        btnDeleteBasicData->setObjectName("btnDeleteBasicData");

        horizontalLayout_buttons->addWidget(btnDeleteBasicData);


        verticalLayout_tree->addLayout(horizontalLayout_buttons);


        horizontalLayout_content->addLayout(verticalLayout_tree);

        verticalLayout_preview = new QVBoxLayout();
        verticalLayout_preview->setObjectName("verticalLayout_preview");
        labelImagePreview = new QLabel(tabBasicData);
        labelImagePreview->setObjectName("labelImagePreview");
        labelImagePreview->setMinimumSize(QSize(400, 300));
        labelImagePreview->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_preview->addWidget(labelImagePreview);

        textEditContentPreview = new QTextEdit(tabBasicData);
        textEditContentPreview->setObjectName("textEditContentPreview");
        textEditContentPreview->setReadOnly(true);

        verticalLayout_preview->addWidget(textEditContentPreview);


        horizontalLayout_content->addLayout(verticalLayout_preview);


        verticalLayout_basic->addLayout(horizontalLayout_content);

        labelAttachment = new QLabel(tabBasicData);
        labelAttachment->setObjectName("labelAttachment");

        verticalLayout_basic->addWidget(labelAttachment);

        horizontalLayout_attachment = new QHBoxLayout();
        horizontalLayout_attachment->setObjectName("horizontalLayout_attachment");
        lineEditAttachmentPath = new QLineEdit(tabBasicData);
        lineEditAttachmentPath->setObjectName("lineEditAttachmentPath");
        lineEditAttachmentPath->setReadOnly(true);

        horizontalLayout_attachment->addWidget(lineEditAttachmentPath);

        btnSelectAttachment = new QPushButton(tabBasicData);
        btnSelectAttachment->setObjectName("btnSelectAttachment");

        horizontalLayout_attachment->addWidget(btnSelectAttachment);


        verticalLayout_basic->addLayout(horizontalLayout_attachment);

        tabWidgetDataManage->addTab(tabBasicData, QString());
        tabCompartmentData = new QWidget();
        tabCompartmentData->setObjectName("tabCompartmentData");
        verticalLayout_cd = new QVBoxLayout(tabCompartmentData);
        verticalLayout_cd->setObjectName("verticalLayout_cd");
        horizontalLayout_cdpath = new QHBoxLayout();
        horizontalLayout_cdpath->setObjectName("horizontalLayout_cdpath");
        labelCDDataPath = new QLabel(tabCompartmentData);
        labelCDDataPath->setObjectName("labelCDDataPath");

        horizontalLayout_cdpath->addWidget(labelCDDataPath);

        lineEditCDDataPath = new QLineEdit(tabCompartmentData);
        lineEditCDDataPath->setObjectName("lineEditCDDataPath");
        lineEditCDDataPath->setReadOnly(true);

        horizontalLayout_cdpath->addWidget(lineEditCDDataPath);

        btnSelectCDDataPath = new QPushButton(tabCompartmentData);
        btnSelectCDDataPath->setObjectName("btnSelectCDDataPath");

        horizontalLayout_cdpath->addWidget(btnSelectCDDataPath);


        verticalLayout_cd->addLayout(horizontalLayout_cdpath);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        treeViewCDBasicData = new QTreeView(tabCompartmentData);
        treeViewCDBasicData->setObjectName("treeViewCDBasicData");

        horizontalLayout_2->addWidget(treeViewCDBasicData);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        treeViewCDData = new QTreeView(tabCompartmentData);
        treeViewCDData->setObjectName("treeViewCDData");

        verticalLayout_4->addWidget(treeViewCDData);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        btnNewModel = new QPushButton(tabCompartmentData);
        btnNewModel->setObjectName("btnNewModel");

        horizontalLayout_3->addWidget(btnNewModel);

        btnAddStructureType = new QPushButton(tabCompartmentData);
        btnAddStructureType->setObjectName("btnAddStructureType");

        horizontalLayout_3->addWidget(btnAddStructureType);

        btnCopyData = new QPushButton(tabCompartmentData);
        btnCopyData->setObjectName("btnCopyData");

        horizontalLayout_3->addWidget(btnCopyData);

        btnDelete = new QPushButton(tabCompartmentData);
        btnDelete->setObjectName("btnDelete");

        horizontalLayout_3->addWidget(btnDelete);


        verticalLayout_4->addLayout(horizontalLayout_3);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout_cd->addLayout(horizontalLayout_2);

        tabWidgetDataManage->addTab(tabCompartmentData, QString());
        tabUnderwaterData = new QWidget();
        tabUnderwaterData->setObjectName("tabUnderwaterData");
        gridLayout = new QGridLayout(tabUnderwaterData);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_csv_2 = new QHBoxLayout();
        horizontalLayout_csv_2->setObjectName("horizontalLayout_csv_2");
        labelAcousticsPath = new QLabel(tabUnderwaterData);
        labelAcousticsPath->setObjectName("labelAcousticsPath");

        horizontalLayout_csv_2->addWidget(labelAcousticsPath);

        lineEditAcousticsPath = new QLineEdit(tabUnderwaterData);
        lineEditAcousticsPath->setObjectName("lineEditAcousticsPath");
        lineEditAcousticsPath->setReadOnly(true);

        horizontalLayout_csv_2->addWidget(lineEditAcousticsPath);

        btnSelectAcousticsCSV = new QPushButton(tabUnderwaterData);
        btnSelectAcousticsCSV->setObjectName("btnSelectAcousticsCSV");

        horizontalLayout_csv_2->addWidget(btnSelectAcousticsCSV);


        gridLayout->addLayout(horizontalLayout_csv_2, 0, 0, 1, 1);

        tableAcoustics = new QTableWidget(tabUnderwaterData);
        tableAcoustics->setObjectName("tableAcoustics");

        gridLayout->addWidget(tableAcoustics, 1, 0, 1, 1);

        tabWidgetDataManage->addTab(tabUnderwaterData, QString());
        tabMaterialData = new QWidget();
        tabMaterialData->setObjectName("tabMaterialData");
        verticalLayout_material = new QVBoxLayout(tabMaterialData);
        verticalLayout_material->setObjectName("verticalLayout_material");
        horizontalLayout_csv = new QHBoxLayout();
        horizontalLayout_csv->setObjectName("horizontalLayout_csv");
        labelCSVPath = new QLabel(tabMaterialData);
        labelCSVPath->setObjectName("labelCSVPath");

        horizontalLayout_csv->addWidget(labelCSVPath);

        lineEditCSVPath = new QLineEdit(tabMaterialData);
        lineEditCSVPath->setObjectName("lineEditCSVPath");
        lineEditCSVPath->setReadOnly(true);

        horizontalLayout_csv->addWidget(lineEditCSVPath);

        btnSelectCSV = new QPushButton(tabMaterialData);
        btnSelectCSV->setObjectName("btnSelectCSV");

        horizontalLayout_csv->addWidget(btnSelectCSV);


        verticalLayout_material->addLayout(horizontalLayout_csv);

        tableMaterial = new QTableWidget(tabMaterialData);
        tableMaterial->setObjectName("tableMaterial");

        verticalLayout_material->addWidget(tableMaterial);

        tabWidgetDataManage->addTab(tabMaterialData, QString());
        tabLoadData = new QWidget();
        tabLoadData->setObjectName("tabLoadData");
        horizontalLayout_load = new QHBoxLayout(tabLoadData);
        horizontalLayout_load->setObjectName("horizontalLayout_load");
        verticalLayout_load_left = new QVBoxLayout();
        verticalLayout_load_left->setObjectName("verticalLayout_load_left");
        horizontalLayout_load_path = new QHBoxLayout();
        horizontalLayout_load_path->setObjectName("horizontalLayout_load_path");
        labelLoadPath = new QLabel(tabLoadData);
        labelLoadPath->setObjectName("labelLoadPath");

        horizontalLayout_load_path->addWidget(labelLoadPath);

        lineEditLoadPath = new QLineEdit(tabLoadData);
        lineEditLoadPath->setObjectName("lineEditLoadPath");
        lineEditLoadPath->setReadOnly(true);

        horizontalLayout_load_path->addWidget(lineEditLoadPath);

        btnSelectLoadPath = new QPushButton(tabLoadData);
        btnSelectLoadPath->setObjectName("btnSelectLoadPath");

        horizontalLayout_load_path->addWidget(btnSelectLoadPath);


        verticalLayout_load_left->addLayout(horizontalLayout_load_path);

        listLoadFiles = new QListWidget(tabLoadData);
        listLoadFiles->setObjectName("listLoadFiles");

        verticalLayout_load_left->addWidget(listLoadFiles);


        horizontalLayout_load->addLayout(verticalLayout_load_left);

        tableLoadData = new QTableWidget(tabLoadData);
        tableLoadData->setObjectName("tableLoadData");

        horizontalLayout_load->addWidget(tableLoadData);

        chartLoadView = new QChartView(tabLoadData);
        chartLoadView->setObjectName("chartLoadView");

        horizontalLayout_load->addWidget(chartLoadView);

        tabWidgetDataManage->addTab(tabLoadData, QString());

        verticalLayout_2->addWidget(tabWidgetDataManage);

        tabWidgetMain->addTab(tabDataManage, QString());
        tabTaskManage = new QWidget();
        tabTaskManage->setObjectName("tabTaskManage");
        verticalLayout_task = new QVBoxLayout(tabTaskManage);
        verticalLayout_task->setObjectName("verticalLayout_task");
        horizontalLayout_filter = new QHBoxLayout();
        horizontalLayout_filter->setObjectName("horizontalLayout_filter");
        labelStatus = new QLabel(tabTaskManage);
        labelStatus->setObjectName("labelStatus");

        horizontalLayout_filter->addWidget(labelStatus);

        comboBoxStatusFilter = new QComboBox(tabTaskManage);
        comboBoxStatusFilter->addItem(QString());
        comboBoxStatusFilter->addItem(QString());
        comboBoxStatusFilter->addItem(QString());
        comboBoxStatusFilter->addItem(QString());
        comboBoxStatusFilter->addItem(QString());
        comboBoxStatusFilter->setObjectName("comboBoxStatusFilter");

        horizontalLayout_filter->addWidget(comboBoxStatusFilter);

        labelType = new QLabel(tabTaskManage);
        labelType->setObjectName("labelType");

        horizontalLayout_filter->addWidget(labelType);

        comboBoxTypeFilter = new QComboBox(tabTaskManage);
        comboBoxTypeFilter->addItem(QString());
        comboBoxTypeFilter->addItem(QString());
        comboBoxTypeFilter->addItem(QString());
        comboBoxTypeFilter->addItem(QString());
        comboBoxTypeFilter->setObjectName("comboBoxTypeFilter");

        horizontalLayout_filter->addWidget(comboBoxTypeFilter);

        lineEditSearch = new QLineEdit(tabTaskManage);
        lineEditSearch->setObjectName("lineEditSearch");

        horizontalLayout_filter->addWidget(lineEditSearch);

        horizontalSpacer_task = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_filter->addItem(horizontalSpacer_task);


        verticalLayout_task->addLayout(horizontalLayout_filter);

        tableTaskList = new QTableWidget(tabTaskManage);
        if (tableTaskList->columnCount() < 6)
            tableTaskList->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableTaskList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableTaskList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableTaskList->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableTaskList->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableTaskList->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableTaskList->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableTaskList->setObjectName("tableTaskList");
        tableTaskList->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tableTaskList->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        verticalLayout_task->addWidget(tableTaskList);

        splitterTask = new QSplitter(tabTaskManage);
        splitterTask->setObjectName("splitterTask");
        splitterTask->setOrientation(Qt::Orientation::Vertical);
        widgetTaskDefine = new QWidget(splitterTask);
        widgetTaskDefine->setObjectName("widgetTaskDefine");
        verticalLayout_taskDefine = new QVBoxLayout(widgetTaskDefine);
        verticalLayout_taskDefine->setObjectName("verticalLayout_taskDefine");
        verticalLayout_taskDefine->setContentsMargins(0, 0, 0, 0);
        groupBoxBasicInfo = new QGroupBox(widgetTaskDefine);
        groupBoxBasicInfo->setObjectName("groupBoxBasicInfo");
        formLayout_basic = new QFormLayout(groupBoxBasicInfo);
        formLayout_basic->setObjectName("formLayout_basic");
        labelTaskName = new QLabel(groupBoxBasicInfo);
        labelTaskName->setObjectName("labelTaskName");

        formLayout_basic->setWidget(0, QFormLayout::LabelRole, labelTaskName);

        lineEditTaskName = new QLineEdit(groupBoxBasicInfo);
        lineEditTaskName->setObjectName("lineEditTaskName");

        formLayout_basic->setWidget(0, QFormLayout::FieldRole, lineEditTaskName);

        labelWorkDir = new QLabel(groupBoxBasicInfo);
        labelWorkDir->setObjectName("labelWorkDir");

        formLayout_basic->setWidget(1, QFormLayout::LabelRole, labelWorkDir);

        horizontalLayout_workDir = new QHBoxLayout();
        horizontalLayout_workDir->setObjectName("horizontalLayout_workDir");
        lineEditWorkDir = new QLineEdit(groupBoxBasicInfo);
        lineEditWorkDir->setObjectName("lineEditWorkDir");
        lineEditWorkDir->setReadOnly(true);

        horizontalLayout_workDir->addWidget(lineEditWorkDir);

        btnSelectWorkDir = new QPushButton(groupBoxBasicInfo);
        btnSelectWorkDir->setObjectName("btnSelectWorkDir");

        horizontalLayout_workDir->addWidget(btnSelectWorkDir);


        formLayout_basic->setLayout(1, QFormLayout::FieldRole, horizontalLayout_workDir);

        labelTaskDesc = new QLabel(groupBoxBasicInfo);
        labelTaskDesc->setObjectName("labelTaskDesc");

        formLayout_basic->setWidget(2, QFormLayout::LabelRole, labelTaskDesc);

        textEditTaskDescription = new QTextEdit(groupBoxBasicInfo);
        textEditTaskDescription->setObjectName("textEditTaskDescription");

        formLayout_basic->setWidget(2, QFormLayout::FieldRole, textEditTaskDescription);

        labelTaskAttachment = new QLabel(groupBoxBasicInfo);
        labelTaskAttachment->setObjectName("labelTaskAttachment");

        formLayout_basic->setWidget(3, QFormLayout::LabelRole, labelTaskAttachment);

        horizontalLayout_taskAttachment = new QHBoxLayout();
        horizontalLayout_taskAttachment->setObjectName("horizontalLayout_taskAttachment");
        lineEditTaskAttachmentPath = new QLineEdit(groupBoxBasicInfo);
        lineEditTaskAttachmentPath->setObjectName("lineEditTaskAttachmentPath");
        lineEditTaskAttachmentPath->setReadOnly(true);

        horizontalLayout_taskAttachment->addWidget(lineEditTaskAttachmentPath);

        btnSelectTaskAttachment = new QPushButton(groupBoxBasicInfo);
        btnSelectTaskAttachment->setObjectName("btnSelectTaskAttachment");

        horizontalLayout_taskAttachment->addWidget(btnSelectTaskAttachment);


        formLayout_basic->setLayout(3, QFormLayout::FieldRole, horizontalLayout_taskAttachment);


        verticalLayout_taskDefine->addWidget(groupBoxBasicInfo);

        groupBoxModel = new QGroupBox(widgetTaskDefine);
        groupBoxModel->setObjectName("groupBoxModel");
        formLayout_model = new QFormLayout(groupBoxModel);
        formLayout_model->setObjectName("formLayout_model");
        labelModelType = new QLabel(groupBoxModel);
        labelModelType->setObjectName("labelModelType");

        formLayout_model->setWidget(0, QFormLayout::LabelRole, labelModelType);

        comboBoxModelSelect = new QComboBox(groupBoxModel);
        comboBoxModelSelect->setObjectName("comboBoxModelSelect");

        formLayout_model->setWidget(0, QFormLayout::FieldRole, comboBoxModelSelect);

        labelModelPath = new QLabel(groupBoxModel);
        labelModelPath->setObjectName("labelModelPath");

        formLayout_model->setWidget(1, QFormLayout::LabelRole, labelModelPath);

        lineEditModelPath = new QLineEdit(groupBoxModel);
        lineEditModelPath->setObjectName("lineEditModelPath");
        lineEditModelPath->setReadOnly(true);

        formLayout_model->setWidget(1, QFormLayout::FieldRole, lineEditModelPath);


        verticalLayout_taskDefine->addWidget(groupBoxModel);

        groupBoxAnalysisType = new QGroupBox(widgetTaskDefine);
        groupBoxAnalysisType->setObjectName("groupBoxAnalysisType");
        horizontalLayout_analysis = new QHBoxLayout(groupBoxAnalysisType);
        horizontalLayout_analysis->setObjectName("horizontalLayout_analysis");
        checkBoxDryModalAnalysis = new QCheckBox(groupBoxAnalysisType);
        checkBoxDryModalAnalysis->setObjectName("checkBoxDryModalAnalysis");

        horizontalLayout_analysis->addWidget(checkBoxDryModalAnalysis);

        checkBoxWetModalAnalysis = new QCheckBox(groupBoxAnalysisType);
        checkBoxWetModalAnalysis->setObjectName("checkBoxWetModalAnalysis");

        horizontalLayout_analysis->addWidget(checkBoxWetModalAnalysis);

        checkBoxStaticAnalysis = new QCheckBox(groupBoxAnalysisType);
        checkBoxStaticAnalysis->setObjectName("checkBoxStaticAnalysis");

        horizontalLayout_analysis->addWidget(checkBoxStaticAnalysis);

        checkBoxVibrationAnalysis = new QCheckBox(groupBoxAnalysisType);
        checkBoxVibrationAnalysis->setObjectName("checkBoxVibrationAnalysis");

        horizontalLayout_analysis->addWidget(checkBoxVibrationAnalysis);

        checkBoxAcousticAnalysis = new QCheckBox(groupBoxAnalysisType);
        checkBoxAcousticAnalysis->setObjectName("checkBoxAcousticAnalysis");

        horizontalLayout_analysis->addWidget(checkBoxAcousticAnalysis);


        verticalLayout_taskDefine->addWidget(groupBoxAnalysisType);

        groupBoxAssign = new QGroupBox(widgetTaskDefine);
        groupBoxAssign->setObjectName("groupBoxAssign");
        formLayout_assign = new QFormLayout(groupBoxAssign);
        formLayout_assign->setObjectName("formLayout_assign");
        labelAssignTo = new QLabel(groupBoxAssign);
        labelAssignTo->setObjectName("labelAssignTo");

        formLayout_assign->setWidget(0, QFormLayout::LabelRole, labelAssignTo);

        comboBoxUserSelect = new QComboBox(groupBoxAssign);
        comboBoxUserSelect->setObjectName("comboBoxUserSelect");

        formLayout_assign->setWidget(0, QFormLayout::FieldRole, comboBoxUserSelect);

        labelAssignDesc = new QLabel(groupBoxAssign);
        labelAssignDesc->setObjectName("labelAssignDesc");

        formLayout_assign->setWidget(1, QFormLayout::LabelRole, labelAssignDesc);

        lineEditAssignDescription = new QLineEdit(groupBoxAssign);
        lineEditAssignDescription->setObjectName("lineEditAssignDescription");

        formLayout_assign->setWidget(1, QFormLayout::FieldRole, lineEditAssignDescription);


        verticalLayout_taskDefine->addWidget(groupBoxAssign);

        horizontalLayout_buttons1 = new QHBoxLayout();
        horizontalLayout_buttons1->setObjectName("horizontalLayout_buttons1");
        horizontalSpacer_buttons = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_buttons1->addItem(horizontalSpacer_buttons);

        btnTaskPublish = new QPushButton(widgetTaskDefine);
        btnTaskPublish->setObjectName("btnTaskPublish");

        horizontalLayout_buttons1->addWidget(btnTaskPublish);

        btnTaskDelete = new QPushButton(widgetTaskDefine);
        btnTaskDelete->setObjectName("btnTaskDelete");

        horizontalLayout_buttons1->addWidget(btnTaskDelete);


        verticalLayout_taskDefine->addLayout(horizontalLayout_buttons1);

        splitterTask->addWidget(widgetTaskDefine);

        verticalLayout_task->addWidget(splitterTask);

        tabWidgetMain->addTab(tabTaskManage, QString());
        tabSystemManage = new QWidget();
        tabSystemManage->setObjectName("tabSystemManage");
        verticalLayout_5 = new QVBoxLayout(tabSystemManage);
        verticalLayout_5->setObjectName("verticalLayout_5");
        tabWidgetSystemManage = new QTabWidget(tabSystemManage);
        tabWidgetSystemManage->setObjectName("tabWidgetSystemManage");
        tabUserManage = new QWidget();
        tabUserManage->setObjectName("tabUserManage");
        verticalLayout_6 = new QVBoxLayout(tabUserManage);
        verticalLayout_6->setObjectName("verticalLayout_6");
        widgetUserManager = new UserManager(tabUserManage);
        widgetUserManager->setObjectName("widgetUserManager");

        verticalLayout_6->addWidget(widgetUserManager);

        tabWidgetSystemManage->addTab(tabUserManage, QString());
        tabRoleManage = new QWidget();
        tabRoleManage->setObjectName("tabRoleManage");
        verticalLayout_7 = new QVBoxLayout(tabRoleManage);
        verticalLayout_7->setObjectName("verticalLayout_7");
        widgetRoleManager = new RoleManager(tabRoleManage);
        widgetRoleManager->setObjectName("widgetRoleManager");

        verticalLayout_7->addWidget(widgetRoleManager);

        tabWidgetSystemManage->addTab(tabRoleManage, QString());
        tabApprovalManage = new QWidget();
        tabApprovalManage->setObjectName("tabApprovalManage");
        verticalLayout_8 = new QVBoxLayout(tabApprovalManage);
        verticalLayout_8->setObjectName("verticalLayout_8");
        widgetApprovalManager = new ApprovalManager(tabApprovalManage);
        widgetApprovalManager->setObjectName("widgetApprovalManager");

        verticalLayout_8->addWidget(widgetApprovalManager);

        tabWidgetSystemManage->addTab(tabApprovalManage, QString());

        verticalLayout_5->addWidget(tabWidgetSystemManage);

        tabWidgetMain->addTab(tabSystemManage, QString());

        verticalLayout->addWidget(tabWidgetMain);

        SystemManager->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SystemManager);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 33));
        SystemManager->setMenuBar(menubar);
        statusbar = new QStatusBar(SystemManager);
        statusbar->setObjectName("statusbar");
        SystemManager->setStatusBar(statusbar);

        retranslateUi(SystemManager);

        tabWidgetMain->setCurrentIndex(0);
        tabWidgetDataManage->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(SystemManager);
    } // setupUi

    void retranslateUi(QMainWindow *SystemManager)
    {
        SystemManager->setWindowTitle(QCoreApplication::translate("SystemManager", "\347\263\273\347\273\237\347\256\241\347\220\206", nullptr));
        labelBasicDataPath->setText(QCoreApplication::translate("SystemManager", "\346\225\260\346\215\256\350\267\257\345\276\204\357\274\232", nullptr));
        btnSelectBasicDataPath->setText(QCoreApplication::translate("SystemManager", "\351\200\211\346\213\251\350\267\257\345\276\204", nullptr));
        btnAddBasicFolder->setText(QCoreApplication::translate("SystemManager", "\346\267\273\345\212\240\346\226\207\344\273\266\345\244\271", nullptr));
        btnDeleteBasicData->setText(QCoreApplication::translate("SystemManager", "\345\210\240\351\231\244", nullptr));
        labelAttachment->setText(QCoreApplication::translate("SystemManager", "\351\231\204\344\273\266\357\274\232", nullptr));
        btnSelectAttachment->setText(QCoreApplication::translate("SystemManager", "\351\200\211\346\213\251\351\231\204\344\273\266", nullptr));
        tabWidgetDataManage->setTabText(tabWidgetDataManage->indexOf(tabBasicData), QCoreApplication::translate("SystemManager", "\345\237\272\347\241\200\346\225\260\346\215\256\345\272\223", nullptr));
        labelCDDataPath->setText(QCoreApplication::translate("SystemManager", "\346\225\260\346\215\256\350\267\257\345\276\204\357\274\232", nullptr));
        btnSelectCDDataPath->setText(QCoreApplication::translate("SystemManager", "\351\200\211\346\213\251\350\267\257\345\276\204", nullptr));
        btnNewModel->setText(QCoreApplication::translate("SystemManager", "\346\226\260\345\273\272\345\236\213\345\217\267", nullptr));
        btnAddStructureType->setText(QCoreApplication::translate("SystemManager", "\347\273\223\346\236\204\345\261\202\347\272\247\347\273\264\346\212\244", nullptr));
        btnCopyData->setText(QCoreApplication::translate("SystemManager", "\346\225\260\346\215\256\345\244\215\345\210\266", nullptr));
        btnDelete->setText(QCoreApplication::translate("SystemManager", "\345\210\240\351\231\244", nullptr));
        tabWidgetDataManage->setTabText(tabWidgetDataManage->indexOf(tabCompartmentData), QCoreApplication::translate("SystemManager", "\350\210\261\346\256\265\346\225\260\346\215\256\345\272\223", nullptr));
        labelAcousticsPath->setText(QCoreApplication::translate("SystemManager", "CSV\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", nullptr));
        btnSelectAcousticsCSV->setText(QCoreApplication::translate("SystemManager", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        tabWidgetDataManage->setTabText(tabWidgetDataManage->indexOf(tabUnderwaterData), QCoreApplication::translate("SystemManager", "\345\243\260\345\255\246\345\217\202\346\225\260\345\272\223", nullptr));
        labelCSVPath->setText(QCoreApplication::translate("SystemManager", "CSV\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", nullptr));
        btnSelectCSV->setText(QCoreApplication::translate("SystemManager", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        tabWidgetDataManage->setTabText(tabWidgetDataManage->indexOf(tabMaterialData), QCoreApplication::translate("SystemManager", "\346\235\220\346\226\231\345\272\223", nullptr));
        labelLoadPath->setText(QCoreApplication::translate("SystemManager", "\350\275\275\350\215\267\345\272\223\350\267\257\345\276\204\357\274\232", nullptr));
        btnSelectLoadPath->setText(QCoreApplication::translate("SystemManager", "\351\200\211\346\213\251\350\267\257\345\276\204", nullptr));
        tabWidgetDataManage->setTabText(tabWidgetDataManage->indexOf(tabLoadData), QCoreApplication::translate("SystemManager", "\350\275\275\350\215\267\345\272\223", nullptr));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tabDataManage), QCoreApplication::translate("SystemManager", "\346\225\260\346\215\256\347\256\241\347\220\206", nullptr));
        labelStatus->setText(QCoreApplication::translate("SystemManager", "\347\212\266\346\200\201\357\274\232", nullptr));
        comboBoxStatusFilter->setItemText(0, QCoreApplication::translate("SystemManager", "\345\205\250\351\203\250", nullptr));
        comboBoxStatusFilter->setItemText(1, QCoreApplication::translate("SystemManager", "\345\276\205\345\244\204\347\220\206", nullptr));
        comboBoxStatusFilter->setItemText(2, QCoreApplication::translate("SystemManager", "\350\277\233\350\241\214\344\270\255", nullptr));
        comboBoxStatusFilter->setItemText(3, QCoreApplication::translate("SystemManager", "\345\267\262\345\256\214\346\210\220", nullptr));
        comboBoxStatusFilter->setItemText(4, QCoreApplication::translate("SystemManager", "\345\267\262\345\217\226\346\266\210", nullptr));

        labelType->setText(QCoreApplication::translate("SystemManager", "\347\261\273\345\236\213\357\274\232", nullptr));
        comboBoxTypeFilter->setItemText(0, QCoreApplication::translate("SystemManager", "\345\205\250\351\203\250", nullptr));
        comboBoxTypeFilter->setItemText(1, QCoreApplication::translate("SystemManager", "\346\250\241\346\200\201\345\210\206\346\236\220", nullptr));
        comboBoxTypeFilter->setItemText(2, QCoreApplication::translate("SystemManager", "\351\235\231\345\212\233\345\255\246\345\210\206\346\236\220", nullptr));
        comboBoxTypeFilter->setItemText(3, QCoreApplication::translate("SystemManager", "\346\214\257\345\212\250\345\210\206\346\236\220", nullptr));

        lineEditSearch->setPlaceholderText(QCoreApplication::translate("SystemManager", "\346\220\234\347\264\242\344\273\273\345\212\241...", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableTaskList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SystemManager", "\344\273\273\345\212\241ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableTaskList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("SystemManager", "\344\273\273\345\212\241\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableTaskList->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("SystemManager", "\344\273\273\345\212\241\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableTaskList->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("SystemManager", "\344\273\273\345\212\241\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableTaskList->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("SystemManager", "\346\214\207\346\264\276\344\272\272\345\221\230", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableTaskList->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("SystemManager", "\345\210\233\345\273\272\346\227\266\351\227\264", nullptr));
        groupBoxBasicInfo->setTitle(QCoreApplication::translate("SystemManager", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        labelTaskName->setText(QCoreApplication::translate("SystemManager", "\344\273\273\345\212\241\345\220\215\347\247\260\357\274\232", nullptr));
        labelWorkDir->setText(QCoreApplication::translate("SystemManager", "\345\267\245\344\275\234\347\233\256\345\275\225\357\274\232", nullptr));
        btnSelectWorkDir->setText(QCoreApplication::translate("SystemManager", "\351\200\211\346\213\251\347\233\256\345\275\225", nullptr));
        labelTaskDesc->setText(QCoreApplication::translate("SystemManager", "\344\273\273\345\212\241\346\217\217\350\277\260\357\274\232", nullptr));
        labelTaskAttachment->setText(QCoreApplication::translate("SystemManager", "\351\231\204\344\273\266\357\274\232", nullptr));
        btnSelectTaskAttachment->setText(QCoreApplication::translate("SystemManager", "\351\200\211\346\213\251\351\231\204\344\273\266", nullptr));
        groupBoxModel->setTitle(QCoreApplication::translate("SystemManager", "\350\210\261\346\256\265\346\250\241\345\236\213", nullptr));
        labelModelType->setText(QCoreApplication::translate("SystemManager", "\345\236\213\345\217\267\351\200\211\346\213\251\357\274\232", nullptr));
        labelModelPath->setText(QCoreApplication::translate("SystemManager", "\346\250\241\345\236\213\350\267\257\345\276\204\357\274\232", nullptr));
        groupBoxAnalysisType->setTitle(QCoreApplication::translate("SystemManager", "\345\210\206\346\236\220\347\261\273\345\236\213", nullptr));
        checkBoxDryModalAnalysis->setText(QCoreApplication::translate("SystemManager", "\345\271\262\346\250\241\346\200\201\345\210\206\346\236\220", nullptr));
        checkBoxWetModalAnalysis->setText(QCoreApplication::translate("SystemManager", "\346\271\277\346\250\241\346\200\201\345\210\206\346\236\220", nullptr));
        checkBoxStaticAnalysis->setText(QCoreApplication::translate("SystemManager", "\351\235\231\345\212\233\345\255\246\345\210\206\346\236\220", nullptr));
        checkBoxVibrationAnalysis->setText(QCoreApplication::translate("SystemManager", "\346\214\257\345\212\250\345\210\206\346\236\220", nullptr));
        checkBoxAcousticAnalysis->setText(QCoreApplication::translate("SystemManager", "\345\243\260\345\255\246\345\210\206\346\236\220", nullptr));
        groupBoxAssign->setTitle(QCoreApplication::translate("SystemManager", "\344\273\273\345\212\241\346\214\207\346\264\276", nullptr));
        labelAssignTo->setText(QCoreApplication::translate("SystemManager", "\346\214\207\346\264\276\347\273\231\357\274\232", nullptr));
        labelAssignDesc->setText(QCoreApplication::translate("SystemManager", "\346\214\207\346\264\276\350\257\264\346\230\216\357\274\232", nullptr));
        btnTaskPublish->setText(QCoreApplication::translate("SystemManager", "\345\217\221\345\270\203\344\273\273\345\212\241", nullptr));
        btnTaskDelete->setText(QCoreApplication::translate("SystemManager", "\345\210\240\351\231\244\344\273\273\345\212\241", nullptr));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tabTaskManage), QCoreApplication::translate("SystemManager", "\344\273\273\345\212\241\347\256\241\347\220\206", nullptr));
        tabWidgetSystemManage->setTabText(tabWidgetSystemManage->indexOf(tabUserManage), QCoreApplication::translate("SystemManager", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        tabWidgetSystemManage->setTabText(tabWidgetSystemManage->indexOf(tabRoleManage), QCoreApplication::translate("SystemManager", "\350\247\222\350\211\262\347\256\241\347\220\206", nullptr));
        tabWidgetSystemManage->setTabText(tabWidgetSystemManage->indexOf(tabApprovalManage), QCoreApplication::translate("SystemManager", "\345\256\241\346\211\271\347\256\241\347\220\206", nullptr));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tabSystemManage), QCoreApplication::translate("SystemManager", "\347\263\273\347\273\237\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemManager: public Ui_SystemManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMMANAGER_H
