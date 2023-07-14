#include "courses.h"
#include "ui_courses.h"

int invalidCourseselected;

QString pathCourses;
QString pathConfig;
int currSlot;

QString currN;
QString currT;

QString MsgBoxStyleSheet;

int temp = 1;

QString mainpath;
int filecount;

void Courses::updateVars()
{
    ui->listWidget_Courses->clear();

    mainpath = additionalInfo.pathToInitFileCoursesMain();

    QDir count(mainpath);
    filecount = count.count() - 1;

    for (int i = 1; i < filecount; i++) {
        QFile *file = new QFile(mainpath + QString::number(i) + ".ini");
        QTextStream reading(file);
        reading.setCodec("UTF-8");
        file->open(QIODevice::ReadOnly);
        ui->listWidget_Courses->addItem(reading.readLine());
        file->close();
    }
}

void Courses::rearRange()
{
    for (int i = 1; i < filecount; i++) {
        int fi = i;
        QString path = mainpath + QString::number(i) + ".ini";
        QFile file(path);
        qDebug() << "current file check:" << QString::number(i);
        while (!file.exists()) {
            fi = fi + 1;
            QString path = mainpath + QString::number(fi) + ".ini";
            QFile check(path);
            qDebug() << "old path:" << path;
            if (check.exists()) {
                check.open(QIODevice::ReadWrite);
                QString contents = check.readAll();
                check.close();
                check.remove();
                QFile renamed(mainpath + QString::number(i) + ".ini");
                qDebug() << "new path:" << QString(mainpath + QString::number(i) + ".ini");
                renamed.open(QIODevice::ReadWrite);
                renamed.resize(0);
                renamed.write(contents.toUtf8());
                break;
            }
        }
    }
}

Courses::Courses(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Courses)
{
    ui->setupUi(this);

    updateVars();
    rearRange();
    lightCourses();
}

void Courses::lightCourses()
{
    Courses::setStyleSheet("background-color: rgb(244, 244, 244);");
    QString button = "color: black; background-color: rgb(244, 244, 244);";
    ui->pushButton_Add->setStyleSheet(button);
    ui->pushButton_Edit->setStyleSheet(button);
    ui->pushButton_Remove->setStyleSheet(button);
    ui->buttonBox->setStyleSheet("QPushButton {color: black; background-color: rgb(244, 244, 244); font-size: 14px;}");
    ui->label->setStyleSheet("color: black;");
    ui->listWidget_Courses->setStyleSheet("QListWidget {background-color: white; border: 0.5px solid grey;}"
                                          "QListWidget::item {color: black; background-color: white;}"
                                          "QListWidget::item:selected {color: white; background-color: rgb(0, 120, 215); border: 0.5px solid black;}");
    MsgBoxStyleSheet = "QMessageBox {background-color: rgb(244, 244, 244);}"
                       "QLabel {background-color: rgb(244, 244, 244); color: black; font-size: 16px;}"
                       "QPushButton {color: black; background-color: rgb(244, 244, 244); font-size: 14px;}";
    add.lightCourseAdd();
}
void Courses::darkCourses()
{
    Courses::setStyleSheet("background-color: rgb(6, 6, 14);");
    QString button = "color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);";
    ui->pushButton_Add->setStyleSheet(button);
    ui->pushButton_Edit->setStyleSheet(button);
    ui->pushButton_Remove->setStyleSheet(button);
    ui->buttonBox->setStyleSheet("QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 14px;}");
    ui->label->setStyleSheet("color: rgb(211, 213, 201);");
    ui->listWidget_Courses->setStyleSheet("QListWidget {background-color: rgb(36, 36, 44); border: 1px solid rgb(66, 66, 74);}"
                                          "QListWidget::item {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);}"
                                          "QListWidget::item:selected {color: rgb(211, 213, 201); background-color: rgb(66, 66, 74); border: 0.5px solid black;}");
    MsgBoxStyleSheet = "QMessageBox {background-color: rgb(6, 6, 14);}"
                       "QLabel {background-color: rgb(6, 6, 14); color: rgb(211, 213, 201); font-size: 16px;}"
                       "QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 14px;}";
    add.darkCourseAdd();
}

