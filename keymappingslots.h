#ifndef KEYMAPPINGSLOTS_H
#define KEYMAPPINGSLOTS_H

#include "preapptasks.h"
#include <QDialog>
#include <QFile>
#include <QDir>
#include <QInputDialog>
#include <QMessageBox>

namespace Ui {
class keyMappingSlots;
}

class keyMappingSlots : public QDialog
{
    Q_OBJECT

public:
    explicit keyMappingSlots(QWidget *parent = nullptr);
    ~keyMappingSlots();

    void Initialize();

    QString GetPath() {return FilePath;}

    void lightMapSlots();
    void darkMapSlots();

private slots:
    void on_pushButton_Add_clicked();

    void on_pushButton_Remove_clicked();

    void on_listWidget_Slots_currentRowChanged(int currentRow);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_pushButton_Rename_clicked();

private:
    Ui::keyMappingSlots *ui;

    PreAppTasks Paths;

    QString FilePath;
};

#endif // KEYMAPPINGSLOTS_H
