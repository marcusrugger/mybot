#include "hardware.rgbledarray.h"


RGBLedArray *RGBLedArray::create(RGBLedWriter *writer, uint8_t ledCount)
{
    return new RGBLedArray(writer, ledCount);
}


RGBLedArray::RGBLedArray(RGBLedWriter *writer, uint8_t ledCount)
:   _writer(writer),
    _ledCount(ledCount),
    _grbArray(new GRB[ledCount])
{}


void RGBLedArray::writeArray(void)
{
    _writer->writeData((uint8_t *) _grbArray, sizeof(GRB) * _ledCount);
}
