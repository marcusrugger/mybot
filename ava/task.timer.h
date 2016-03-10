#ifndef TASK_TIMER_H
#define TASK_TIMER_H

#include "interfaces.h"


class TimerTask : public Runnable
{
public:

    TimerTask(Runnable *task, unsigned long milli);

    void setTimer(unsigned long milli);
    void run(void);


private:

    Runnable *_task;
    unsigned long _wait_time;
    unsigned long _wait_start;
    bool _paused;


    inline bool isTriggered(void)
    { return millis() - _wait_start > _wait_time; }

};


#endif
