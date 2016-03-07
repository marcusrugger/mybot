#include <Arduino.h>
#include "scheduler.h"


TaskRunner *TaskRunner::_instance = NULL;


TaskRunner *TaskRunner::instance(void)
{
    if (NULL == _instance)
        _instance = new TaskRunner();

    return _instance;
}


TaskRunner::TaskRunner(void)
:   _count(0)
{}


void TaskRunner::tick(void)
{
    while (true)
    {
        Robot::setMillis(millis());
        for (unsigned int i = 0; i < _count; ++i)
            _tasks[i]->tick();
    }
}


void TaskRunner::schedule(Tickable *task)
{
    if (_count < MAX_TASKS)
        _tasks[_count++] = task;
}


void TaskRunner::unschedule(Tickable *task)
{
    unsigned int is, id;
    for (is = id = 0; is < _count; )
    {
        if (_tasks[is] == task)
        {
            if (++is < _count)
                _tasks[id++] = _tasks[is++];
            --_count;
        }
        else if (id < is)
            _tasks[id++] = _tasks[is++];
        else
            id = ++is;
    }
}
