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

        static void copyIniToDestDir()
        {
            QFile destFile(pathToInitFile());
            QFile orgFile(":/Config.ini");
            if(destFile.exists()){
                QFile *config = new QFile(pathToInitFile());
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

                QFile *config = new QFile(pathToInitFile());
                QTextStream in(config);

                QString write = "Slot 1\n"
                                "Quick red fox\n"
                                "A quick red fox jumped over a lazy dog.\n"
                                "Slot 2\n\n\nSlot 3\n\n\nSlot 4\n\n\nSlot 5\n\n\nSlot 6\n\n\nSlot 7\n\n\nSlot 8\n\n\nSlot 9\n\n\nSlot 10\n\n\n"
                                "Slot 11\n\n\nSlot 12\n\n\nSlot 13\n\n\nSlot 14\n\n\nSlot 15\n\n\nSlot 16\n\n\nSlot 17\n\n\nSlot 18\n\n\nSlot 19\n\n\nSlot 20\n\n";

                config->open(QIODevice::ReadWrite | QIODevice::Text);
                config->write(write.toUtf8());
                config->close();
            }
        }

        static QString pathToInitFile()
        {
            return QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + QString("/Config.ini");
        }
};

#endif // PREAPPTASKS_H
