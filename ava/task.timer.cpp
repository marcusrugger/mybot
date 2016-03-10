#include "task.timer.h"


TimerTask::TimerTask(Runnable *task, unsigned long milli)
:   _task(task)
{
    setTimer(milli);
}


void TimerTask::setTimer(unsigned long milli)
{
    _wait_start = millis();
    _wait_time = milli;
}


void TimerTask::run(void)
{
    if (isTriggered())
    {
        _wait_start = millis();
        _task->run();
    }
}
