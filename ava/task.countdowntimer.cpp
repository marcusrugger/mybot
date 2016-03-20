#include "task.countdowntimer.h"
#include "robot.h"


CountDownTimerTask *CountDownTimerTask::create(DataStream *writer, uint16_t timer)
{
    return new CountDownTimerTask(writer, timer);
}


CountDownTimerTask::CountDownTimerTask(DataStream *writer, uint16_t timer)
:   _writer(writer),
    _timer(timer)
{}


void CountDownTimerTask::run(void)
{
    if (_timer)
    {
        _writer->writeDec(--_timer);
        if (_timer == 0)
            Robot::instance()->alertUser();
    }
}
