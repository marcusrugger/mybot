#include "latch.timer.h"


TimerLatch::TimerLatch(unsigned long wait)
:   _wait_time(wait),
    _wait_start(millis())
{}


bool TimerLatch::isLatched(void)
{
    return millis() - _wait_start > _wait_time;
}
