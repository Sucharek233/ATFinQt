#include "courses.h"
#include "ui_courses.h"

int invalidSlotSelected;

QString Path;
int currSlot;

//Slots
QString Slot1Name;   QString Slot1Text;
QString Slot2Name;   QString Slot2Text;
QString Slot3Name;   QString Slot3Text;
QString Slot4Name;   QString Slot4Text;
QString Slot5Name;   QString Slot5Text;
QString Slot6Name;   QString Slot6Text;
QString Slot7Name;   QString Slot7Text;
QString Slot8Name;   QString Slot8Text;
QString Slot9Name;   QString Slot9Text;
QString Slot10Name;  QString Slot10Text;
QString Slot11Name;  QString Slot11Text;
QString Slot12Name;  QString Slot12Text;
QString Slot13Name;  QString Slot13Text;
QString Slot14Name;  QString Slot14Text;
QString Slot15Name;  QString Slot15Text;
QString Slot16Name;  QString Slot16Text;
QString Slot17Name;  QString Slot17Text;
QString Slot18Name;  QString Slot18Text;
QString Slot19Name;  QString Slot19Text;
QString Slot20Name;  QString Slot20Text;

void Courses::updateVars()
{
    QFile *config = new QFile(Path);
    QTextStream in(config);
    in.setCodec("UTF-8");
    config->open(QIODevice::ReadOnly | QIODevice::Text);

    in.readLine();
    Slot1Name = in.readLine();      Slot1Text = in.readLine();
    in.readLine();
    Slot2Name = in.readLine();      Slot2Text = in.readLine();
    in.readLine();
    Slot3Name = in.readLine();      Slot3Text = in.readLine();
    in.readLine();
    Slot4Name = in.readLine();      Slot4Text = in.readLine();
    in.readLine();
    Slot5Name = in.readLine();      Slot5Text = in.readLine();
    in.readLine();
    Slot6Name = in.readLine();      Slot6Text = in.readLine();
    in.readLine();
    Slot7Name = in.readLine();      Slot7Text = in.readLine();
    in.readLine();
    Slot8Name = in.readLine();      Slot8Text = in.readLine();
    in.readLine();
    Slot9Name = in.readLine();      Slot9Text = in.readLine();
    in.readLine();
    Slot10Name = in.readLine();     Slot10Text = in.readLine();
    in.readLine();
    Slot11Name = in.readLine();     Slot11Text = in.readLine();
    in.readLine();
    Slot12Name = in.readLine();     Slot12Text = in.readLine();
    in.readLine();
    Slot13Name = in.readLine();     Slot13Text = in.readLine();
    in.readLine();
    Slot14Name = in.readLine();     Slot14Text = in.readLine();
    in.readLine();
    Slot15Name = in.readLine();     Slot15Text = in.readLine();
    in.readLine();
    Slot16Name = in.readLine();     Slot16Text = in.readLine();
    in.readLine();
    Slot17Name = in.readLine();     Slot17Text = in.readLine();
    in.readLine();
    Slot18Name = in.readLine();     Slot18Text = in.readLine();
    in.readLine();
    Slot19Name = in.readLine();     Slot19Text = in.readLine();
    in.readLine();
    Slot20Name = in.readLine();     Slot20Text = in.readLine();
    config->close();

    if (Slot1Name == "") {ui->listWidget_Courses->addItem("Empty slot");} else {ui->listWidget_Courses->addItem(Slot1Name);}
    if (Slot2Name == "") {ui->listWidget_Courses->addItem("Empty slot");} else {ui->listWidget_Courses->addItem(Slot2Name);}
    if (Slot3Name == "") {ui->listWidget_Courses->addItem("Empty slot");} else {ui->listWidget_Courses->addItem(Slot3Name);}
    if (Slot4Name == "") {ui->listWidget_Courses->addItem("Empty slot");} else {ui->listWidget_Courses->addItem(Slot4Name);}
    if (Slot5Name == "") {ui->listWidget_Courses->addItem("Empty slot");} else {ui->listWidget_Courses->addItem(Slot5Name);}
    if (Slot6Name == "") {ui->listWidget_Courses->addItem("Empty slot");} else {ui->listWidget_Courses->addItem(Slot6Name);}
    if (Slot7Name == "") {ui->listWidget_Courses->addItem("Empty slot");} else {ui->listWidget_Courses->addItem(Slot7Name);}
    if (Slot8Name == "") {ui->listWidget_Courses->addItem("Empty slot");} else {ui->listWidget_Courses->addItem(Slot8Name);}
    if (Slot9Name == "") {ui->listWidget_Courses->addItem("Empty slot");} else {ui->listWidget_Courses->addItem(Slot9Name);}
    if (Slot10Name == "") {ui->listWidget_Courses->addItem("Empty slot");} else {ui->listWidget_Courses->addItem(Slot10Name);}
    if (Slot11Name == "") {ui->listWidget_Courses->addItem("Empty slot");} else {ui->listWidget_Courses->addItem(Slot11Name);}
    if (Slot12Name == "") {ui->listWidget_Courses->addItem("Empty slot");} else {ui->listWidget_Courses->addItem(Slot12Name);}
    if (Slot13Name == "") {ui->listWidget_Courses->addItem("Empty slot");} else {ui->listWidget_Courses->addItem(Slot13Name);}
    if (Slot14Name == "") {ui->listWidget_Courses->addItem("Empty slot");} else {ui->listWidget_Courses->addItem(Slot14Name);}
    if (Slot15Name == "") {ui->listWidget_Courses->addItem("Empty slot");} else {ui->listWidget_Courses->addItem(Slot15Name);}
    if (Slot16Name == "") {ui->listWidget_Courses->addItem("Empty slot");} else {ui->listWidget_Courses->addItem(Slot16Name);}
    if (Slot17Name == "") {ui->listWidget_Courses->addItem("Empty slot");} else {ui->listWidget_Courses->addItem(Slot17Name);}
    if (Slot18Name == "") {ui->listWidget_Courses->addItem("Empty slot");} else {ui->listWidget_Courses->addItem(Slot18Name);}
    if (Slot19Name == "") {ui->listWidget_Courses->addItem("Empty slot");} else {ui->listWidget_Courses->addItem(Slot19Name);}
    if (Slot20Name == "") {ui->listWidget_Courses->addItem("Empty slot");} else {ui->listWidget_Courses->addItem(Slot20Name);}
}

