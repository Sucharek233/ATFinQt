#include "additionalinfogetter.h"

int seconds = 0;
int minutes = 0;

void additionalInfoGetter::run()
{
    seconds = 0;
    minutes = 0;

    isRunning = 1;
    while(isRunning == 1)
    {
        timeSeconds = timeSeconds + 1;
        setTimeSeconds(timeSeconds);

        seconds = seconds + 1;
        if (seconds > 59) {seconds = 0; minutes = minutes + 1;}

        if (seconds < 10) {time = "Time: " + QString::number(minutes) + ":0" + QString::number(seconds);}
        else {time = "Time: " + QString::number(minutes) + ":" + QString::number(seconds);}

        emit signalValueUpdated(time);
        sleep(1);
    }
}

void additionalInfoGetter::stopRunning()
{
    isRunning = 0;
}
