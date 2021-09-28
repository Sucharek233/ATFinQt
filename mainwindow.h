#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "additionalinfogetter.h"
#include "keymappingscolor.h"
#include "courses.h"
#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QVector>
#include <QGraphicsEllipseItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineEdit_TextInput_textChanged(const QString &arg1);

    void on_action_MakeCustomCourse_triggered();

    void on_action_ChangeKeyMapping_triggered();

    void on_pushButton_StartCourse_clicked();

    void on_action_CourseSelector_triggered();

private:
    Ui::MainWindow *ui;
    additionalInfoGetter getInfo;
    keyMappingsColor mapColor;
    Courses courses;
};
#endif // MAINWINDOW_H
