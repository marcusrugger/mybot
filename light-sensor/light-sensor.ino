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

mCoreButtonObserver *button;


void setup()
{
    button = new mCoreButtonObserver();
}


void loop()
{
    const uint16_t tick_delay = 100;
    uint16_t enter_tick = millis();

    Scheduler::instance()->tick();

    uint16_t tick_time = millis() - enter_tick;
    if (tick_time < tick_delay)
        delay(tick_delay - tick_time);
}
