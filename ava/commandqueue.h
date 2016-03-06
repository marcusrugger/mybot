#ifndef COMMANDQUEUE_H
#define COMMANDQUEUE_H

#include "interfaces.h"
#include "stdqueue.h"


class CommandQueue : public Tickable
{
public:

    CommandQueue(void);

    bool add(Command *cmd);
    void pause(unsigned long milli);
    void reset(void);

    void tick(void);


private:

    StdQueue<Command *> _queue;
    bool _paused;
    unsigned long _wait_time;
    unsigned long _wait_start;

    bool isPaused(void);

};


#endif
