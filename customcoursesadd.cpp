#include "customcoursesadd.h"
#include "ui_customcoursesadd.h"
#include "preapptasks.h"

QString pathS;
QString pathC;
QString path;

int switcher;

QString fileContents;
int slotNumbers;
int lines;

QString currSN;
QString currST;

int stopDuplicate;

QString stopDupeStyleSheet;

customCoursesAdd::customCoursesAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customCoursesAdd)
{
    ui->setupUi(this);
    initialize(1);

    lightCourseAdd();
}

void customCoursesAdd::initialize(int AoE)
{
    switcher = AoE;

    if (switcher == 1) {
        ui->label_Main->setText("Add a custom course");
        ui->textEdit_Text->setText("");
        ui->lineEdit_Name->setText("");
    } else {
        ui->label_Main->setText("Edit a custom course");
        QFile *Slots = new QFile(pathS);
        QTextStream sIn(Slots);
        sIn.setCodec("UTF-8");
        Slots->open(QIODevice::ReadOnly | QIODevice::Text);
        for(int i=0; i<=currSlot; i++){
            currSN = sIn.readLine();    ui->lineEdit_Name->setText(currSN);
            currST = sIn.readLine();    ui->textEdit_Text->setText(currST);
            if (currSlot == i - 1) {
                break;
              }
           }
        Slots->close();
    }

    PreAppTasks load;
    pathS = load.pathToInitFileSlots();
    pathC = load.pathToInitFileConfig();

    QFile *config = new QFile(pathC);
    QTextStream cIn(config);
    cIn.setCodec("UTF-8");
    config->open(QIODevice::ReadOnly | QIODevice::Text);
    QString num = cIn.readLine();
    slotNumbers = num.toInt();
    config->close();

    QFile *Slots = new QFile(pathS);
    QTextStream sIn(Slots);
    sIn.setCodec("UTF-8");
    Slots->open(QIODevice::ReadOnly | QIODevice::Text);
    fileContents = sIn.readAll();
    Slots->close();

    Slots->open(QIODevice::ReadOnly | QIODevice::Text);
    lines = 0;
    while(true){
        lines = lines + 1;
        sIn.readLine();
        if (sIn.atEnd()) {
            break;
          }
    }
    Slots->close();
}

QString customCoursesAdd::multipleCheck(QString varToCheck)
{
    QFile *Slots = new QFile(pathS);
    QTextStream sIn(Slots);
    sIn.setCodec("UTF-8");
    Slots->open(QIODevice::ReadOnly | QIODevice::Text);

    QString checkName;
    QString checkText;
    QString toReturn;

    for(int i=0; i<=lines; i++){
        checkName = sIn.readLine();
        checkText = sIn.readLine();

        if (checkName == varToCheck) {toReturn = "yes"; break;} else {toReturn = "no";}
        if (checkText == varToCheck) {toReturn = "yes"; break;} else {toReturn = "no";}
    }

    if (varToCheck == "") {toReturn = "empty";}
    return toReturn;

    Slots->close();
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
    stopDupeStyleSheet = "QMessageBox {background-color: rgb(244, 244, 244);}"
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
    stopDupeStyleSheet = "QMessageBox {background-color: rgb(6, 6, 14);}"
                         "QLabel {background-color: rgb(6, 6, 14); color: rgb(211, 213, 201); font-size: 16px;}"
                         "QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 14px;}";
}

customCoursesAdd::~customCoursesAdd()
{
    delete ui;
}

void customCoursesAdd::on_lineEdit_Name_textChanged(const QString &arg1)
{
    name = arg1.simplified();
    stopDuplicate = 0;
}

void customCoursesAdd::on_textEdit_Text_textChanged()
{
    text = ui->textEdit_Text->toPlainText().simplified();
    stopDuplicate = 0;
}

void customCoursesAdd::on_buttonBox_accepted()
{
    QString nameDupe = multipleCheck(name);
    QString textDupe = multipleCheck(text);

    if (nameDupe == "yes") {stopDuplicate = 1;}
    if (textDupe == "yes") {stopDuplicate = 1;}

    if (name == text) {stopDuplicate = 3;}

    int empty = 0;
    if (nameDupe == "empty") {
        empty = empty + 1;}
    if (textDupe == "empty") {
        empty = empty + 1;}
    if (empty > 0) {stopDuplicate = 2;}

    if (stopDuplicate == 0) {
        if (switcher == 1) {
            QFile *configC = new QFile(pathC);
            configC->open(QIODevice::ReadWrite | QIODevice::Text);
            configC->resize(0);
            slotNumbers = slotNumbers + 1;
            configC->write(QString::number(slotNumbers).toUtf8());
            configC->close();

            QFile *configS = new QFile(pathS);
            configS->open(QIODevice::ReadWrite | QIODevice::Text);
            configS->resize(0);
            if (slotNumbers == 1) {fileContents = name + "\n" + text;} else {
                fileContents = fileContents + "\n" + name + "\n" + text;
            }
            configS->write(fileContents.toUtf8());
            configS->close();
        } else {
            QFile *configS = new QFile(pathS);
            configS->open(QIODevice::ReadWrite | QIODevice::Text);
            configS->resize(0);
            fileContents = fileContents.replace(currSN, name);
            fileContents = fileContents.replace(currST, text);
            configS->write(fileContents.toUtf8());
            configS->close();
        }
        accept();
        close();
    } else if (stopDuplicate == 1) {
        QMessageBox stopDupe;
        stopDupe.setWindowTitle("Duplicate text found!");
        stopDupe.setText("Warning! You have entered name/text that already\n"
                         "exists in another course!\n"
                         "Please don't try to make duplicate courses!");
        stopDupe.setStyleSheet(stopDupeStyleSheet);
        stopDupe.exec();
    } else if (stopDuplicate == 2) {
        QMessageBox stopDupe;
        stopDupe.setWindowTitle("Empty spaces!");
        stopDupe.setText("Warning! You have entered name/text that is empty!\n"
                         "Please type in something and click OK!");
        stopDupe.setStyleSheet(stopDupeStyleSheet);
        stopDupe.exec();
    } else {
        QMessageBox stopDupe;
        stopDupe.setWindowTitle("Name se as text!");
        stopDupe.setText("Warning! You have entered the same name and text!\n"
                         "Please type in something different and click OK!");
        stopDupe.setStyleSheet(stopDupeStyleSheet);
        stopDupe.exec();
    }
}

void customCoursesAdd::on_buttonBox_rejected()
{
    reject();
    close();
}
