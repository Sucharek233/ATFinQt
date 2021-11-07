#include "mainwindow.h"
#include "preapptasks.h"

#include <QApplication>
#include <QIODevice>
#include <QTextStream>
#include <QProcess>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
        QCoreApplication::setApplicationName("ATFinQt");

        PreAppTasks::copyIniToDestDir();

        QString pathToPersitentIni = PreAppTasks::pathToInitFile();
        qDebug() << pathToPersitentIni;

        //Write Simple sentence to Local iniFile
        QFile writeAbleIniFile(pathToPersitentIni);
        if(!writeAbleIniFile.open(QIODevice::ReadWrite |QIODevice::Append)){
            qDebug() << "Could not open local ini file" << writeAbleIniFile.errorString() << writeAbleIniFile.error();
            return -1;
        }
    MainWindow w;
    w.show();
    return a.exec();
}
