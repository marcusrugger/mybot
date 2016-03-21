#include "hardware.melcddigit.h"


/*
 *      A
 *     ---
 *  F |   | B
 *     -G-
 *  E |   | C
 *     ---
 *      D
 */
const uint8_t MeLCDDigit::_hexToSegmentBitmap[] =
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


uint8_t MeLCDDigit::toHex(uint8_t n)
{
    return _hexToSegmentBitmap[n & 0x0f];
}


uint8_t MeLCDDigit::toDec(uint8_t n)
{
    return _hexToSegmentBitmap[n % 10];
}
