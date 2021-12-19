#ifndef KEYCOLORSLOTS_H
#define KEYCOLORSLOTS_H

#include <preapptasks.h>
#include <QDialog>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QInputDialog>
#include <QMessageBox>

namespace Ui {
class keyColorSlots;
}

class keyColorSlots : public QDialog
{
    Q_OBJECT

public:
    explicit keyColorSlots(QWidget *parent = nullptr);
    ~keyColorSlots();

    void initialize();

    QString getPath() {return filePath;}

    void lightColSlots();
    void darkColSlots();

private slots:
    void on_pushButton_Add_clicked();

    void on_pushButton_Remove_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_listWidget_Slots_currentRowChanged(int currentRow);

private:
    Ui::keyColorSlots *ui;

    PreAppTasks paths;

    QString filePath;
};

#endif // KEYCOLORSLOTS_H
