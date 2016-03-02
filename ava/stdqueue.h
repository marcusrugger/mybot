#ifndef STDQUEUE_H
#define STDQUEUE_H


template<class T>
class StdQueue
{
public:

    StdQueue(void)
    :   _pushidx(0),
        _pullidx(0),
        _count(0)
    {}


    bool push(T obj)
    {
        bool success = false;

        if (!isFull())
        {
            ++_count;
            _queue[_pushidx++] = obj;
            if (_pushidx == MAX_QUEUE)
                _pushidx = 0;
        }

        return success;
    }


    T pull(void)
    {
        T obj = NULL;

        if (isMore())
        {
            --_count;
            obj = _queue[_pullidx++];
            if (_pullidx == MAX_QUEUE)
                _pullidx = 0;
        }

        return obj;
    }


    bool isEmpty(void) { return _count == 0;         }
    bool isFull(void)  { return _count == MAX_QUEUE; }
    bool isMore(void)  { return _count > 0;          }
    void reset(void)   { _pushidx = _pullidx = _count = 0; }

private:

    static const int MAX_QUEUE = 16;
    T   _queue[MAX_QUEUE];
    int _pushidx;
    int _pullidx;
    int _count;
};


#endif
