#include "task.blinker.h"



BlinkerTask *BlinkerTask::create(RGBLedArray *leds)
{
    return new BlinkerTask(leds);
}


BlinkerTask::BlinkerTask(RGBLedArray *leds)
:   _leds(leds)
{}


void BlinkerTask::run(void)
{}
