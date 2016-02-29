#include "subject.h"


void BaseSubject::attach(Observer *observer)
{
    if (_count < MAX_OBSERVERS)
        _observers[_count++] = observer;
}


void BaseSubject::detach(const Observer *observer)
{
    unsigned int is, id;
    for (is = id = 0; is < _count; )
    {
        if (_observers[is] == observer)
        {
            ++is;
            --_count;
        }
        else if (id < is)
            _observers[id++] = _observers[is++];
        else
            id = ++is;
    }
}


void BaseSubject::notify(void) const
{
    for (unsigned int index = 0; index < _count; index++)
        _observers[index]->update();
}
