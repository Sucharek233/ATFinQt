#include "courses.h"
#include "ui_courses.h"

Courses::Courses(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Courses)
{
    ui->setupUi(this);
}

Courses::~Courses()
{
    delete ui;
}

void Courses::on_listWidget_currentTextChanged(const QString &currentText)
{
    if (currentText == "Temp course – Quick red fox")
    {
        selectedArticle = "A quick red fox jumped over a lazy dog";
    } else {
        selectedArticle = "Another one";
    }
}

void Courses::on_buttonBox_accepted()
{
    accept();
    close();
}

void Courses::on_buttonBox_rejected()
{
    close();
}
