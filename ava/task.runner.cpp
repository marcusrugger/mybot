#include <Arduino.h>
#include "task.runner.h"


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


void TaskRunner::run(void)
{
    for (unsigned int i = 0; i < _count; ++i)
        _tasks[i]->run();
}


void TaskRunner::schedule(Runnable *task)
{
    if (_count < MAX_TASKS)
        _tasks[_count++] = task;
}


void TaskRunner::unschedule(Runnable *task)
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
