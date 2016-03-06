#ifndef OBSERVER_BUTTON_H
#define OBSERVER_BUTTON_H

#include "interfaces.h"
#include "subject.button.h"


class ButtonObserver : public Observer
{
public:

    ButtonObserver(ButtonSubject *subject,
                   Command *buttonPressed,
                   Command *buttonReleased);


private:

    void update(void);

    ButtonSubject *_subject;
    Command *_buttonPressed;
    Command *_buttonReleased;

};

#endif
