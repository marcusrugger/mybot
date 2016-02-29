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

    Timer(Tickable *tickee, uint16_t milli)
    :   _tickee(tickee)
    {
        setTimer(milli);
    }

    void setTimer(uint16_t milli)
    {
        _ticks      = milli_to_ticks(milli);
        _countdown  = _ticks;
    }

    void tick(void)
    {
        if (0 == --_countdown)
        {
            _tickee->tick();
            _countdown = _ticks;
        }
    }


private:

    Tickable *_tickee;
    uint16_t _ticks;
    uint16_t _countdown;

};

#endif
