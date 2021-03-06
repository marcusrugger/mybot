#include "hardware.rgbledarray.h"


RGBLedArray *RGBLedArray::create(DataSerializer *writer, uint8_t ledCount)
{
    return new RGBLedArray(writer, ledCount);
}


RGBLedArray::RGBLedArray(DataSerializer *writer, uint8_t ledCount)
:   _writer(writer),
    _ledCount(ledCount),
    _grbArray(new GRB[ledCount])
{
    for (int a = 0; a < _ledCount; _grbArray[a++].setRGB(0, 0, 0));
    show();
}


void RGBLedArray::show(void)
{
    _writer->writeData((uint8_t *) _grbArray, sizeof(GRB) * _ledCount);
}


RGBLedArray::GRB &RGBLedArray::operator[](uint8_t index)
{
    return _grbArray[index < _ledCount ? index : 0];
}
