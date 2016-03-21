#ifndef HARDWARE_MELCDDIGIT_H
#define HARDWARE_MELCDDIGIT_H

#include <Arduino.h>
#include "interfaces.h"


class MeLCDDigit
{
public:

    static uint8_t toHex(uint8_t number);
    static uint8_t toDec(uint8_t number);

private:

    static const uint8_t _hexToSegmentBitmap[];

};


class MeLCDDigitHex : public Translator<uint8_t>
{
public:

    uint8_t operator()(uint8_t n)
    { return MeLCDDigit::toHex(n); }

};


class MeLCDDigitDec : public Translator<uint8_t>
{
public:

    uint8_t operator()(uint8_t n)
    { return MeLCDDigit::toDec(n); }

};


class Serializable
{
public:

    virtual ~Serializable(void) {}

    virtual void operator()(DataSerializer *writer) = 0;

};


class MeLCDDisplay : public Serializable
{
public:

    MeLCDDisplay(void) {}

    void operator()(DataSerializer *writer)
    { writer->writeData(digits, NUMBER_OF_DIGITS); }

protected:

    static const uint16_t NUMBER_OF_DIGITS = 4;
    uint8_t digits[NUMBER_OF_DIGITS];

};


class MeLCDDisplayHex : public MeLCDDisplay
{
public:

    MeLCDDisplayHex(Translator<uint8_t> translate, uint8_t n) : MeLCDDisplay()
    {
        digits[3] = translate( n       );
        digits[2] = translate( n >>= 4 );
        digits[1] = translate( n >>= 4 );
        digits[0] = translate( n >>= 4 );
    }

};


class MeLCDDisplayDec : public MeLCDDisplay
{
public:

    MeLCDDisplayDec(Translator<uint8_t> translate, uint8_t n) : MeLCDDisplay()
    {
        digits[3] = translate( n       );
        digits[2] = translate( n /= 10 );
        digits[1] = translate( n /= 10 );
        digits[0] = translate( n /= 10 );
    }

};


class MeLCDDisplayCreator : public Transformer<uint16_t, MeLCDDisplay>
{
public:

    MeLCDDisplayCreator(Translator<uint8_t> translator) : _translator(translator) {}

protected:

    Translator<uint8_t> _translator;
};


class MeLCDDisplayHexCreator : public MeLCDDisplayCreator
{
public:

    MeLCDDisplayHexCreator(Translator<uint8_t> translator) : MeLCDDisplayCreator(translator) {}

    MeLCDDisplay operator()(uint16_t n)
    {
        return MeLCDDisplayHex(_translator, n);
    }

};


class MeLCDDisplayDecCreator : public MeLCDDisplayCreator
{
public:

    MeLCDDisplayDecCreator(Translator<uint8_t> translator) : MeLCDDisplayCreator(translator) {}

    MeLCDDisplay operator()(uint16_t n)
    {
        return MeLCDDisplayDec(_translator, n);
    }

};


#endif
