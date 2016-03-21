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

};


#endif
