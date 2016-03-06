#ifndef HARDWARE_BUTTON_H
#define HARDWARE_BUTTON_H

#include "mcore.h"


class HardwareButton : public ButtonProvider
{
public:

    HardwareButton(AnalogPinReader *pin);

    ButtonState getButtonState(void);

private:

    AnalogPinReader *_pin;

};


#endif
