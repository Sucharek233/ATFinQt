#ifndef ADDITIONALINFOGETTER_H
#define ADDITIONALINFOGETTER_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QDebug>
#include <QElapsedTimer>

class additionalInfoGetter : public QThread
{
    Q_OBJECT
public:
    QString getTime() { return time; }
    int getTimeSeconds() { return timeSeconds; }
    void setTimeSeconds(int set) {timeSeconds = set;}

public slots:
    void stopRunning();

protected:
    virtual void run();

signals:
   void signalValueUpdated(QString);

private:
    bool isRunning;
    QString time;
    int timeSeconds = 0;
};

#endif // ADDITIONALINFOGETTER_H
