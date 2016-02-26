#ifndef SCHEDULER_H
#define SCHEDULER_H

class Scheduler
{
public:

    static Scheduler *instance(void);


private:

    Scheduler(void);

    static Scheduler *_instance;

};

#endif
