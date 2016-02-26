#ifndef SCHEDULER_H
#define SCHEDULER_H

class Tickable
{
public:

    virtual void tick(void) = 0;

};

class Scheduler : public Tickable
{
public:

    static Scheduler *instance(void);

    void tick(void);
    void schedule(Tickable *task);

private:

    Scheduler(void);

    static Scheduler *_instance;

    static const unsigned int MAX_TASKS = 8;
    Tickable *_tasks[MAX_TASKS];
    unsigned int _count = 0;

};

#endif
