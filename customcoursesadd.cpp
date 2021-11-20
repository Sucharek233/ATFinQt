#include "customcoursesadd.h"
#include "ui_customcoursesadd.h"
#include "preapptasks.h"

QString pathS;
QString pathC;
QString path;

int switcher;

QString fileContents;
int slotNumbers;

QString currSN;
QString currST;

customCoursesAdd::customCoursesAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customCoursesAdd)
{
    ui->setupUi(this);
    initialize(1);
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
}

customCoursesAdd::~customCoursesAdd()
{
    delete ui;
}

void customCoursesAdd::on_lineEdit_Name_textChanged(const QString &arg1)
{
    name = arg1;
}

void customCoursesAdd::on_textEdit_Text_textChanged()
{
    text = ui->textEdit_Text->toPlainText().simplified();
}

void customCoursesAdd::on_buttonBox_accepted()
{
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
}

void customCoursesAdd::on_buttonBox_rejected()
{
    reject();
    close();
}
