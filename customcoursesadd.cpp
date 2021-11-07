#include "customcoursesadd.h"
#include "ui_customcoursesadd.h"
#include "preapptasks.h"

QString path;

//Slots
QString slot1Name;   QString slot1Text;
QString slot2Name;   QString slot2Text;
QString slot3Name;   QString slot3Text;
QString slot4Name;   QString slot4Text;
QString slot5Name;   QString slot5Text;
QString slot6Name;   QString slot6Text;
QString slot7Name;   QString slot7Text;
QString slot8Name;   QString slot8Text;
QString slot9Name;   QString slot9Text;
QString slot10Name;  QString slot10Text;
QString slot11Name;  QString slot11Text;
QString slot12Name;  QString slot12Text;
QString slot13Name;  QString slot13Text;
QString slot14Name;  QString slot14Text;
QString slot15Name;  QString slot15Text;
QString slot16Name;  QString slot16Text;
QString slot17Name;  QString slot17Text;
QString slot18Name;  QString slot18Text;
QString slot19Name;  QString slot19Text;
QString slot20Name;  QString slot20Text;

void updateVariables() {
    QFile *config = new QFile(path);
    QTextStream in(config);
    in.setCodec("UTF-8");
    config->open(QIODevice::ReadOnly | QIODevice::Text);

    in.readLine();
    slot1Name = in.readLine();      slot1Text = in.readLine();
    in.readLine();
    slot2Name = in.readLine();      slot2Text = in.readLine();
    in.readLine();
    slot3Name = in.readLine();      slot3Text = in.readLine();
    in.readLine();
    slot4Name = in.readLine();      slot4Text = in.readLine();
    in.readLine();
    slot5Name = in.readLine();      slot5Text = in.readLine();
    in.readLine();
    slot6Name = in.readLine();      slot6Text = in.readLine();
    in.readLine();
    slot7Name = in.readLine();      slot7Text = in.readLine();
    in.readLine();
    slot8Name = in.readLine();      slot8Text = in.readLine();
    in.readLine();
    slot9Name = in.readLine();      slot9Text = in.readLine();
    in.readLine();
    slot10Name = in.readLine();     slot10Text = in.readLine();
    in.readLine();
    slot11Name = in.readLine();     slot11Text = in.readLine();
    in.readLine();
    slot12Name = in.readLine();     slot12Text = in.readLine();
    in.readLine();
    slot13Name = in.readLine();     slot13Text = in.readLine();
    in.readLine();
    slot14Name = in.readLine();     slot14Text = in.readLine();
    in.readLine();
    slot15Name = in.readLine();     slot15Text = in.readLine();
    in.readLine();
    slot16Name = in.readLine();     slot16Text = in.readLine();
    in.readLine();
    slot17Name = in.readLine();     slot17Text = in.readLine();
    in.readLine();
    slot18Name = in.readLine();     slot18Text = in.readLine();
    in.readLine();
    slot19Name = in.readLine();     slot19Text = in.readLine();
    in.readLine();
    slot20Name = in.readLine();     slot20Text = in.readLine();
    config->close();
}

customCoursesAdd::customCoursesAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customCoursesAdd)
{
    ui->setupUi(this);
    initialize();
}

