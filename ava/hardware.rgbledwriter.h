#ifndef HARDWARE_RGBLEDWRITER_H
#define HARDWARE_RGBLEDWRITER_H

#include <Arduino.h>


class RGBLedWriter
{
public:

    struct GRB
    {
        uint8_t _green;
        uint8_t _red;
        uint8_t _blue;

        void setRed(uint8_t red)
        { _red = red; }

        void setGreen(uint8_t green)
        { _green = green; }

        void setBlue(uint8_t blue)
        { _blue = blue; }

        void setRGB(uint8_t red, uint8_t green, uint8_t blue)
        { setRed(red); setGreen(green); setBlue(blue); }
    };

    static RGBLedWriter *create(int pinNumber);

    void writeData(uint8_t *array, uint16_t length);


private:

    RGBLedWriter(int pinNumber);

    const volatile uint8_t *_ws2812_port;

    int _pinNumber;
    uint8_t _pinMask;

    void  rgbled_sendarray_mask(uint8_t *data, uint16_t datlen, uint8_t maskhi, const volatile uint8_t *port);

};


#endif
