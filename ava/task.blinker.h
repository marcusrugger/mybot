#ifndef TASK_BLINKER_H
#define TASK_BLINKER_H

#include "hardware.rgbledarray.h"


class BlinkerTask : public Runnable
{
public:

    static BlinkerTask *create(RGBLedArray *leds);

    void run(void);


private:

    BlinkerTask(RGBLedArray *leds);

    RGBLedArray *_leds;

};

#endif
