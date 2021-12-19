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
        QFile orgFile(":/Slots/Slots.ini");
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
        QFile orgFile(":/Slots/Config.ini");
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
        return QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + QString("/Slots/Slots.ini");
    }

    static QString pathToInitFileConfig()
    {
        return QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + QString("/Slots/Config.ini");
    }

    static void copyIniToDestDirColCols()
    {
        QFile destFile(pathToInitFileColCols());
        QFile orgFile(":/Colors/Colors.ini");
        if(destFile.exists()){
            QFile *ColCols = new QFile(pathToInitFileColCols());
            QTextStream in(ColCols);
            ColCols->open(QIODevice::ReadOnly | QIODevice::Text);
        } else {
            QFileInfo info(destFile.fileName());
            info.setFile(info.absolutePath());
            if(!info.exists()){
                QDir d;
                d.mkpath(info.absoluteFilePath());
            }
            orgFile.copy(destFile.fileName());
            destFile.setPermissions(QFile::WriteUser | destFile.permissions());

            QFile *ColCols = new QFile(pathToInitFileColCols());
            QTextStream in(ColCols);

            QString write = "Default\n"
                            "#ffaa00\n"
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
                            "#000000\n";

            ColCols->open(QIODevice::ReadWrite | QIODevice::Text);
            ColCols->write(write.toUtf8());
            ColCols->close();
        }
    }

    static void copyIniToDestDirColConfig()
    {
        QFile destFile(pathToInitFileColConfig());
        QFile orgFile(":/Colors/Config.ini");
        if(destFile.exists()){
            QFile *ColConfig = new QFile(pathToInitFileColConfig());
            QTextStream in(ColConfig);
            ColConfig->open(QIODevice::ReadOnly | QIODevice::Text);
        } else {
            QFileInfo info(destFile.fileName());
            info.setFile(info.absolutePath());
            if(!info.exists()){
                QDir d;
                d.mkpath(info.absoluteFilePath());
            }
            orgFile.copy(destFile.fileName());
            destFile.setPermissions(QFile::WriteUser | destFile.permissions());

            QFile *ColConfig = new QFile(pathToInitFileColConfig());
            QTextStream in(ColConfig);

            QString write = pathToInitFileCol() + "Colors.ini";

            ColConfig->open(QIODevice::ReadWrite | QIODevice::Text);
            ColConfig->write(write.toUtf8());
            ColConfig->close();
        }
    }

    static QString pathToInitFileColCols()
    {
        return QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + QString("/Colors/Colors.ini");
    }

    static QString pathToInitFileColConfig()
    {
        return QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + QString("/Colors/Config.ini");
    }

    static QString pathToInitFileCol()
    {
        return QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + QString("/Colors/");
    }
};

#endif // PREAPPTASKS_H
