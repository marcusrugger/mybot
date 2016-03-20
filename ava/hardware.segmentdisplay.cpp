#include "hardware.segmentdisplay.h"


/*
 *      A
 *     ---
 *  F |   | B
 *     -G-
 *  E |   | C
 *     ---
 *      D
 */
const uint8_t SegmentDisplay::_hexToSegmentBitmap[] =
{
//    .GFEDCBA
    0b00111111,     // 0
    0b00000110,     // 1
    0b01011011,     // 2
    0b01001111,     // 3
    0b01100110,     // 4
    0b01101101,     // 5
    0b01111101,     // 6
    0b00000111,     // 7
    0b01111111,     // 8
    0b01101111,     // 9
    0b01110111,     // A
    0b01111100,     // b
    0b00111001,     // C
    0b01011110,     // d
    0b01111001,     // E
    0b01110001      // F
};

//                              .GFEDCBA
const uint8_t CHAR_SPACE    = 0b00000000;
const uint8_t CHAR_PERIOD   = 0b10000000;
const uint8_t CHAR_DASH     = 0b01000000;
const uint8_t CHAR_DEGREE   = 0b01100011;


SegmentDisplay *SegmentDisplay::create(DataSerializer *writer)
{
    return new SegmentDisplay(writer);
}


SegmentDisplay::SegmentDisplay(DataSerializer *writer)
:   _writer(writer)
{}


void SegmentDisplay::writeHex(uint16_t number)
{
    uint8_t digits[4];

    digits[3] = getHexDigitBitmap( number       );
    digits[2] = getHexDigitBitmap( number >>= 4 );
    digits[1] = getHexDigitBitmap( number >>= 4 );
    digits[0] = getHexDigitBitmap( number >>= 4 );

    _writer->writeData(digits, 4);
}


void SegmentDisplay::writeDec(uint16_t number)
{
    uint8_t digits[4];

    digits[3] = getDecDigitBitmap( number       );
    digits[2] = getDecDigitBitmap( number /= 10 );
    digits[1] = getDecDigitBitmap( number /= 10 );
    digits[0] = getDecDigitBitmap( number /= 10 );

    _writer->writeData(digits, 4);
}


uint8_t SegmentDisplay::getHexDigitBitmap(uint8_t n)
{
    return _hexToSegmentBitmap[n & 0x0f];
}


uint8_t SegmentDisplay::getDecDigitBitmap(uint16_t n)
{
    return _hexToSegmentBitmap[n % 10];
}
