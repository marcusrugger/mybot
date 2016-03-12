#ifndef HARDWARE_BUZZER_H
#define HARDWARE_BUZZER_H

#include "interfaces.h"
#include "mcore.h"
#include "task.timer.h"


class SimpleBuzzer : public Runnable
{
public:

    static SimpleBuzzer *create(int pinNumber, Scheduler *scheduler);

    void soundUserAlert(void);

private:

    SimpleBuzzer(int pinNumber, Scheduler *scheduler);

    static const int TONE = 200;
    static const int DURATION = 500;
    Scheduler *_scheduler;
    int _pinNumber;
    TimerTask _timer;
    int _countDown;

    void run(void);

};

#endif
