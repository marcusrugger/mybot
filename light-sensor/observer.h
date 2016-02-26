#ifndef OBSERVER_H
#define OBSERVER_H

class ButtonSubject;

class Observer
{
public:

    virtual void update(void);

};

class mCoreButtonObserver : public Observer
{
public:

    mCoreButtonObserver(ButtonSubject *subject);

private:

    void update(void);

    ButtonSubject *_subject;

};

#endif
