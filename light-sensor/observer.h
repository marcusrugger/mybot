#ifndef OBSERVER_H
#define OBSERVER_H

class mCoreButtonSubject;

class Observer
{
public:

    virtual void update(void);

};

class mCoreButtonObserver : public Observer
{
public:

    mCoreButtonObserver(void);

private:

    void update(void);

};

#endif
