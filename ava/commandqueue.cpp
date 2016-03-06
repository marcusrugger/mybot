#include "commandqueue.h"
#include "mcore.h"


CommandQueue::CommandQueue(void)
:   _latch(NULL)
{}


bool CommandQueue::add(Command *cmd)
{
    return _queue.push(cmd);
}


void CommandQueue::reset(void)
{
    resetLatch();
    _queue.reset();
}


void CommandQueue::setLatch(Latch *latch)
{
    if (_latch && _latch != latch)
        resetLatch();

    _latch = latch;
}


void CommandQueue::tick(void)
{
    if (isWaitingOnLatch())
        return;

    resetLatch();

    if (_queue.isMore())
    {
        Command *cmd = _queue.pull();
        cmd->execute();
        delete cmd;
    }
}


bool CommandQueue::isWaitingOnLatch(void)
{
    return _latch ? !_latch->isLatched() : false;
}


void CommandQueue::resetLatch(void)
{
    if (_latch)
    {
        delete _latch;
        _latch = NULL;
    }
}