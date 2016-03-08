#include "subject.button.h"


ButtonSubject::ButtonSubject(ButtonProvider *provider)
:   _provider(provider)
{}


ButtonProvider::ButtonState ButtonSubject::getButtonState(void)
{
    return _state;
}


void ButtonSubject::run(void)
{
    ButtonProvider::ButtonState current_state = _provider->getButtonState();
    if (current_state != _state)
    {
        _state = current_state;
        notify();
    }
}
