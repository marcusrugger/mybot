#ifndef SCHEDULER_H
#define SCHEDULER_H


class Tickable
{
public:

    virtual void tick(void) = 0;

};


class Scheduler
{
public:

    virtual void schedule(Tickable *task) = 0;

};


class TaskRunner : public Tickable,
                   public Scheduler
{
public:

    static TaskRunner *instance(void);

    void tick(void);
    void schedule(Tickable *task);

private:

    TaskRunner(void);

    static TaskRunner *_instance;

    static const unsigned int MAX_TASKS = 8;
    Tickable *_tasks[MAX_TASKS];
    unsigned int _count = 0;

};

#endif
