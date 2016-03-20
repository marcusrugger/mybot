#ifndef TASK_COUNTDOWNTIMER_H
#define TASK_COUNTDOWNTIMER_H

#include <Arduino.h>
#include "interfaces.h"


class CountDownTimerTask : public Runnable
{
public:

    static CountDownTimerTask *create(DataStream *writer, uint16_t timer);

    void run(void);


private:

    CountDownTimerTask(DataStream *writer, uint16_t timer);

    DataStream *_writer;
    uint16_t _timer;

};


#endif
