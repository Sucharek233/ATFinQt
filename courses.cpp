#include "courses.h"
#include "ui_courses.h"

int invalidSlotSelected;

QString pathSlots;
QString pathConfig;
int currSlot;

QString currN;
QString currT;

QString noMoreStyleSheet;

int temp = 1;

void Courses::updateVars()
{
    QFile *config = new QFile(pathConfig);
    QTextStream cIn(config);
    cIn.setCodec("UTF-8");
    config->open(QIODevice::ReadOnly | QIODevice::Text);
    int slotNumber = cIn.readLine().toInt();
    config->close();

    QFile *Slots = new QFile(pathSlots);
    QTextStream sIn(Slots);
    sIn.setCodec("UTF-8");
    Slots->open(QIODevice::ReadOnly | QIODevice::Text);
    for(int i=1; i<=slotNumber; i++){
          QString line = sIn.readLine();
          sIn.readLine();
          ui->listWidget_Courses->addItem(line);
       }
    Slots->close();
}

Courses::Courses(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Courses)
{
    ui->setupUi(this);
    pathSlots = additionalInfo.pathToInitFileSlots();
    pathConfig = additionalInfo.pathToInitFileConfig();

    updateVars();
    lightCourses();
}

void Courses::lightCourses()
{
    Courses::setStyleSheet("background-color: rgb(244, 244, 244);");
    QString button = "color: black; background-color: rgb(244, 244, 244);";
    ui->pushButton_Add->setStyleSheet(button);
    ui->pushButton_Edit->setStyleSheet(button);
    ui->pushButton_Remove->setStyleSheet(button);
    ui->pushButton_Reset->setStyleSheet(button);
    ui->buttonBox->setStyleSheet("QPushButton {color: black; background-color: rgb(244, 244, 244); font-size: 12px;}");
    ui->label->setStyleSheet("color: black;");
    ui->listWidget_Courses->setStyleSheet("QListWidget {background-color: white; border: 0.5px solid grey;}"
                                          "QListWidget::item {color: black; background-color: white;}"
                                          "QListWidget::item:selected {color: white; background-color: rgb(0, 120, 215); border: 0.5px solid black;}");
    noMoreStyleSheet = "QMessageBox {background-color: rgb(244, 244, 244);}"
                       "QLabel {background-color: rgb(244, 244, 244); color: black; font-size: 16px;}"
                       "QPushButton {color: black; background-color: rgb(244, 244, 244); font-size: 14px;}";
}
void Courses::darkCourses()
{
    Courses::setStyleSheet("background-color: rgb(6, 6, 14);");
    QString button = "color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);";
    ui->pushButton_Add->setStyleSheet(button);
    ui->pushButton_Edit->setStyleSheet(button);
    ui->pushButton_Remove->setStyleSheet(button);
    ui->pushButton_Reset->setStyleSheet(button);
    ui->buttonBox->setStyleSheet("QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 12px;}");
    ui->label->setStyleSheet("color: rgb(211, 213, 201);");
    ui->listWidget_Courses->setStyleSheet("QListWidget {background-color: rgb(36, 36, 44); border: 1px solid rgb(66, 66, 74);}"
                                          "QListWidget::item {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);}"
                                          "QListWidget::item:selected {color: rgb(211, 213, 201); background-color: rgb(66, 66, 74); border: 0.5px solid black;}");
    noMoreStyleSheet = "QMessageBox {background-color: rgb(6, 6, 14);}"
                       "QLabel {background-color: rgb(6, 6, 14); color: rgb(211, 213, 201); font-size: 16px;}"
                       "QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 14px;}";
}

Courses::~Courses()
{
    delete ui;
}

void Courses::on_listWidget_Courses_currentRowChanged(int currentRow)
{
    currSlot = currentRow;
    add.setCurrSlot(currSlot);

    QFile *config = new QFile(pathConfig);
    QTextStream cIn(config);
    cIn.setCodec("UTF-8");
    config->open(QIODevice::ReadOnly | QIODevice::Text);
    int slotNumber = cIn.readLine().toInt();
    config->close();

    QFile *Slots = new QFile(pathSlots);
    QTextStream sIn(Slots);
    sIn.setCodec("UTF-8");
    Slots->open(QIODevice::ReadOnly | QIODevice::Text);
    for(int i=1; i<=slotNumber; i++){
        currN = sIn.readLine();
        currT = sIn.readLine(); selectedArticle = currT;
        if (currSlot == i - 1) {
            break;
          }
       }
    Slots->close();
}


void Courses::on_buttonBox_accepted()
{
    if (selectedArticle == "") {
        QMessageBox bad;
        bad.setStyleSheet(noMoreStyleSheet);
        bad.setWindowTitle("Invalid slot selected!");
        bad.setText("Warning! An invalid slot has been selected!\nPlease select another slot, or if the are\nno slots, please click add, and make one!");
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
    add.setCurrSlot(currSlot);
    add.initialize(1);
    if (add.exec() == QDialog::Accepted) {
        ui->listWidget_Courses->clear();
        updateVars();
    }
}

void Courses::on_pushButton_Edit_clicked()
{
    add.setModal(true);
    add.setCurrSlot(currSlot);
    add.initialize(2);
    if (add.exec() == QDialog::Accepted) {
        ui->listWidget_Courses->clear();
        updateVars();
    }
}

void Courses::on_pushButton_Remove_clicked()
{
    QFile *config = new QFile(pathConfig);
    QTextStream cIn(config);
    cIn.setCodec("UTF-8");
    config->open(QIODevice::ReadWrite | QIODevice::Text);
    QString num = cIn.readLine();
    int slotNumbers = num.toInt();
    slotNumbers = slotNumbers - 1;
    if (slotNumbers < 0) {
        slotNumbers = 0;
    }
    config->resize(0);
    config->write(QString::number(slotNumbers).toUtf8());
    config->close();
    qDebug() << slotNumbers;

    QFile *Slots = new QFile(pathSlots);
    QTextStream sIn(Slots);
    sIn.setCodec("UTF-8");
    Slots->open(QIODevice::ReadWrite | QIODevice::Text);
    if (slotNumbers == 0) {
        Slots->resize(0);
        QMessageBox noMore;
        noMore.setStyleSheet(noMoreStyleSheet);
        noMore.setWindowTitle("No more slots to remove!");
        noMore.setText("There are no more slots to remove!\nPlease don't click this button!");
        noMore.exec();
    } else {
        QString fileContents = sIn.readAll();
        fileContents = fileContents.replace(currN + "\n", "");
        fileContents = fileContents.replace("\n" + currT, "");
        Slots->resize(0);
        Slots->write(fileContents.toUtf8());
    }
    Slots->close();

    ui->listWidget_Courses->clear();
    updateVars();
}

void Courses::on_pushButton_Reset_clicked()
{
    QFile *configS = new QFile(pathSlots);
    configS->open(QIODevice::ReadWrite | QIODevice::Text);
    configS->resize(0);
    configS->write("Quick red fox\n"
                   "A quick red fox jumped over a lazy dog.");
    configS->close();

    QFile *configC = new QFile(pathConfig);
    configC->open(QIODevice::ReadWrite | QIODevice::Text);
    configC->resize(0);
    configC->write("1");
    configC->close();

    ui->listWidget_Courses->clear();
    updateVars();
}
