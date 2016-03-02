#ifndef COMMANDQUEUE_H
#define COMMANDQUEUE_H

#include "interfaces.h"
#include "stdqueue.h"


class CommandQueue : public Tickable
{
public:

    CommandQueue(void);

    bool add(Command *cmd);
    void pause(int milli);
    void reset(void);

    void tick(void);


private:

    StdQueue<Command *> _queue;
    int _paused;

};


#endif
