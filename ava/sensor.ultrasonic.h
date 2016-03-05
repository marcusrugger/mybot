#ifndef SENSOR_ULTRASONIC_H
#define SENSOR_ULTRASONIC_H

#include "mcore.h"


class UltrasonicSensor : public DistanceProvider
{
public:

    static UltrasonicSensor *create(DigitalPin *pin);

    unsigned long distance(void);

private:

    UltrasonicSensor(DigitalPin *pin);

    DigitalPin *_pin;

    unsigned long readSensor(unsigned long timeout);

};

#endif
