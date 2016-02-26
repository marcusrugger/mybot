#include <Arduino.h>
#include "scheduler.h"


Scheduler *Scheduler::_instance;


Scheduler *Scheduler::instance(void)
{
    if (NULL == _instance)
        _instance = new Scheduler();

    return _instance;
}


Scheduler::Scheduler(void)
:   _count(0)
{}


void Scheduler::tick(void)
{
}


void Scheduler::schedule(Tickable *task)
{
    if (_count < MAX_TASKS)
        _tasks[_count++] = task;
}
