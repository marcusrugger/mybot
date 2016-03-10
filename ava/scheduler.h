#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "mcore.h"
#include "interfaces.h"
#include "robot.h"


class TaskRunner : public Runnable,
                   public Scheduler
{
public:

    static TaskRunner *instance(void);

    void run(void);
    void schedule(Runnable *task);
    void unschedule(Runnable *task);

private:

    TaskRunner(void);

    static TaskRunner *_instance;

    static const unsigned int MAX_TASKS = 8;
    Runnable *_tasks[MAX_TASKS];
    unsigned int _count = 0;

};

#endif