void customCoursesAdd::initialize()
{
    PreAppTasks load;
    path = load.pathToInitFile();
    updateVariables();

    if (currSlot == 0) {
        ui->lineEdit_Name->setText(slot1Name);
        ui->textEdit_Text->setText(slot1Text);
    } else if (currSlot == 1) {
        ui->lineEdit_Name->setText(slot2Name);
        ui->textEdit_Text->setText(slot2Text);
    } else if (currSlot == 2) {
        ui->lineEdit_Name->setText(slot3Name);
        ui->textEdit_Text->setText(slot3Text);
    } else if (currSlot == 3) {
        ui->lineEdit_Name->setText(slot4Name);
        ui->textEdit_Text->setText(slot4Text);
    } else if (currSlot == 4) {
        ui->lineEdit_Name->setText(slot5Name);
        ui->textEdit_Text->setText(slot5Text);
    } else if (currSlot == 5) {
        ui->lineEdit_Name->setText(slot6Name);
        ui->textEdit_Text->setText(slot6Text);
    } else if (currSlot == 6) {
        ui->lineEdit_Name->setText(slot7Name);
        ui->textEdit_Text->setText(slot7Text);
    } else if (currSlot == 7) {
        ui->lineEdit_Name->setText(slot8Name);
        ui->textEdit_Text->setText(slot8Text);
    } else if (currSlot == 8) {
        ui->lineEdit_Name->setText(slot9Name);
        ui->textEdit_Text->setText(slot9Text);
    } else if (currSlot == 9) {
        ui->lineEdit_Name->setText(slot10Name);
        ui->textEdit_Text->setText(slot10Text);
    } else if (currSlot == 10) {
        ui->lineEdit_Name->setText(slot11Name);
        ui->textEdit_Text->setText(slot11Text);
    } else if (currSlot == 11) {
        ui->lineEdit_Name->setText(slot12Name);
        ui->textEdit_Text->setText(slot12Text);
    } else if (currSlot == 12) {
        ui->lineEdit_Name->setText(slot13Name);
        ui->textEdit_Text->setText(slot13Text);
    } else if (currSlot == 13) {
        ui->lineEdit_Name->setText(slot14Name);
        ui->textEdit_Text->setText(slot14Text);
    } else if (currSlot == 14) {
        ui->lineEdit_Name->setText(slot15Name);
        ui->textEdit_Text->setText(slot15Text);
    } else if (currSlot == 15) {
        ui->lineEdit_Name->setText(slot16Name);
        ui->textEdit_Text->setText(slot16Text);
    } else if (currSlot == 16) {
        ui->lineEdit_Name->setText(slot17Name);
        ui->textEdit_Text->setText(slot17Text);
    } else if (currSlot == 17) {
        ui->lineEdit_Name->setText(slot18Name);
        ui->textEdit_Text->setText(slot18Text);
    } else if (currSlot == 18) {
        ui->lineEdit_Name->setText(slot19Name);
        ui->textEdit_Text->setText(slot19Text);
    } else if (currSlot == 19) {
        ui->lineEdit_Name->setText(slot20Name);
        ui->textEdit_Text->setText(slot20Text);
    }
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
    if (currSlot == 0) {
        slot1Name = arg1;
    } else if (currSlot == 1) {
        slot2Name = arg1;
    } else if (currSlot == 2) {
        slot3Name = arg1;
    } else if (currSlot == 3) {
        slot4Name = arg1;
    } else if (currSlot == 4) {
        slot5Name = arg1;
    } else if (currSlot == 5) {
        slot6Name = arg1;
    } else if (currSlot == 6) {
        slot7Name = arg1;
    } else if (currSlot == 7) {
        slot8Name = arg1;
    } else if (currSlot == 8) {
        slot9Name = arg1;
    } else if (currSlot == 9) {
        slot10Name = arg1;
    } else if (currSlot == 10) {
        slot11Name = arg1;
    } else if (currSlot == 11) {
        slot12Name = arg1;
    } else if (currSlot == 12) {
        slot13Name = arg1;
    } else if (currSlot == 13) {
        slot14Name = arg1;
    } else if (currSlot == 14) {
        slot15Name = arg1;
    } else if (currSlot == 15) {
        slot16Name = arg1;
    } else if (currSlot == 16) {
        slot17Name = arg1;
    } else if (currSlot == 17) {
        slot18Name = arg1;
    } else if (currSlot == 18) {
        slot19Name = arg1;
    } else if (currSlot == 19) {
        slot20Name = arg1;
    }
}

