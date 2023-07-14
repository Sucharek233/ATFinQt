#include "keymappingslots.h"
#include "ui_keymappingslots.h"

QString MainPath;
QString FilePathHere;

int FileCount;

int CurrRow;

QString MessBoxStyleSheet;
QString InputDialogStyleSheet;

keyMappingSlots::keyMappingSlots(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::keyMappingSlots)
{
    ui->setupUi(this);

    MainPath = Paths.pathToInitFileMap();

    QFile file(Paths.pathToInitFileMapConfig());
    file.open(QIODevice::ReadOnly);
    FilePath = file.readLine();
    FilePathHere = FilePath;
    file.close();

    Initialize();
    lightMapSlots();
}

void keyMappingSlots::Initialize()
{
    ui->listWidget_Slots->clear();

    QDir count(MainPath);
    FileCount = count.count() - 3;

    ui->listWidget_Slots->addItem("Default");

    for (int i = 1; i < FileCount; i++) {
        QFile *file = new QFile(MainPath + QString::number(i) + ".ini");
        QTextStream reading(file);
        file->open(QIODevice::ReadOnly);
        ui->listWidget_Slots->addItem(reading.readLine());
        file->close();
    }
    QFile *file = new QFile(MainPath + "Config.ini");
    file->open(QIODevice::ReadOnly);
    QString used = file->readLine();
    if (used == MainPath + "Mapping.ini") {
        ui->listWidget_Slots->setCurrentRow(0);
    } else {
        used.chop(4);
        int select = QString(used.back()).toInt();
        ui->listWidget_Slots->setCurrentRow(select);
    }
}

void keyMappingSlots::Rearrange()
{
    for (int i = 1; i < FileCount - 1; i++) {
        int fi = i;
        QString path = MainPath + QString::number(i) + ".ini";
        QFile file(path);
        qDebug() << "current file check:" << QString::number(i);
        while (!file.exists()) {
            fi = fi + 1;
            QString path = MainPath + QString::number(fi) + ".ini";
            QFile check(path);
            qDebug() << "old path:" << path;
            if (check.exists()) {
                check.open(QIODevice::ReadWrite);
                QString contents = check.readAll();
                check.close();
                check.remove();
                QFile renamed(MainPath + QString::number(i) + ".ini");
                qDebug() << "new path:" << QString(MainPath + QString::number(i) + ".ini");
                renamed.open(QIODevice::ReadWrite);
                renamed.resize(0);
                renamed.write(contents.toUtf8());
                break;
            }
        }
    }
}

void keyMappingSlots::lightMapSlots()
{
    keyMappingSlots::setStyleSheet("background-color: rgb(244, 244, 244);");
    QString button = "color: black; background-color: rgb(244, 244, 244);";
    ui->pushButton_Add->setStyleSheet(button);
    ui->pushButton_Remove->setStyleSheet(button);
    ui->pushButton_Rename->setStyleSheet(button);
    ui->buttonBox->setStyleSheet("QPushButton {color: black; background-color: rgb(244, 244, 244); font-size: 14px;}");
    ui->label_Main->setStyleSheet("color: black;");
    ui->listWidget_Slots->setStyleSheet("QListWidget {background-color: white; border: 0.5px solid grey;}"
                                        "QListWidget::item {color: black; background-color: white;}"
                                        "QListWidget::item:selected {color: white; background-color: rgb(0, 120, 215); border: 0.5px solid black;}");
    MessBoxStyleSheet = "QMessageBox {background-color: rgb(244, 244, 244);}"
                        "QLabel {background-color: rgb(244, 244, 244); color: black; font-size: 16px;}"
                        "QPushButton {color: black; background-color: rgb(244, 244, 244); font-size: 14px;}";
    InputDialogStyleSheet = "QInputDialog {background-color: rgb(244, 244, 244);}"
                            "QLabel {background-color: rgb(244, 244, 244); color: black; font-size: 16px;}"
                            "QLineEdit {color: black; background-color: white; font-size: 14px;}"
                            "QPushButton {color: black; background-color: rgb(244, 244, 244); font-size: 12px;}";
}
void keyMappingSlots::darkMapSlots()
{
    keyMappingSlots::setStyleSheet("background-color: rgb(6, 6, 14);");
    QString button = "color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);";
    ui->pushButton_Add->setStyleSheet(button);
    ui->pushButton_Remove->setStyleSheet(button);
    ui->pushButton_Rename->setStyleSheet(button);
    ui->buttonBox->setStyleSheet("QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 14px;}");
    ui->label_Main->setStyleSheet("color: rgb(211, 213, 201);");
    ui->listWidget_Slots->setStyleSheet("QListWidget {background-color: rgb(36, 36, 44); border: 1px solid rgb(66, 66, 74);}"
                                          "QListWidget::item {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);}"
                                          "QListWidget::item:selected {color: rgb(211, 213, 201); background-color: rgb(66, 66, 74); border: 0.5px solid black;}");
    MessBoxStyleSheet = "QMessageBox {background-color: rgb(6, 6, 14);}"
                        "QLabel {background-color: rgb(6, 6, 14); color: rgb(211, 213, 201); font-size: 16px;}"
                        "QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 14px;}";
    InputDialogStyleSheet = "QInputDialog {background-color: rgb(6, 6, 14);}"
                            "QLabel {background-color: rgb(6, 6, 14); color: rgb(211, 213, 201); font-size: 16px;}"
                            "QLineEdit {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 14px;}"
                            "QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 12px;}";
}

