#ifndef HARDWARE_BUZZER_H
#define HARDWARE_BUZZER_H

#include "interfaces.h"
#include "mcore.h"


class SimpleBuzzer : public Tickable
{
public:

    static SimpleBuzzer *create(DigitalPinWriter *pin);

    void setBuzzer(bool flag);
    void setBuzzerOn(void);
    void setBuzzerOff(void);

    void tick(void);

private:

    SimpleBuzzer(DigitalPinWriter *ping);

    bool isTimeExpired(void);

    DigitalPinWriter *_pin;
    bool _buzzerOn;
    bool _pinState;
    unsigned long _wait_time;
    unsigned long _wait_start;

};

#endif