Courses::~Courses()
{
    delete ui;
}

void Courses::on_listWidget_Courses_currentRowChanged(int currentRow)
{
    currSlot = currentRow;

    if (currSlot >= 0) {
    QFile *file = new QFile(mainpath + QString::number(currSlot + 1) + ".ini");
    file->open(QIODevice::ReadOnly);
    QTextStream read(file);
    read.setCodec("UTF-8");
    read.readLine();
    QString text;
    while(!read.atEnd()) {
        text = text + read.readLine() + "\n";
    }
    file->close();
    selectedArticle = text/*.simplified()*/;
    }
}

void Courses::on_buttonBox_accepted()
{
    if (selectedArticle == "") {
        QMessageBox bad;
        bad.setStyleSheet(MsgBoxStyleSheet);
        bad.setWindowTitle("Invalid slot selected!");
        bad.setText("Warning! An invalid slot has been selected!\nPlease select another slot, or if the are\nno Courses, please click add, and make one!");
        bad.exec();
    } else {
        accept();
        close();
    }
}

void Courses::on_buttonBox_rejected()
{
    close();
}

void Courses::on_pushButton_Add_clicked()
{
    add.setModal(true);
    add.setName("");
    add.setText("");
    add.initialize();
    if (add.exec() == QDialog::Accepted) {
        QString name = add.getName();
        QString text = add.getText();

        QFile file(mainpath + QString::number(filecount) + ".ini");
        file.open(QIODevice::ReadWrite);
        file.resize(0);
        file.write(QString(name + "\n" + text).toUtf8());
        file.close();

        updateVars();
        ui->listWidget_Courses->setCurrentRow(ui->listWidget_Courses->count() - 1);
    }
}

void Courses::on_pushButton_Edit_clicked()
{
    add.setModal(true);
    QFile *file = new QFile(mainpath + QString::number(currSlot + 1) + ".ini");
    file->open(QIODevice::ReadOnly);
    QTextStream read(file);
    read.setCodec("UTF-8");
    QString name = read.readLine();
    QString text;
    while(!read.atEnd()) {
        text = text + read.readLine() + "\n";
    }
    file->close();

    add.setName(name);
    add.setText(text);
    add.initialize();
    if (add.exec() == QDialog::Accepted) {
        QString name = add.getName();
        QString text = add.getText();
        file->open(QIODevice::ReadWrite);
        file->resize(0);
        file->write(QString(name + "\n" + text).toUtf8());
        file->close();

        int saveRow = currSlot;
        updateVars();
        ui->listWidget_Courses->setCurrentRow(saveRow);
    }
}

void Courses::on_pushButton_Remove_clicked()
{
    if (currSlot != -1) {
        if (currSlot == 0) {
            QMessageBox def;
            def.setWindowTitle("Default course");
            def.setText("Warning! Please don't try to remove\n"
                        "the default course!");
            def.setStyleSheet(MsgBoxStyleSheet);
            def.exec();
        } else {
            int items = filecount;
            int deletedItem = currSlot + 2;
            qDebug() << items;
            qDebug() << deletedItem;

            if (items == deletedItem) {
                QString path = mainpath + QString::number(currSlot + 1) + ".ini";
                QFile file(path);
                file.remove();

                updateVars();
                ui->listWidget_Courses->setCurrentRow(ui->listWidget_Courses->count() - 1);
            } else {
                QString path = mainpath + QString::number(currSlot + 1) + ".ini";
                QFile file(path);
                file.remove();
                qDebug() << QString(mainpath + QString::number(currSlot + 1) + ".ini");

                int count = currSlot;

                filecount = filecount - 1;
                rearRange();
                updateVars();
                ui->listWidget_Courses->setCurrentRow(count);
            }
        }
    } else {
        QMessageBox un;
        un.setWindowTitle("Not selected");
        un.setText("Warning! You have not selected anything!\n"
                   "Please select a slot and click Remove!");
        un.setStyleSheet(MsgBoxStyleSheet);
        un.exec();
    }
}