keyMappingSlots::~keyMappingSlots()
{
    delete ui;
}

void keyMappingSlots::on_pushButton_Add_clicked()
{
    QInputDialog name;
    name.setWindowTitle("Set name");
    name.setLabelText("Type in a name.");
    name.setInputMode(QInputDialog::TextInput);
    name.setStyleSheet(InputDialogStyleSheet);
    if (name.exec() == QInputDialog::Accepted) {
        QString text = name.textValue();
        text = text.simplified();

        if (text == "") {
            QMessageBox empty;
            empty.setWindowTitle("Empty");
            empty.setText("You've not entered a name!\nPlease enter a name and click OK!");
            empty.setStyleSheet(MessBoxStyleSheet);
            empty.exec();
        } else {
            QFile file(MainPath + QString::number(FileCount) + ".ini");
            file.open(QIODevice::ReadWrite);
            file.write(text.toUtf8() +
                       "\n~​\n1\n2\n3\n4\n5\n6\n7\n8\n9\n0\n-\n=\n⌫\n"
                       "tab\nq\nw\ne\nr\nt\ny\nu\ni\no\np\n[\n]\n\\\n"
                       "caps\na\ns\nd\nf\ng\nh\nj\nk\nl\n;\n'\n⏎\n"
                       "⇧\nz\nx\nc\nv\nb\nn\nm\n,\n.\n/\n⇧\n"
                       "ctrl\nsu\nalt\n \nalt\nme\nctrl\n"
                       "~\n!\n@\n#\n$\n%\n^\n&\n*\n(\n)\n_\n+\n⌫\n"
                       "tab\nQ\nW\nE\nR\nT\nY\nU\nI\nO\nP\n{\n}\n|\n"
                       "caps\nA\nS\nD\nF\nG\nH\nJ\nK\nL\n:\n\"\n⏎\n"
                       "⇧\nZ\nX\nC\nV\nB\nN\nM\n<\n>\n?\n⇧\n"
                       "ctrl\nsu\nalt\n \nalt\nme\nctrl\n");
            file.close();
            Initialize();
            ui->listWidget_Slots->setCurrentRow(ui->listWidget_Slots->count() - 1);
        }
    }
}

