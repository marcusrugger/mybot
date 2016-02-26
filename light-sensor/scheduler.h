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

private:

    Scheduler(void);

    static Scheduler *_instance;

};

#endif
