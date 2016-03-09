#ifndef HARDWARE_RGBLEDARRAY_H
#define HARDWARE_RGBLEDARRAY_H

#include "hardware.rgbledwriter.h"


class RGBLedArray
{
public:

    static RGBLedArray *create(DataSerializer *writer, uint8_t ledCount);

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

    void writeArray(void);
    GRB &operator[](uint8_t index);

private:

    RGBLedArray(DataSerializer *writer, uint8_t ledCount);

    DataSerializer *_writer;
    uint8_t _ledCount;

    GRB *_grbArray;

};


#endif
