#include "observer.distance.h"
#include "subject.distance.h"


DistanceObserver::DistanceObserver(DistanceSubject *subject, Command *pathBlocked, Command *pathCleared)
:   _subject(subject),
    _pathBlocked(pathBlocked),
    _pathCleared(pathCleared)
{}


void DistanceObserver::update(void)
{
    if (_subject->isBlocked())
        _pathBlocked->execute();
    else
        _pathCleared->execute();
}
