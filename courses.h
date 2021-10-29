#ifndef COURSES_H
#define COURSES_H

#include "customcoursesadd.h"
#include "preapptasks.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class Courses;
}

class Courses : public QDialog
{
    Q_OBJECT

public:
    explicit Courses(QWidget *parent = nullptr);
    ~Courses();

    QString getArticle() {return selectedArticle;}
    int getSlot() {return currSlot;}

private slots:
    void on_listWidget_currentRowChanged(int currentRow);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_pushButton_Add_clicked();

    void on_pushButton_Remove_clicked();

    void on_pushButton_Reset_clicked();

private:
    Ui::Courses *ui;
    customCoursesAdd add;
    PreAppTasks additionalInfo;

    QString selectedArticle;
    int currSlot;
};

#endif // COURSES_H
