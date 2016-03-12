#include "hardware.buzzer.h"
#include "robot.h"


SimpleBuzzer *SimpleBuzzer::create(int pinNumber, Scheduler *scheduler)
{
    return new SimpleBuzzer(pinNumber, scheduler);
}


SimpleBuzzer::SimpleBuzzer(int pinNumber, Scheduler *scheduler)
:   _scheduler(scheduler),
    _pinNumber(pinNumber),
    _timer(this, 2 * DURATION),
    _countDown(0)
{}


void SimpleBuzzer::soundUserAlert(void)
{
    // If user alert is already sounding, just return.
    if (_countDown)
        return;

    tone(_pinNumber, TONE, DURATION);
    _scheduler->schedule(&_timer);
    _timer.setTimer(2 * DURATION);
    _countDown = 2;
}


void SimpleBuzzer::run(void)
{
    tone(_pinNumber, TONE, DURATION);
    if (--_countDown == 0)
        _scheduler->unschedule(&_timer);
}
