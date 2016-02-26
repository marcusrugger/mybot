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
{}


void Scheduler::tick(void)
{}
