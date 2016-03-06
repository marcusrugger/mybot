#ifndef LATCH_TIMER_H
#define LATCH_TIMER_H

#include "interfaces.h"


class TimerLatch : public Latch
{
public:

    TimerLatch(unsigned long wait);

    bool isLatched(void);


private:

    unsigned long _wait_time;
    unsigned long _wait_start;

};


#endif
