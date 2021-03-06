#ifndef HARDWARE_RGBLEDWRITER_H
#define HARDWARE_RGBLEDWRITER_H

#include <Arduino.h>
#include "interfaces.h"



class RGBLedWriter : public DataSerializer
{
public:

    static RGBLedWriter *create(int pinNumber);

    void writeData(const uint8_t *data, uint16_t length);


private:

    RGBLedWriter(int pinNumber);

    const volatile uint8_t *_ws2812_port;

    int _pinNumber;
    uint8_t _pinMask;

    void  rgbled_sendarray_mask(const uint8_t *data, uint16_t datlen, uint8_t maskhi, const volatile uint8_t *port);

};


#endif
