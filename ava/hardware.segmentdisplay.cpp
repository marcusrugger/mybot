#include "hardware.segmentdisplay.h"
#include "hardware.melcddigit.h"


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

    digits[3] = MeLCDDigit::toHex( number       );
    digits[2] = MeLCDDigit::toHex( number >>= 4 );
    digits[1] = MeLCDDigit::toHex( number >>= 4 );
    digits[0] = MeLCDDigit::toHex( number >>= 4 );

    _writer->writeData(digits, 4);
}


void SegmentDisplay::writeDec(uint16_t number)
{
    uint8_t digits[4];

    digits[3] = MeLCDDigit::toDec( number       );
    digits[2] = MeLCDDigit::toDec( number /= 10 );
    digits[1] = MeLCDDigit::toDec( number /= 10 );
    digits[0] = MeLCDDigit::toDec( number /= 10 );

    _writer->writeData(digits, 4);
}
