#include "task.blinker.h"



BlinkerTask *BlinkerTask::create(RGBLedArray *leds)
{
    return new BlinkerTask(leds);
}


BlinkerTask::BlinkerTask(RGBLedArray *leds)
:   _leds(leds)
{}


void BlinkerTask::run(void)
{
    static bool flag = false;

    flag = !flag;
    if (flag)
    {
        (*_leds)[0].setRGB(0, 0, 0);
        (*_leds)[1].setRGB(32, 32, 32);
    }
    else
    {
        (*_leds)[0].setRGB(32, 32, 32);
        (*_leds)[1].setRGB(0, 0, 0);
    }

    _leds->show();
}
