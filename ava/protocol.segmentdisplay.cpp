#include "protocol.segmentdisplay.h"


SegmentDisplayProtocol *SegmentDisplayProtocol::create(DigitalPin *pinClock, DigitalPin *pinData)
{
    return new SegmentDisplayProtocol(pinClock, pinData);
}


SegmentDisplayProtocol::SegmentDisplayProtocol(DigitalPin *pinClock, DigitalPin *pinData)
:   _pinClock(pinClock),
    _pinData(pinData)
{
    _pinClock->setLow();
    _pinData->setLow();
}


void SegmentDisplayProtocol::writeData(const uint8_t *data, uint16_t length)
{
    start();    // Start signal sent to TM1637 from MCU.
    writeByte(ADDR_AUTO);
    stop();

    start();
    writeByte(STARTADDR);
    for (uint16_t i = 0; i < length; i++)
        writeByte(data[i]);
    stop();

    start();
    writeByte(Cmd_DispCtrl);
    stop();
}


void SegmentDisplayProtocol::bitDelay(void)
{
    delayMicroseconds(5);
}


void SegmentDisplayProtocol::start(void)
{
    _pinData->setHigh();
    _pinClock->setHigh();   bitDelay();
    _pinData->setLow();     bitDelay();
    _pinClock->setLow();
}


void SegmentDisplayProtocol::stop(void)
{
    _pinData->setLow();     bitDelay();
    _pinClock->setHigh();   bitDelay();
    _pinData->setHigh();
}


void SegmentDisplayProtocol::writeByte(uint8_t data)
{
    for (int bit = 0; bit < 8; bit++)
    {
        _pinClock->setLow();
        _pinData->set(data & 0x01);
        _pinClock->setHigh();
        bitDelay();

        for (int cnt = 0; !_pinClock->get() && cnt < 20; cnt++)
            bitDelay();

        data >>= 1;
    }

    waitForAck();
}


void SegmentDisplayProtocol::waitForAck(void)
{
    _pinClock->setLow();
    _pinData->setHigh();    bitDelay();
    _pinClock->setHigh();

    for (int cnt = 0; !_pinClock->get() && cnt < 20; cnt++)
        bitDelay();

    _pinClock->setLow();
    _pinData->setLow();
}
