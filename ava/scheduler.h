#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "mcore.h"
#include "interfaces.h"


class TaskRunner : public Tickable,
                   public Scheduler
{
public:

    static TaskRunner *instance(void);

    void tick(void);
    void schedule(Tickable *task);
    void unschedule(Tickable *task);

private:

    TaskRunner(void);

    static TaskRunner *_instance;

    static const unsigned int MAX_TASKS = 8;
    Tickable *_tasks[MAX_TASKS];
    unsigned int _count = 0;

};


class Timer : public Tickable
{
public:

    Timer(Tickable *tickee, unsigned long milli)
    :   _tickee(tickee)
    {
        setTimer(milli);
    }

    void setTimer(unsigned long milli)
    {
        _wait_start = millis();
        _wait_time = milli;
    }

    void tick(void)
    {
        if (isTriggered())
        {
            _wait_start = millis();
            _tickee->tick();
        }
    }


private:

    Tickable *_tickee;
    unsigned long _wait_time;
    unsigned long _wait_start;
    bool _paused;


    bool isTriggered(void)
    { return millis() - _wait_start < _wait_time; }

};

#endif
