#ifndef TASK_DISPLAYANIMATOR_H
#define TASK_DISPLAYANIMATOR_H

#include "interfaces.h"


class DisplayAnimatorTask : public Runnable
{
public:

    static DisplayAnimatorTask *create(DataSerializer *writer);

    void run(void);


private:

    DisplayAnimatorTask(DataSerializer *writer);

    DataSerializer *_writer;
    uint16_t _animation_index;

};


#endif
