#include "customcoursesadd.h"
#include "ui_customcoursesadd.h"
#include "preapptasks.h"

int stopBlank;

QString msgBoxStyleSheet;

customCoursesAdd::customCoursesAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customCoursesAdd)
{
    ui->setupUi(this);
    initialize();

    lightCourseAdd();
}

void customCoursesAdd::initialize()
{
    ui->lineEdit_Name->setText(name);
    ui->textEdit_Text->setText(text);
}

void customCoursesAdd::lightCourseAdd()
{
    customCoursesAdd::setStyleSheet("background-color: rgb(244, 244, 244);");
    ui->buttonBox->setStyleSheet("QPushButton {color: black; background-color: rgb(244, 244, 244);}");
    ui->label_Main->setStyleSheet("color: black;");
    ui->label_Name->setStyleSheet("color: black;");
    ui->label_Text->setStyleSheet("color: black;");
    ui->textEdit_Text->setStyleSheet("color: black; background: white; font-size: 13px;");
    ui->lineEdit_Name->setStyleSheet("color: black; background-color: white; font-size: 13px;");
    msgBoxStyleSheet = "QMessageBox {background-color: rgb(244, 244, 244);}"
                         "QLabel {background-color: rgb(244, 244, 244); color: black; font-size: 16px;}"
                         "QPushButton {color: black; background-color: rgb(244, 244, 244); font-size: 14px;}";
}
void customCoursesAdd::darkCourseAdd()
{
    customCoursesAdd::setStyleSheet("background-color: rgb(6, 6, 14);");
    ui->buttonBox->setStyleSheet("QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);}");
    ui->label_Main->setStyleSheet("color: rgb(211, 213, 201);");
    ui->label_Name->setStyleSheet("color: rgb(211, 213, 201);");
    ui->label_Text->setStyleSheet("color: rgb(211, 213, 201);");
    ui->textEdit_Text->setStyleSheet("color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 13px;");
    ui->lineEdit_Name->setStyleSheet("color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 13px;");
    msgBoxStyleSheet = "QMessageBox {background-color: rgb(6, 6, 14);}"
                         "QLabel {background-color: rgb(6, 6, 14); color: rgb(211, 213, 201); font-size: 16px;}"
                         "QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 14px;}";
}

customCoursesAdd::~customCoursesAdd()
{
    delete ui;
}

void customCoursesAdd::on_lineEdit_Name_textChanged(const QString &arg1)
{
    name = arg1;
    stopBlank = 0;
}

void customCoursesAdd::on_textEdit_Text_textChanged()
{
    text = ui->textEdit_Text->toPlainText();
    stopBlank = 0;
}

void customCoursesAdd::on_buttonBox_accepted()
{
    if (name.simplified() == "") {
        stopBlank = stopBlank + 1;
    } else if (text.simplified() == "") {
        stopBlank = stopBlank + 1;
    }
    if (stopBlank > 0) {
        QMessageBox blank;
        blank.setWindowTitle("Black spaces");
        blank.setText("Warning! There are black spaces in name or text!\n"
                      "Please enter in a name or text and click OK!");
        blank.setStyleSheet(msgBoxStyleSheet);
        blank.exec();
    } else {
        accept();
        close();
    }
}

void customCoursesAdd::on_buttonBox_rejected()
{
    reject();
    close();
}
