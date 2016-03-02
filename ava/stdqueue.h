#ifndef STDQUEUE_H
#define STDQUEUE_H


template<class T>
class StdQueue
{
public:

    StdQueue(void);

    bool push(T *obj);
    T *pull(void);

    void reset(void);

private:

    static const int MAX_QUEUE = 16;
    T   *_queue[MAX_QUEUE];
    int _pushidx;
    int _pullidx;
    int _count;
};


#endif
