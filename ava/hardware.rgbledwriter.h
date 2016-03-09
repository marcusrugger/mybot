#ifndef HARDWARE_RGBLEDWRITER_H
#define HARDWARE_RGBLEDWRITER_H

#include <Arduino.h>


class DataSerializer
{
public:

    virtual ~DataSerializer(void) {}
    virtual void writeData(uint8_t *data, uint16_t length) = 0;
};


class RGBLedWriter : public DataSerializer
{
public:

    static RGBLedWriter *create(int pinNumber);

    void writeData(uint8_t *data, uint16_t length);


private:

    RGBLedWriter(int pinNumber);

    const volatile uint8_t *_ws2812_port;

    int _pinNumber;
    uint8_t _pinMask;

    void  rgbled_sendarray_mask(uint8_t *data, uint16_t datlen, uint8_t maskhi, const volatile uint8_t *port);

};


#endif
