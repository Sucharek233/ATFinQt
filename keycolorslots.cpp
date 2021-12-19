#include "keycolorslots.h"
#include "ui_keycolorslots.h"

QString mainPath;

int fileCount;

int currRow;

QString messBoxStyleSheet;
QString inputDialogStyleSheet;

void keyColorSlots::lightColSlots()
{
    keyColorSlots::setStyleSheet("background-color: rgb(244, 244, 244);");
    QString button = "color: black; background-color: rgb(244, 244, 244);";
    ui->pushButton_Add->setStyleSheet(button);
    ui->pushButton_Remove->setStyleSheet(button);
    ui->buttonBox->setStyleSheet("QPushButton {color: black; background-color: rgb(244, 244, 244); font-size: 12px;}");
    ui->label_Main->setStyleSheet("color: black;");
    ui->listWidget_Slots->setStyleSheet("QListWidget {background-color: white; border: 0.5px solid grey;}"
                                        "QListWidget::item {color: black; background-color: white;}"
                                        "QListWidget::item:selected {color: white; background-color: rgb(0, 120, 215); border: 0.5px solid black;}");
    messBoxStyleSheet = "QMessageBox {background-color: rgb(244, 244, 244);}"
                        "QLabel {background-color: rgb(244, 244, 244); color: black; font-size: 16px;}"
                        "QPushButton {color: black; background-color: rgb(244, 244, 244); font-size: 14px;}";
    inputDialogStyleSheet = "QInputDialog {background-color: rgb(244, 244, 244);}"
                            "QLabel {background-color: rgb(244, 244, 244); color: black; font-size: 16px;}"
                            "QLineEdit {color: black; background-color: white; font-size: 14px;}"
                            "QPushButton {color: black; background-color: rgb(244, 244, 244); font-size: 12px;}";
}
void keyColorSlots::darkColSlots()
{
    keyColorSlots::setStyleSheet("background-color: rgb(6, 6, 14);");
    QString button = "color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);";
    ui->pushButton_Add->setStyleSheet(button);
    ui->pushButton_Remove->setStyleSheet(button);
    ui->buttonBox->setStyleSheet("QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 12px;}");
    ui->label_Main->setStyleSheet("color: rgb(211, 213, 201);");
    ui->listWidget_Slots->setStyleSheet("QListWidget {background-color: rgb(36, 36, 44); border: 1px solid rgb(66, 66, 74);}"
                                          "QListWidget::item {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);}"
                                          "QListWidget::item:selected {color: rgb(211, 213, 201); background-color: rgb(66, 66, 74); border: 0.5px solid black;}");
    messBoxStyleSheet = "QMessageBox {background-color: rgb(6, 6, 14);}"
                        "QLabel {background-color: rgb(6, 6, 14); color: rgb(211, 213, 201); font-size: 16px;}"
                        "QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 14px;}";
    inputDialogStyleSheet = "QInputDialog {background-color: rgb(6, 6, 14);}"
                            "QLabel {background-color: rgb(6, 6, 14); color: rgb(211, 213, 201); font-size: 16px;}"
                            "QLineEdit {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 14px;}"
                            "QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 12px;}";
}

keyColorSlots::keyColorSlots(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::keyColorSlots)
{
    ui->setupUi(this);

    mainPath = paths.pathToInitFileCol();

    QFile file(paths.pathToInitFileColConfig());
    file.open(QIODevice::ReadOnly);
    filePath = file.readLine();
    file.close();

    initialize();

    lightColSlots();
}

void keyColorSlots::initialize()
{
    ui->listWidget_Slots->clear();

    QDir count(mainPath);
    fileCount = count.count() - 3;

    ui->listWidget_Slots->addItem("Default");

    for (int i = 1; i < fileCount; i++) {
        QFile *file = new QFile(mainPath + QString::number(i) + ".ini");
        QTextStream reading(file);
        file->open(QIODevice::ReadOnly);
        ui->listWidget_Slots->addItem(reading.readLine());
        file->close();
    }
}

keyColorSlots::~keyColorSlots()
{
    delete ui;
}

void keyColorSlots::on_pushButton_Add_clicked()
{
    QInputDialog name;
    name.setWindowTitle("Set name");
    name.setLabelText("Type in or paste an article.");
    name.setInputMode(QInputDialog::TextInput);
    name.setStyleSheet(inputDialogStyleSheet);
    if (name.exec() == QInputDialog::Accepted) {
        QString text = name.textValue();
        text = text.simplified();

        if (text == "") {
            QMessageBox empty;
            empty.setWindowTitle("Empty");
            empty.setText("You've not entered a name!\nPlease enter a name and click OK!");
            empty.setStyleSheet(messBoxStyleSheet);
            empty.exec();
        } else {
            QFile file(mainPath + QString::number(fileCount) + ".ini");
            file.open(QIODevice::ReadWrite);
            file.write(text.toUtf8() +
                       "\n#ffaa00\n"
                       "#af5a00\n"
                       "#cd7800\n"
                       "#ff0f0f\n"
                       "#960000\n"
                       "#780000\n"
                       "#14ff14\n"
                       "#00cd00\n"
                       "#009600\n"
                       "#3232ff\n"
                       "#0000cd\n"
                       "#0000af\n"
                       "#00ffff\n"
                       "#00cdcd\n"
                       "#00afaf\n"
                       "#bee6ff\n"
                       "#a0c8e1\n"
                       "#8cb4cd\n"
                       "#000000");
            file.close();
            initialize();
        }
    }
}

void keyColorSlots::on_pushButton_Remove_clicked()
{
    if (currRow == 0) {
        QMessageBox def;
        def.setWindowTitle("Default slot");
        def.setText("Warning! You can't delete the default slot, beacuse\n"
                    "the colors just don't randomly appear!\n"
                    "Please DO NOT try to delete this file manually!!!");
        def.setStyleSheet(messBoxStyleSheet);
        def.exec();
    } else {
        int items = fileCount;
        int deletedItem = currRow + 1;

        if (items == deletedItem) {
            QString path = mainPath + QString::number(currRow + 1) + ".ini";
            QFile file(path);
            file.remove();

            initialize();
        } else {
            QMessageBox support;
            support.setWindowTitle("Not supported!");
            support.setText("Waring! Only deleting the last slot is supported!\nPlease update your version or wait untill the next beta release!");
            support.setStyleSheet(messBoxStyleSheet);
            support.exec();
        }
    }
}

void keyColorSlots::on_buttonBox_accepted()
{
    if (currRow != -1) {
        QFile file(paths.pathToInitFileColConfig());
        file.open(QIODevice::ReadWrite);
        file.resize(0);
        if (currRow == 0) {
        file.write(QString(mainPath + "Colors.ini").toUtf8());
        } else {file.write(QString(mainPath + QString::number(currRow) + ".ini").toUtf8());}
        file.close();
        accept();
        close();
    }
}

void keyColorSlots::on_buttonBox_rejected()
{
    reject();
    close();
}

void keyColorSlots::on_listWidget_Slots_currentRowChanged(int currentRow)
{
    currRow = currentRow;
    if (currRow == 0) {filePath = mainPath + "Colors.ini";} else {
    filePath = mainPath + QString::number(currRow) + ".ini";}
}
