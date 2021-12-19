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

        PreAppTasks::copyIniToDestDirSlots();

        QString pathToPersitentIniSlots = PreAppTasks::pathToInitFileSlots();
        qDebug() << pathToPersitentIniSlots;

        QFile writeAbleIniFileSlots(pathToPersitentIniSlots);
        if(!writeAbleIniFileSlots.open(QIODevice::ReadWrite |QIODevice::Append)){
            qDebug() << "Could not open local ini file" << writeAbleIniFileSlots.errorString() << writeAbleIniFileSlots.error();
            return -1;
        }


        PreAppTasks::copyIniToDestDirConfig();

        QString pathToPersitentIniConfig = PreAppTasks::pathToInitFileConfig();
        qDebug() << pathToPersitentIniConfig;

        QFile writeAbleIniFileConfig(pathToPersitentIniConfig);
        if(!writeAbleIniFileConfig.open(QIODevice::ReadWrite |QIODevice::Append)){
            qDebug() << "Could not open local ini file" << writeAbleIniFileConfig.errorString() << writeAbleIniFileConfig.error();
            return -1;
        }

        PreAppTasks::copyIniToDestDirColCols();

        QString pathToPersitentIniColCols = PreAppTasks::pathToInitFileColCols();
        qDebug() << pathToPersitentIniColCols;

        QFile writeAbleIniFileColCols(pathToPersitentIniColCols);
        if(!writeAbleIniFileColCols.open(QIODevice::ReadWrite |QIODevice::Append)){
            qDebug() << "Could not open local ini file" << writeAbleIniFileColCols.errorString() << writeAbleIniFileColCols.error();
            return -1;
        }


        PreAppTasks::copyIniToDestDirColConfig();

        QString pathToPersitentIniColConfig = PreAppTasks::pathToInitFileConfig();
        qDebug() << pathToPersitentIniColConfig;

        QFile writeAbleIniFileColConfig(pathToPersitentIniColConfig);
        if(!writeAbleIniFileColConfig.open(QIODevice::ReadWrite |QIODevice::Append)){
            qDebug() << "Could not open local ini file" << writeAbleIniFileColConfig.errorString() << writeAbleIniFileColConfig.error();
            return -1;
        }

    MainWindow w;
    w.show();
    return a.exec();
}
