#ifndef OBSERVER_H
#define OBSERVER_H

#include "interfaces.h"


class MoveOnButtonRelease : public Observer,
                            public Tickable
{
public:

    MoveOnButtonRelease(ButtonSubject *subject, Moveable *move);

private:

    void update(void);
    void tick(void);

    RobotFactory &_factory;
    Scheduler *_scheduler;

    ButtonSubject *_subject;
    Moveable *_move;
    Tickable *_timer;

};

#endif
