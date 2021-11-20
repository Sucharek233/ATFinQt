#ifndef PREAPPTASKS_H
#define PREAPPTASKS_H

#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QStandardPaths>
#include <QDebug>

class PreAppTasks
{
public:
    PreAppTasks() = default;

    static void copyIniToDestDirSlots()
    {
        QFile destFile(pathToInitFileSlots());
        QFile orgFile(":/Slots.ini");
        if(destFile.exists()){
            QFile *Slots = new QFile(pathToInitFileSlots());
            QTextStream in(Slots);
            Slots->open(QIODevice::ReadOnly | QIODevice::Text);
        } else {
            QFileInfo info(destFile.fileName());
            info.setFile(info.absolutePath());
            if(!info.exists()){
                QDir d;
                d.mkpath(info.absoluteFilePath());
            }
            orgFile.copy(destFile.fileName());
            destFile.setPermissions(QFile::WriteUser | destFile.permissions());

            QFile *Slots = new QFile(pathToInitFileSlots());
            QTextStream in(Slots);

            QString write = "Quick red fox\n"
                            "A quick red fox jumped over a lazy dog.\n";

            Slots->open(QIODevice::ReadWrite | QIODevice::Text);
            Slots->write(write.toUtf8());
            Slots->close();
        }
    }

    static void copyIniToDestDirConfig()
    {
        QFile destFile(pathToInitFileConfig());
        QFile orgFile(":/Config.ini");
        if(destFile.exists()){
            QFile *config = new QFile(pathToInitFileConfig());
            QTextStream in(config);
            config->open(QIODevice::ReadOnly | QIODevice::Text);
        } else {
            QFileInfo info(destFile.fileName());
            info.setFile(info.absolutePath());
            if(!info.exists()){
                QDir d;
                d.mkpath(info.absoluteFilePath());
            }
            orgFile.copy(destFile.fileName());
            destFile.setPermissions(QFile::WriteUser | destFile.permissions());

            QFile *config = new QFile(pathToInitFileConfig());
            QTextStream in(config);

            QString write = "1";

            config->open(QIODevice::ReadWrite | QIODevice::Text);
            config->write(write.toUtf8());
            config->close();
        }
    }

    static QString pathToInitFileSlots()
    {
        return QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + QString("/Slots.ini");
    }

    static QString pathToInitFileConfig()
    {
        return QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + QString("/Config.ini");
    }
};

#endif // PREAPPTASKS_H
