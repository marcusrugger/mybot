#ifndef HARDWARE_SEGMENTDISPLAY_H
#define HARDWARE_SEGMENTDISPLAY_H

#include <Arduino.h>
#include "interfaces.h"


class SegmentDisplay : public DataStream
{
public:

    static SegmentDisplay *create(DataSerializer *writer);

    void writeHex(uint16_t number);
    void writeDec(uint16_t number);


private:

    SegmentDisplay(DataSerializer *writer);

    DataSerializer *_writer;
    static const uint8_t _hexToSegmentBitmap[];

    uint8_t getHexDigitBitmap(uint8_t n);
    uint8_t getDecDigitBitmap(uint16_t n);

};


#endif
