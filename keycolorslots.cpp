#include "keycolorslots.h"
#include "ui_keycolorslots.h"

QString mainPath;

int fileCount;

int currRow;

QString messBoxStyleSheet;
QString inputDialogStyleSheet;

QString filePathHere;

void keyColorSlots::lightColSlots()
{
    keyColorSlots::setStyleSheet("background-color: rgb(244, 244, 244);");
    QString button = "color: black; background-color: rgb(244, 244, 244);";
    ui->pushButton_Add->setStyleSheet(button);
    ui->pushButton_Remove->setStyleSheet(button);
    ui->pushButton_Rename->setStyleSheet(button);
    ui->buttonBox->setStyleSheet("QPushButton {color: black; background-color: rgb(244, 244, 244); font-size: 14px;}");
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
    ui->pushButton_Rename->setStyleSheet(button);
    ui->buttonBox->setStyleSheet("QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 14px;}");
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
    filePathHere = filePath;
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
    QFile *file = new QFile(mainPath + "Config.ini");
    file->open(QIODevice::ReadOnly);
    QString used = file->readLine();
    if (used == mainPath + "Colors.ini") {
        ui->listWidget_Slots->setCurrentRow(0);
    } else {
        used.chop(4);
        int select = QString(used.back()).toInt();
        ui->listWidget_Slots->setCurrentRow(select);
    }
}

void keyColorSlots::rearrange()
{
    for (int i = 1; i < fileCount - 1; i++) {
        int fi = i;
        QString path = mainPath + QString::number(i) + ".ini";
        QFile file(path);
        qDebug() << "current file check:" << QString::number(i);
        while (!file.exists()) {
            fi = fi + 1;
            QString path = mainPath + QString::number(fi) + ".ini";
            QFile check(path);
            qDebug() << "old path:" << path;
            if (check.exists()) {
                check.open(QIODevice::ReadWrite);
                QString contents = check.readAll();
                check.close();
                check.remove();
                QFile renamed(mainPath + QString::number(i) + ".ini");
                qDebug() << "new path:" << QString(mainPath + QString::number(i) + ".ini");
                renamed.open(QIODevice::ReadWrite);
                renamed.resize(0);
                renamed.write(contents.toUtf8());
                break;
            }
        }
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
            ui->listWidget_Slots->setCurrentRow(ui->listWidget_Slots->count() - 1);
        }
    }
}

void keyColorSlots::on_pushButton_Remove_clicked()
{
    if (currRow != -1) {
        if (currRow == 0) {
            QMessageBox def;
            def.setWindowTitle("Default slot");
            def.setText("Warning! You can't delete the default slot, beacuse\n"
                        "the colors just don't randomly appear!\n"
                        "Please DO NOT try to delete this file manually!!!");
            def.setStyleSheet(messBoxStyleSheet);
            def.exec();
        } else {
            QFile checkFile(mainPath + "Config.ini");
            checkFile.open(QIODevice::ReadOnly);
            QString check = checkFile.readLine();
            checkFile.close();
            if (check == QString(mainPath + QString::number(currRow) + ".ini")) {
                QMessageBox inUse;
                inUse.setWindowTitle("In use");
                inUse.setText("Warning! This slot is currently being used!\n"
                              "Please DO NOT try to delete files that are being used!");
                inUse.setStyleSheet(messBoxStyleSheet);
                inUse.exec();
            } else {
            int items = fileCount;
            int deletedItem = currRow + 1;

                if (items == deletedItem) {
                    QString path = mainPath + QString::number(currRow) + ".ini";
                    QFile file(path);
                    file.remove();
                    initialize();

                    ui->listWidget_Slots->setCurrentRow(ui->listWidget_Slots->count() - 1);
                } else {
                    QString path = mainPath + QString::number(currRow) + ".ini";
                    QFile file(path);
                    file.remove();

                    int count = currRow;

                    rearrange();
                    initialize();
                    ui->listWidget_Slots->setCurrentRow(count);
                }
            }
        }
    } else {
        QMessageBox un;
        un.setWindowTitle("Not selected");
        un.setText("Warning! You have not selected anything!\n"
                   "Please select a slot and click Open!");
        un.setStyleSheet(messBoxStyleSheet);
        un.exec();
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
        filePath = filePathHere;
        accept();
        close();
    } else {
        QMessageBox un;
        un.setWindowTitle("Not selected");
        un.setText("Warning! You have not selected anything!\n"
                   "Please select a slot and click Open!");
        un.setStyleSheet(messBoxStyleSheet);
        un.exec();
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
    if (currRow == 0) {filePathHere = mainPath + "Colors.ini";} else {
    filePathHere = mainPath + QString::number(currRow) + ".ini";}
}

void keyColorSlots::on_pushButton_Rename_clicked()
{
    if (currRow != -1) {
        if (currRow == 0) {
            QMessageBox def;
            def.setWindowTitle("Default slot");
            def.setText("Warning! You can't rename the default slot\n"
                        "Well, you can, but it doesn't make a difference.\n"
                        "The default slot will ALWAYS be named \"Default\".");
            def.setStyleSheet(messBoxStyleSheet);
            def.exec();
        } else {
            QFile *file = new QFile(filePathHere);
            QTextStream reading(file);
            reading.setCodec("UTF-8");
            file->open(QIODevice::ReadWrite);
            reading.readLine();
            QString contents;
            for (int i = 0; i < 19; i++) {
                contents = contents + reading.readLine() + "\n";
            }
            QInputDialog rename;
            rename.setWindowTitle("Rename");
            rename.setLabelText("Type in a new name.");
            rename.setInputMode(QInputDialog::TextInput);
            rename.setStyleSheet(inputDialogStyleSheet);
            if (rename.exec() == QInputDialog::Accepted) {
                QString text = rename.textValue();
                text = text.simplified();

                if (text == "") {
                    QMessageBox empty;
                    empty.setWindowTitle("Empty");
                    empty.setText("You've not entered a name!\nPlease enter a name and click OK!");
                    empty.setStyleSheet(messBoxStyleSheet);
                    empty.exec();
                } else {
                    file->resize(0);
                    file->write(text.toUtf8() + "\n" + contents.toUtf8());
                }
            file->close();
            int saveCurrRow = currRow;
            initialize();
            ui->listWidget_Slots->setCurrentRow(saveCurrRow);
            }
        }
    } else {
        QMessageBox un;
        un.setWindowTitle("Not selected");
        un.setText("Warning! You have not selected anything!\n"
                   "Please select a slot and click Remove!");
        un.setStyleSheet(messBoxStyleSheet);
        un.exec();
    }
}