void keyMappingSlots::on_pushButton_Remove_clicked()
{
    if (CurrRow != -1) {
        if (CurrRow == 0) {
            QMessageBox def;
            def.setWindowTitle("Default slot");
            def.setText("Warning! You can't delete the default slot, beacuse\n"
                        "the keys just don't randomly appear!\n"
                        "Please DO NOT try to delete this file manually!!!");
            def.setStyleSheet(MessBoxStyleSheet);
            def.exec();
        } else {
            QFile checkFile(MainPath + "Config.ini");
            checkFile.open(QIODevice::ReadOnly);
            QString check = checkFile.readLine();
            checkFile.close();
            if (check == QString(MainPath + QString::number(CurrRow) + ".ini")) {
                QMessageBox inUse;
                inUse.setWindowTitle("In use");
                inUse.setText("Warning! This slot is currently being used!\n"
                              "Please DO NOT try to delete files that are being used!");
                inUse.setStyleSheet(MessBoxStyleSheet);
                inUse.exec();
            } else {
                int items = FileCount;
                int deletedItem = CurrRow + 1;

                if (items == deletedItem) {
                    QString path = MainPath + QString::number(CurrRow) + ".ini";
                    QFile file(path);
                    file.remove();

                    Initialize();
                    ui->listWidget_Slots->setCurrentRow(ui->listWidget_Slots->count() - 1);
                } else {
                    QString path = MainPath + QString::number(CurrRow) + ".ini";
                    QFile file(path);
                    file.remove();

                    int count = CurrRow;

                    Rearrange();
                    Initialize();
                    ui->listWidget_Slots->setCurrentRow(count);
                }
            }
        }
    } else {
        QMessageBox un;
        un.setWindowTitle("Not selected");
        un.setText("Warning! You have not selected anything!\n"
                   "Please select a slot and click Remove!");
        un.setStyleSheet(MessBoxStyleSheet);
        un.exec();
    }
}

void keyMappingSlots::on_listWidget_Slots_currentRowChanged(int currentRow)
{
    CurrRow = currentRow;
    if (CurrRow == 0) {FilePathHere = MainPath + "Mapping.ini";} else {
    FilePathHere = MainPath + QString::number(CurrRow) + ".ini";}
}

void keyMappingSlots::on_pushButton_Rename_clicked()
{
    if (CurrRow != -1) {
        if (CurrRow == 0) {
            QMessageBox def;
            def.setWindowTitle("Default slot");
            def.setText("Warning! You can't rename the default slot\n"
                        "Well, you can, but it doesn't make a difference.\n"
                        "The default slot will ALWAYS be named \"Default\".");
            def.setStyleSheet(MessBoxStyleSheet);
            def.exec();
        } else {
            QFile *file = new QFile(FilePathHere);
            QTextStream reading(file);
            reading.setCodec("UTF-8");
            file->open(QIODevice::ReadWrite);
            reading.readLine();
            QString contents;
            for (int i = 0; i < 120; i++) {
                contents = contents + reading.readLine() + "\n";
            }
            QInputDialog rename;
            rename.setWindowTitle("Rename");
            rename.setLabelText("Type in a new name.");
            rename.setInputMode(QInputDialog::TextInput);
            rename.setStyleSheet(InputDialogStyleSheet);
            if (rename.exec() == QInputDialog::Accepted) {
                QString text = rename.textValue();
                text = text.simplified();

                if (text == "") {
                    QMessageBox empty;
                    empty.setWindowTitle("Empty");
                    empty.setText("You've not entered a name!\nPlease enter a name and click OK!");
                    empty.setStyleSheet(MessBoxStyleSheet);
                    empty.exec();
                } else {
                    file->resize(0);
                    file->write(text.toUtf8() + "\n" + contents.toUtf8());
                }
            file->close();
            int saveCurrRow = CurrRow;
            Initialize();
            ui->listWidget_Slots->setCurrentRow(saveCurrRow);
            }
        }
    } else {
        QMessageBox un;
        un.setWindowTitle("Not selected");
        un.setText("Warning! You have not selected anything!\n"
                   "Please select a slot and click Remove!");
        un.setStyleSheet(MessBoxStyleSheet);
        un.exec();
    }
}

void keyMappingSlots::on_buttonBox_accepted()
{
    if (CurrRow != -1) {
        QFile file(Paths.pathToInitFileMapConfig());
        file.open(QIODevice::ReadWrite);
        file.resize(0);
        if (CurrRow == 0) {
        file.write(QString(MainPath + "Mapping.ini").toUtf8());
        } else {file.write(QString(MainPath + QString::number(CurrRow) + ".ini").toUtf8());}
        file.close();
        FilePath = FilePathHere;
        accept();
        close();
    } else {
        QMessageBox un;
        un.setWindowTitle("Not selected");
        un.setText("Warning! You have not selected anything!\n"
                   "Please select a slot and click Open!");
        un.setStyleSheet(MessBoxStyleSheet);
        un.exec();
    }
}

void keyMappingSlots::on_buttonBox_rejected()
{
    reject();
    close();
}
