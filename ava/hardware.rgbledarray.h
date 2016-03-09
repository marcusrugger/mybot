#ifndef HARDWARE_RGBLEDARRAY_H
#define HARDWARE_RGBLEDARRAY_H

#include "hardware.rgbledwriter.h"


class RGBLedArray
{
public:

    static RGBLedArray *create(RGBLedWriter *writer, uint8_t ledCount);

    void writeArray(void);
    RGBLedWriter::GRB &operator[](uint8_t index);

private:

    RGBLedArray(RGBLedWriter *writer, uint8_t ledCount);

    RGBLedWriter *_writer;
    uint8_t _ledCount;

    RGBLedWriter::GRB *_grbArray;

};


#endif
