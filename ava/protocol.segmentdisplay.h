#ifndef PROTOCOL_SEGMENTDISPLAY_H
#define PROTOCOL_SEGMENTDISPLAY_H

#include <Arduino.h>
#include "interfaces.h"
#include "controller.pin.h"


class SegmentDisplayProtocol : public DataSerializer
{
public:

    static SegmentDisplayProtocol *create(DigitalPin *pinClock, DigitalPin *pinData);
    SegmentDisplayProtocol(DigitalPin *pinClock, DigitalPin *pinData);

    void setDisplayOn(bool flag);

    virtual void writeData(uint8_t *data, uint16_t length);

private:

    DigitalPin *_pinClock;
    DigitalPin *_pinData;

    static const uint8_t ADDR_AUTO  = 0x40;   //Automatic address increment mode
    static const uint8_t STARTADDR  = 0xc0;   //start address of display register
    static const uint8_t SEGDIS_ON  = 0x88;   //diplay on
    static const uint8_t SEGDIS_OFF = 0x80;   //diplay off

    static const uint8_t Cmd_DispCtrl = SEGDIS_ON + 2;

    void bitDelay(void);
    void start(void);
    void stop(void);
    void writeByte(uint8_t data);
    void waitForAck(void);

};


#endif
