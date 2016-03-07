#include "latch.timer.h"
#include "robot.h"


TimerLatch::TimerLatch(unsigned long wait)
:   _wait_time(wait),
    _wait_start(Robot::getMillis())
{}


bool TimerLatch::isLatched(void)
{
    return Robot::getMillis() - _wait_start > _wait_time;
}
