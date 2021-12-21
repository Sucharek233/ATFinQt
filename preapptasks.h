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

    static void copyIniToDestDirMapMapping()
    {
        QFile destFile(pathToInitFileMapMapping());
        QFile orgFile(":/Mapping/Mapping.ini");
        if(destFile.exists()){
            QFile *MapMapps = new QFile(pathToInitFileMapMapping());
            QTextStream in(MapMapps);
            MapMapps->open(QIODevice::ReadOnly | QIODevice::Text);
        } else {
            QFileInfo info(destFile.fileName());
            info.setFile(info.absolutePath());
            if(!info.exists()){
                QDir d;
                d.mkpath(info.absoluteFilePath());
            }
            orgFile.copy(destFile.fileName());
            destFile.setPermissions(QFile::WriteUser | destFile.permissions());

            QFile *MapMapps = new QFile(pathToInitFileMapMapping());
            QTextStream in(MapMapps);

            QString write = "Default\n"
                            "~​\n1\n2\n3\n4\n5\n6\n7\n8\n9\n0\n-\n=\n⌫\n"
                            "tab\nq\nw\ne\nr\nt\ny\nu\ni\no\np\n[\n]\n\\\n"
                            "caps\na\ns\nd\nf\ng\nh\nj\nk\nl\n;\n'\n⏎\n"
                            "⇧\nz\nx\nc\nv\nb\nn\nm\n,\n.\n/\n⇧\n"
                            "ctrl\nsu\nalt\n \nalt\nme\nctrl\n"
                            "~\n!\n@\n#\n$\n%\n^\n&\n*\n(\n)\n_\n+\n⌫\n"
                            "tab\nQ\nW\nE\nR\nT\nY\nU\nI\nO\nP\n{\n}\n|\n"
                            "caps\nA\nS\nD\nF\nG\nH\nJ\nK\nL\n:\n\"\n⏎\n"
                            "⇧\nZ\nX\nC\nV\nB\nN\nM\n<\n>\n?\n⇧\n"
                            "ctrl\nsu\nalt\n \nalt\nme\nctrl\n";

            MapMapps->open(QIODevice::ReadWrite | QIODevice::Text);
            MapMapps->write(write.toUtf8());
            MapMapps->close();
        }
    }

    static void copyIniToDestDirMapConfig()
    {
        QFile destFile(pathToInitFileMapConfig());
        QFile orgFile(":/Mapping/Config.ini");
        if(destFile.exists()){
            QFile *MapConfig = new QFile(pathToInitFileMapConfig());
            QTextStream in(MapConfig);
            MapConfig->open(QIODevice::ReadOnly | QIODevice::Text);
        } else {
            QFileInfo info(destFile.fileName());
            info.setFile(info.absolutePath());
            if(!info.exists()){
                QDir d;
                d.mkpath(info.absoluteFilePath());
            }
            orgFile.copy(destFile.fileName());
            destFile.setPermissions(QFile::WriteUser | destFile.permissions());

            QFile *MapConfig = new QFile(pathToInitFileMapConfig());
            QTextStream in(MapConfig);

            QString write = pathToInitFileMap() + "Mapping.ini";

            MapConfig->open(QIODevice::ReadWrite | QIODevice::Text);
            MapConfig->write(write.toUtf8());
            MapConfig->close();
        }
    }

    static QString pathToInitFileMapMapping()
    {
        return QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + QString("/Mapping/Mapping.ini");
    }

    static QString pathToInitFileMapConfig()
    {
        return QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + QString("/Mapping/Config.ini");
    }

    static QString pathToInitFileMap()
    {
        return QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + QString("/Mapping/");
    }
};

#endif // PREAPPTASKS_H
