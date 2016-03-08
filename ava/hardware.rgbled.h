#ifndef HARDWARE_RGBLED_H
#define HARDWARE_RGBLED_H

#include <Arduino.h>


class RGBLed
{
public:

    static RGBLed *create(int pinNumber);

    void writeData(uint8_t *array, uint16_t length);


private:

    RGBLed(int pinNumber);

    const volatile uint8_t *_ws2812_port;

    int _pinNumber;
    uint8_t _pinMask;

    void  rgbled_sendarray_mask(uint8_t *data, uint16_t datlen, uint8_t maskhi, const volatile uint8_t *port);

};


#endif
