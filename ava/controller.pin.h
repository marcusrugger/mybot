#ifndef CONTROLLER_PIN_H
#define CONTROLLER_PIN_H

#include <Arduino.h>


class AnalogPinReader
{
public:

    virtual int16_t readPin(void) = 0;

};


class ControllerPin : public AnalogPinReader
{
public:

    ControllerPin(uint8_t pin, uint8_t mode)
    :   _pin(pin)
    { pinMode(_pin, mode); }

    int16_t readPin(void)
    { return analogRead(_pin); }

private:

    uint8_t _pin;

};


class DigitalPinWriter
{
public:

    virtual void setLow(void) = 0;
    virtual void setHigh(void) = 0;
    virtual void set(bool value) = 0;

};


class DigitalPinReader
{
public:

    virtual bool get(void) = 0;
    virtual unsigned long readPulse(bool state, unsigned long timeout) = 0;

};


class DigitalPin : public DigitalPinWriter,
                   public DigitalPinReader 
{
public:

};


class ControllerDigitalPin : public DigitalPin
{
public:

    ControllerDigitalPin(uint8_t pin, bool pullup = false)
    :   _pin(pin),
        _pullup(pullup)
    { setMode(pullupMode()); }

    void setLow(void)
    { setWriteMode(); digitalWrite(_pin, LOW); }

    void setHigh(void)
    { setWriteMode(); digitalWrite(_pin, HIGH); }

    void set(bool value)
    { value ? setHigh() : setLow(); }

    bool get(void)
    { setReadMode(); return digitalRead(_pin) == HIGH; }

    unsigned long readPulse(bool state, unsigned long timeout)
    { setMode(INPUT); return pulseIn(_pin, state ? HIGH : LOW, timeout); }


private:

    uint8_t _pin;
    uint8_t _mode;
    bool _pullup;

    void setMode(uint8_t mode)
    {
        _mode = mode;
        pinMode(_pin, mode);
    }

    void setReadMode(void)
    {
        if (OUTPUT == _mode)
            setMode(pullupMode());
    }

    void setWriteMode(void)
    {
        if (OUTPUT != _mode)
            setMode(OUTPUT);
    }

    int pullupMode(void)
    {
        return _pullup ? INPUT_PULLUP : INPUT;
    }

};


#endif
