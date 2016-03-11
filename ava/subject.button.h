#ifndef SUBJECT_BUTTON_H
#define SUBJECT_BUTTON_H

#include "subject.base.h"


class ButtonSubject : public BaseSubject,
                      public Runnable
{
public:

    ButtonSubject(ButtonProvider *provider);

    ButtonProvider::ButtonState getButtonState(void);

protected:

    void run(void);

private:

    ButtonProvider *_provider;
    ButtonProvider::ButtonState _state;

};


#endif
