#ifndef OBSERVER_DISTANCE_H
#define OBSERVER_DISTANCE_H

#include "interfaces.h"

class DistanceSubject;


class DistanceObserver : public Observer
{
public:

    DistanceObserver(DistanceSubject *subject, Command *pathBlocked, Command *pathCleared);

    void update(void);


private:

    DistanceSubject *_subject;
    Command *_pathBlocked;
    Command *_pathCleared;

};

#endif
