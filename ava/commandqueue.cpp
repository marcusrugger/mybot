#include "commandqueue.h"
#include "mcore.h"


CommandQueue::CommandQueue(void)
:   _paused(0)
{}


bool CommandQueue::add(Command *cmd)
{
    return _queue.push(cmd);
}


void CommandQueue::pause(int milli)
{
    _paused = milli_to_ticks(milli);
}


void CommandQueue::reset(void)
{
    _queue.reset();
}


void CommandQueue::tick(void)
{
    if (_paused > 0)
    {
        --_paused;
        return;
    }

    if (_queue.isMore())
        _queue.pull()->execute();
}
