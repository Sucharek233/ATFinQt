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

        PreAppTasks::copyIniToDestDirCourses();

        QString pathToPersitentIniCourses = PreAppTasks::pathToInitFileCourses();
        qDebug() << pathToPersitentIniCourses;

        QFile writeAbleIniFileCourses(pathToPersitentIniCourses);
        if(!writeAbleIniFileCourses.open(QIODevice::ReadWrite |QIODevice::Append)){
            qDebug() << "Could not open local ini file" << writeAbleIniFileCourses.errorString() << writeAbleIniFileCourses.error();
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

        QString pathToPersitentIniColConfig = PreAppTasks::pathToInitFileColConfig();
        qDebug() << pathToPersitentIniColConfig;

        QFile writeAbleIniFileColConfig(pathToPersitentIniColConfig);
        if(!writeAbleIniFileColConfig.open(QIODevice::ReadWrite |QIODevice::Append)){
            qDebug() << "Could not open local ini file" << writeAbleIniFileColConfig.errorString() << writeAbleIniFileColConfig.error();
            return -1;
        }

        PreAppTasks::copyIniToDestDirMapMapping();

        QString pathToPersitentIniMapMapping = PreAppTasks::pathToInitFileMapMapping();
        qDebug() << pathToPersitentIniMapMapping;

        QFile writeAbleIniFileMapMapping(pathToPersitentIniMapMapping);
        if(!writeAbleIniFileMapMapping.open(QIODevice::ReadWrite |QIODevice::Append)){
            qDebug() << "Could not open local ini file" << writeAbleIniFileMapMapping.errorString() << writeAbleIniFileMapMapping.error();
            return -1;
        }


        PreAppTasks::copyIniToDestDirMapConfig();

        QString pathToPersitentIniMapConfig = PreAppTasks::pathToInitFileMapConfig();
        qDebug() << pathToPersitentIniMapConfig;

        QFile writeAbleIniFileMapConfig(pathToPersitentIniMapConfig);
        if(!writeAbleIniFileMapConfig.open(QIODevice::ReadWrite |QIODevice::Append)){
            qDebug() << "Could not open local ini file" << writeAbleIniFileMapConfig.errorString() << writeAbleIniFileMapConfig.error();
            return -1;
        }

    MainWindow w;
    w.show();
    return a.exec();
}