Courses::Courses(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Courses)
{
    ui->setupUi(this);
    Path = additionalInfo.pathToInitFile();

    updateVars();
}

void Courses::lightCourses()
{
    QString button = "color: black; background-color: rgb(244, 244, 244);";
    ui->pushButton_Add->setStyleSheet(button);
    ui->pushButton_Remove->setStyleSheet(button);
    ui->pushButton_Reset->setStyleSheet(button);
    ui->buttonBox->setStyleSheet("QPushButton {color: black; background-color: rgb(244, 244, 244); font-size: 12px;}");
    ui->label->setStyleSheet("color: black;");
    ui->listWidget_Courses->setStyleSheet("QListWidget::item {color: black; background-color: white}"
                                  "QListWidget::item:selected {color: white; background-color: rgb(0, 120, 215); border: 0.5px solid black}");
    Courses::setStyleSheet("background-color: rgb(244, 244, 244);");
}
void Courses::darkCourses()
{
    QString button = "color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);";
    ui->pushButton_Add->setStyleSheet(button);
    ui->pushButton_Remove->setStyleSheet(button);
    ui->pushButton_Reset->setStyleSheet(button);
    ui->buttonBox->setStyleSheet("QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 12px;}");
    ui->label->setStyleSheet("color: rgb(211, 213, 201);");
    ui->listWidget_Courses->setStyleSheet("QListWidget::item {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);}"
                                  "QListWidget::item:selected {color: rgb(211, 213, 201); background-color: rgb(66, 66, 74); border: 0.5px solid black;}");
    Courses::setStyleSheet("background-color: rgb(6, 6, 14);");
}

Courses::~Courses()
{
    delete ui;
}

