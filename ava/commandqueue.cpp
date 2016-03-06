#include "commandqueue.h"
#include "mcore.h"


CommandQueue::CommandQueue(void)
:   _paused(false),
    _wait_time(0),
    _wait_start(0)
{}


bool CommandQueue::add(Command *cmd)
{
    return _queue.push(cmd);
}


void CommandQueue::pause(unsigned long milli)
{
    _wait_start = millis();
    _wait_time = milli;
    _paused = true;
}


void CommandQueue::reset(void)
{
    _paused = 0;
    _queue.reset();
}


void CommandQueue::tick(void)
{
    if (isPaused())
        return;

    if (_queue.isMore())
    {
        Command *cmd = _queue.pull();
        cmd->execute();
        delete cmd;
    }
}


bool CommandQueue::isPaused(void)
{
    return _paused = _paused ? millis() - _wait_start < _wait_time : false;
}
