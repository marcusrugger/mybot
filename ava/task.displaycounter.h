#ifndef TASK_DISPLAYCOUNTER_H
#define TASK_DISPLAYCOUNTER_H

#include <Arduino.h>
#include "interfaces.h"


class DisplayCounterTask : public Runnable
{
public:

    static DisplayCounterTask *create(DataStream *writer);

    void run(void);


private:

    DisplayCounterTask(DataStream *writer);

    DataStream *_writer;

};

#endif
