#ifndef COURSES_H
#define COURSES_H

#include <QDialog>
#include <QDebug>

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

private slots:
    void on_listWidget_currentTextChanged(const QString &currentText);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Courses *ui;
    QString selectedArticle;
};

#endif // COURSES_H