void Courses::on_listWidget_Courses_currentRowChanged(int currentRow)
{
    currSlot = currentRow;
    add.setCurrSlot(currSlot);

    if (currSlot == 0) {
        if (Slot1Text == "") {invalidSlotSelected = 1;} else {selectedArticle = Slot1Text; invalidSlotSelected = 0;}
    } else if (currSlot == 1) {
        if (Slot2Text == "") {invalidSlotSelected = 1;} else {selectedArticle = Slot2Text; invalidSlotSelected = 0;}
    } else if (currSlot == 2) {
        if (Slot2Text == "") {invalidSlotSelected = 1;} else {selectedArticle = Slot3Text; invalidSlotSelected = 0;}
    } else if (currSlot == 3) {
        if (Slot3Text == "") {invalidSlotSelected = 1;} else {selectedArticle = Slot4Text; invalidSlotSelected = 0;}
    } else if (currSlot == 4) {
        if (Slot4Text == "") {invalidSlotSelected = 1;} else {selectedArticle = Slot5Text; invalidSlotSelected = 0;}
    } else if (currSlot == 5) {
        if (Slot5Text == "") {invalidSlotSelected = 1;} else {selectedArticle = Slot6Text; invalidSlotSelected = 0;}
    } else if (currSlot == 6) {
        if (Slot6Text == "") {invalidSlotSelected = 1;} else {selectedArticle = Slot7Text; invalidSlotSelected = 0;}
    } else if (currSlot == 7) {
        if (Slot7Text == "") {invalidSlotSelected = 1;} else {selectedArticle = Slot8Text; invalidSlotSelected = 0;}
    } else if (currSlot == 8) {
        if (Slot8Text == "") { invalidSlotSelected = 1;} else {selectedArticle = Slot9Text; invalidSlotSelected = 0;}
    } else if (currSlot == 9) {
        if (Slot9Text == "") {invalidSlotSelected = 1;} else {selectedArticle = Slot10Text; invalidSlotSelected = 0;}
    } else if (currSlot == 10) {
        if (Slot10Text == "") {invalidSlotSelected = 1;} else {selectedArticle = Slot11Text; invalidSlotSelected = 0;}
    } else if (currSlot == 11) {
        if (Slot11Text == "") {invalidSlotSelected = 1;} else {selectedArticle = Slot12Text; invalidSlotSelected = 0;}
    } else if (currSlot == 12) {
        if (Slot12Text == "") {invalidSlotSelected = 1;} else {selectedArticle = Slot13Text; invalidSlotSelected = 0;}
    } else if (currSlot == 13) {
        if (Slot13Text == "") {invalidSlotSelected = 1;} else {selectedArticle = Slot14Text; invalidSlotSelected = 0;}
    } else if (currSlot == 14) {
        if (Slot14Text == "") {invalidSlotSelected = 1;} else {selectedArticle = Slot15Text; invalidSlotSelected = 0;}
    } else if (currSlot == 15) {
        if (Slot15Text == "") {invalidSlotSelected = 1;} else {selectedArticle = Slot16Text; invalidSlotSelected = 0;}
    } else if (currSlot == 16) {
        if (Slot16Text == "") {invalidSlotSelected = 1;} else {selectedArticle = Slot17Text; invalidSlotSelected = 0;}
    } else if (currSlot == 17) {
        if (Slot18Text == "") {invalidSlotSelected = 1;} else {selectedArticle = Slot18Text; invalidSlotSelected = 0;}
    } else if (currSlot == 18) {
        if (Slot19Text == "") {invalidSlotSelected = 1;} else {selectedArticle = Slot19Text; invalidSlotSelected = 0;}
    } else if (currSlot == 19) {
        if (Slot20Text == "") {invalidSlotSelected = 1;} else {selectedArticle = Slot20Text; invalidSlotSelected = 0;}
    }
}


