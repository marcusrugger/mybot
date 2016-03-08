#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "mcore.h"
#include "interfaces.h"
#include "robot.h"


class TaskRunner : public Runnable,
                   public Scheduler
{
public:

    static TaskRunner *instance(void);

    void run(void);
    void schedule(Runnable *task);
    void unschedule(Runnable *task);

private:

    TaskRunner(void);

    static TaskRunner *_instance;

    static const unsigned int MAX_TASKS = 8;
    Runnable *_tasks[MAX_TASKS];
    unsigned int _count = 0;

};


class Timer : public Runnable
{
public:

    Timer(Runnable *tickee, unsigned long milli)
    :   _tickee(tickee)
    {
        setTimer(milli);
    }

    void setTimer(unsigned long milli)
    {
        _wait_start = millis();
        _wait_time = milli;
    }

    void run(void)
    {
        if (isTriggered())
        {
            _wait_start = millis();
            _tickee->run();
        }
    }


private:

    Runnable *_tickee;
    unsigned long _wait_time;
    unsigned long _wait_start;
    bool _paused;


    bool isTriggered(void)
    { return millis() - _wait_start > _wait_time; }

};

#endif
