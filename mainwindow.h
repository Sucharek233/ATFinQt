#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "additionalinfogetter.h"
#include "keymapping.h"
#include "courses.h"
#include "keycolor.h"
#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QVector>
#include <QGraphicsEllipseItem>
#include <QSize>
#include <QtSvg/QGraphicsSvgItem>
#include <QtSvg/QSvgRenderer>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void uncheck();
    void findChar();
    void lightMain();
    void darkMain();
    void updateColors();
    void updateKeys();

    void resizeEvent(QResizeEvent*);
    void changeFontSize(int size);
    void resize();

private slots:
    void on_lineEdit_TextInput_textChanged(const QString &arg1);

    void on_action_MakeCustomCourse_triggered();

    void on_action_ChangeKeyMapping_triggered();

    void on_action_ChangeKeyColors_triggered();

    void on_pushButton_StartCourse_clicked();

    void on_action_CourseSelector_triggered();

    void on_action_Light_triggered();

    void on_action_Dark_triggered();

private:
    Ui::MainWindow *ui;
    additionalInfoGetter getInfo;
    keyMapping keyMap;
    keyColor keyCol;
    Courses courses;
};
#endif // MAINWINDOW_H
