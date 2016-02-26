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
    for (unsigned int i = 0; i < _count; ++i)
        _tasks[i]->tick();
}


void TaskRunner::schedule(Tickable *task)
{
    if (_count < MAX_TASKS)
        _tasks[_count++] = task;
}
