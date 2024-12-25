#pragma once
#include <QDialog>
#include <QTreeView>
#include <QFileSystemModel>

namespace Ui {
class StructureHierarchyDialog;
}

class StructureHierarchyDialog : public QDialog
{
    Q_OBJECT
public:
    explicit StructureHierarchyDialog(const QString& templatePath, QWidget* parent = nullptr);
    ~StructureHierarchyDialog();

private slots:
    void onAddFolderClicked();
    void onDeleteFolderClicked();

private:
    Ui::StructureHierarchyDialog* ui;
    QFileSystemModel* m_model;
    QString m_templatePath;
}; 