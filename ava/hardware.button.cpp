#include "hardware.button.h"


HardwareButton::HardwareButton(AnalogPinReader *pin)
:   _pin(pin)
{}


ButtonProvider::ButtonState HardwareButton::getButtonState(void)
{
    return _pin->readPin() > 100 ? BUTTON_UP : BUTTON_DOWN;
}
