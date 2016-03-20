#ifndef HARDWARE_SEGMENTDISPLAY_H
#define HARDWARE_SEGMENTDISPLAY_H

#include <Arduino.h>
#include "interfaces.h"


class SegmentDisplay
{
public:

    static SegmentDisplay *create(DataSerializer *writer);

    void showHex(uint16_t number);
    void showDec(uint16_t number);


private:

    SegmentDisplay(DataSerializer *writer);

    DataSerializer *_writer;
    static const uint8_t _hexToSegmentMap[];

    uint8_t getHexDigitSegmentMap(uint8_t n);
    uint8_t getDecDigitSegmentMap(uint8_t n);

};


#endif
