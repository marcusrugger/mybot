#ifndef SUBJECT_BUTTON_H
#define SUBJECT_BUTTON_H

#include "subject.h"


class ButtonSubject : public BaseSubject,
                      public Tickable
{
public:

    ButtonSubject(ButtonProvider *provider);

    ButtonProvider::ButtonState getButtonState(void);

protected:

    void tick(void);

private:

    ButtonProvider *_provider;
    ButtonProvider::ButtonState _state;

};


#endif