void customCoursesAdd::on_textEdit_Text_textChanged()
{
    if (currSlot == 0) {
        slot1Text = ui->textEdit_Text->toPlainText().simplified();
    } else if (currSlot == 1) {
        slot2Text = ui->textEdit_Text->toPlainText().simplified();
    } else if (currSlot == 2) {
        slot3Text = ui->textEdit_Text->toPlainText().simplified();
    } else if (currSlot == 3) {
        slot4Text = ui->textEdit_Text->toPlainText().simplified();
    } else if (currSlot == 4) {
        slot5Text = ui->textEdit_Text->toPlainText().simplified();
    } else if (currSlot == 5) {
        slot6Text = ui->textEdit_Text->toPlainText().simplified();
    } else if (currSlot == 6) {
        slot7Text = ui->textEdit_Text->toPlainText().simplified();
    } else if (currSlot == 7) {
        slot8Text = ui->textEdit_Text->toPlainText().simplified();
    } else if (currSlot == 8) {
        slot9Text = ui->textEdit_Text->toPlainText().simplified();
    } else if (currSlot == 9) {
        slot10Text = ui->textEdit_Text->toPlainText().simplified();
    } else if (currSlot == 10) {
        slot11Text = ui->textEdit_Text->toPlainText().simplified();
    } else if (currSlot == 11) {
        slot12Text = ui->textEdit_Text->toPlainText().simplified();
    } else if (currSlot == 12) {
        slot13Text = ui->textEdit_Text->toPlainText().simplified();
    } else if (currSlot == 13) {
        slot14Text = ui->textEdit_Text->toPlainText().simplified();
    } else if (currSlot == 14) {
        slot15Text = ui->textEdit_Text->toPlainText().simplified();
    } else if (currSlot == 15) {
        slot16Text = ui->textEdit_Text->toPlainText().simplified();
    } else if (currSlot == 16) {
        slot17Text = ui->textEdit_Text->toPlainText().simplified();
    } else if (currSlot == 17) {
        slot18Text = ui->textEdit_Text->toPlainText().simplified();
    } else if (currSlot == 18) {
        slot19Text = ui->textEdit_Text->toPlainText().simplified();
    } else if (currSlot == 19) {
        slot20Text = ui->textEdit_Text->toPlainText().simplified();
    }
}

void customCoursesAdd::on_buttonBox_accepted()
{
    QFile *config = new QFile(path);
    QTextStream in(config);
    config->open(QIODevice::ReadWrite | QIODevice::Text);
    config->resize(0);
    QString contents = "Slot 1\n" + slot1Name + "\n" + slot1Text + "\n" +
                       "Slot 2\n" + slot2Name + "\n" + slot2Text + "\n" +
                       "Slot 3\n" + slot3Name + "\n" + slot3Text + "\n" +
                       "Slot 4\n" + slot4Name + "\n" + slot4Text + "\n" +
                       "Slot 5\n" + slot5Name + "\n" + slot5Text + "\n" +
                       "Slot 6\n" + slot6Name + "\n" + slot6Text + "\n" +
                       "Slot 7\n" + slot7Name + "\n" + slot7Text + "\n" +
                       "Slot 8\n" + slot8Name + "\n" + slot8Text + "\n" +
                       "Slot 9\n" + slot9Name + "\n" + slot9Text + "\n" +
                       "Slot 10\n" + slot10Name + "\n" + slot10Text + "\n" +
                       "Slot 11\n" + slot11Name + "\n" + slot11Text + "\n" +
                       "Slot 12\n" + slot12Name + "\n" + slot12Text + "\n" +
                       "Slot 13\n" + slot13Name + "\n" + slot13Text + "\n" +
                       "Slot 14\n" + slot14Name + "\n" + slot14Text + "\n" +
                       "Slot 15\n" + slot15Name + "\n" + slot15Text + "\n" +
                       "Slot 16\n" + slot16Name + "\n" + slot16Text + "\n" +
                       "Slot 17\n" + slot17Name + "\n" + slot17Text + "\n" +
                       "Slot 18\n" + slot18Name + "\n" + slot18Text + "\n" +
                       "Slot 19\n" + slot19Name + "\n" + slot19Text + "\n" +
                       "Slot 20\n" + slot20Name + "\n" + slot20Text;
    config->write(contents.toUtf8());
    config->close();
    updateVariables();

    accept();
    close();
}

void customCoursesAdd::on_buttonBox_rejected()
{
    reject();
    close();
}
