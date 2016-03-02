#include <Arduino.h>
#include "stdqueue.h"


template<class T>
StdQueue<T>::StdQueue(void)
:   _pushidx(0),
    _pullidx(0),
    _count(0)
{}


template<class T>
bool StdQueue<T>::push(T *obj)
{
    bool success = false;

    if (_count < MAX_QUEUE)
    {
        ++_count;
        _queue[_pushidx++] = obj;
        if (_pushidx == MAX_QUEUE)
            _pushidx = 0;
    }

    return success;
}


template<class T>
T *StdQueue<T>::pull(void)
{
    T *obj = NULL;

    if (_count > 0)
    {
        --_count;
        obj = _queue[_pullidx--];
        if (_pullidx == MAX_QUEUE)
            _pullidx = 0;
    }

    return obj;
}


template<class T>
void StdQueue<T>::reset(void)
{
    _pushidx = _pullidx = _count = 0;
}
