#ifndef OBSERVER_H
#define OBSERVER_H

#include "interfaces.h"


class MBotButtonObserver : public Observer
{
public:

    MBotButtonObserver(ButtonSubject *subject,
                       Command *buttonPressed,
                       Command *buttonReleased);


private:

    void update(void);

    ButtonSubject *_subject;
    Command *_buttonPressed;
    Command *_buttonReleased;

};

#endif