void Courses::on_buttonBox_accepted()
{
    if (invalidSlotSelected == 1) {
        QMessageBox invalid;
        invalid.setWindowTitle("Invalid slot selected!");
        invalid.setText("You have selected an empty slot!\nPlease select a valid slot and click Open!");
        invalid.exec();
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
    add.initialize();
    if (add.exec() == QDialog::Accepted) {
        ui->listWidget_Courses->clear();
        updateVars();
    }
}

void Courses::on_pushButton_Remove_clicked()
{
    ui->listWidget_Courses->clear();
    updateVars();
    if (currSlot == 0) {
        Slot1Name = ""; Slot1Text = "";
    } else if (currSlot == 1) {
        Slot2Name = ""; Slot2Text = "";
    } else if (currSlot == 2) {
        Slot3Name = ""; Slot3Text = "";
    } else if (currSlot == 3) {
        Slot4Name = ""; Slot4Text = "";
    } else if (currSlot == 4) {
        Slot5Name = ""; Slot5Text = "";
    } else if (currSlot == 5) {
        Slot6Name = ""; Slot6Text = "";
    } else if (currSlot == 6) {
        Slot7Name = ""; Slot7Text = "";
    } else if (currSlot == 7) {
        Slot8Name = ""; Slot8Text = "";
    } else if (currSlot == 8) {
        Slot9Name = ""; Slot9Text = "";
    } else if (currSlot == 9) {
        Slot10Name = ""; Slot10Text = "";
    } else if (currSlot == 10) {
        Slot11Name = ""; Slot11Text = "";
    } else if (currSlot == 11) {
        Slot12Name = ""; Slot12Text = "";
    } else if (currSlot == 12) {
        Slot13Name = ""; Slot13Text = "";
    } else if (currSlot == 13) {
        Slot14Name = ""; Slot14Text = "";
    } else if (currSlot == 14) {
        Slot15Name = ""; Slot15Text = "";
    } else if (currSlot == 15) {
        Slot16Name = ""; Slot16Text = "";
    } else if (currSlot == 16) {
        Slot17Name = ""; Slot17Text = "";
    } else if (currSlot == 17) {
        Slot8Name = ""; Slot18Text = "";
    } else if (currSlot == 18) {
        Slot19Name = ""; Slot19Text = "";
    } else if (currSlot == 19) {
        Slot20Name = ""; Slot20Text = "";
    }

    QFile *config = new QFile(Path);
    QTextStream in(config);
    config->open(QIODevice::ReadWrite | QIODevice::Text);
    config->resize(0);
    QString contents = "Slot 1\n" + Slot1Name + "\n" + Slot1Text + "\n" +
                       "Slot 2\n" + Slot2Name + "\n" + Slot2Text + "\n" +
                       "Slot 3\n" + Slot3Name + "\n" + Slot3Text + "\n" +
                       "Slot 4\n" + Slot4Name + "\n" + Slot4Text + "\n" +
                       "Slot 5\n" + Slot5Name + "\n" + Slot5Text + "\n" +
                       "Slot 6\n" + Slot6Name + "\n" + Slot6Text + "\n" +
                       "Slot 7\n" + Slot7Name + "\n" + Slot7Text + "\n" +
                       "Slot 8\n" + Slot8Name + "\n" + Slot8Text + "\n" +
                       "Slot 9\n" + Slot9Name + "\n" + Slot9Text + "\n" +
                       "Slot 10\n" + Slot10Name + "\n" + Slot10Text + "\n" +
                       "Slot 11\n" + Slot11Name + "\n" + Slot11Text + "\n" +
                       "Slot 12\n" + Slot12Name + "\n" + Slot12Text + "\n" +
                       "Slot 13\n" + Slot13Name + "\n" + Slot13Text + "\n" +
                       "Slot 14\n" + Slot14Name + "\n" + Slot14Text + "\n" +
                       "Slot 15\n" + Slot15Name + "\n" + Slot15Text + "\n" +
                       "Slot 16\n" + Slot16Name + "\n" + Slot16Text + "\n" +
                       "Slot 17\n" + Slot17Name + "\n" + Slot17Text + "\n" +
                       "Slot 18\n" + Slot18Name + "\n" + Slot18Text + "\n" +
                       "Slot 19\n" + Slot19Name + "\n" + Slot19Text + "\n" +
                       "Slot 20\n" + Slot20Name + "\n" + Slot20Text;
    config->write(contents.toUtf8());
    config->close();

    ui->listWidget_Courses->clear();
    updateVars();
}

void Courses::on_pushButton_Reset_clicked()
{
    QFile *config = new QFile(Path);
    QTextStream in(config);
    config->open(QIODevice::ReadWrite | QIODevice::Text);
    config->resize(0);
    QString contents = "Slot 1\n"
                                "Quick red fox\n"
                                "A quick red fox jumped over a lazy dog.\n"
                                "Slot 2\n\n\nSlot 3\n\n\nSlot 4\n\n\nSlot 5\n\n\nSlot 6\n\n\nSlot 7\n\n\nSlot 8\n\n\nSlot 9\n\n\nSlot 10\n\n\n"
                                "Slot 11\n\n\nSlot 12\n\n\nSlot 13\n\n\nSlot 14\n\n\nSlot 15\n\n\nSlot 16\n\n\nSlot 17\n\n\nSlot 18\n\n\nSlot 19\n\n\nSlot 20\n\n";
    config->write(contents.toUtf8());
    config->close();

    ui->listWidget_Courses->clear();
    updateVars();
}
