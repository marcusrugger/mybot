#ifndef COMMANDQUEUE_H
#define COMMANDQUEUE_H

#include "interfaces.h"
#include "stdqueue.h"


class CommandQueue : public Runnable
{
public:

    CommandQueue(void);

    bool add(Command *cmd);
    void reset(void);
    void setLatch(Latch *latch);

    void run(void);


private:

    StdQueue<Command *> _queue;
    Latch *_latch;

    bool isWaitingOnLatch(void);
    void resetLatch(void);

};


#endif
