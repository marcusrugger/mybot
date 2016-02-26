#include <Arduino.h>

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>

#include "scheduler.h"
#include "subject.h"


class mCoreLightSensor
{
public:

    mCoreLightSensor(uint8_t ledPin, uint8_t sensorPin)
    :   _ledPin(ledPin),
        _sensorPin(sensorPin)
    {}

    int16_t read(void)
    {
        return analogRead(_sensorPin);
    }

    void lightOn(void)
    {
        digitalWrite(_ledPin, HIGH);
    }

    void lightOff(void)
    {
        digitalWrite(_ledPin, LOW);
    }


private:

    uint8_t _ledPin;
    uint8_t _sensorPin;

};

mCoreLightSensor lightSensor(8, A7);


void setup()
{
}


void loop()
{
    Scheduler::instance()->tick();
}
