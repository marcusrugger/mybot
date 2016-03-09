#ifndef HARDWARE_RGBLEDARRAY_H
#define HARDWARE_RGBLEDARRAY_H

#include "hardware.rgbledwriter.h"


class RGBLedArray
{
public:

    static RGBLedArray *create(RGBLedWriter *writer, uint8_t ledCount);

    void writeArray(void);

private:

    RGBLedArray(RGBLedWriter *writer, uint8_t ledCount);

    RGBLedWriter *_writer;
    uint8_t _ledCount;

    struct GRB
    {
        uint8_t green;
        uint8_t red;
        uint8_t blue;
    };

    GRB *_grbArray;

};


#endif
