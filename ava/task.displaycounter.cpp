#include "task.displaycounter.h"


DisplayCounterTask *DisplayCounterTask::create(DataStream *writer)
{
    return new DisplayCounterTask(writer);
}


DisplayCounterTask::DisplayCounterTask(DataStream *writer)
:   _writer(writer)
{}


void DisplayCounterTask::run(void)
{
    static uint16_t counter = 0;
    _writer->writeDec(++counter);
}
