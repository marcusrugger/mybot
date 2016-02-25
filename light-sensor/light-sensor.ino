#include <Arduino.h>


void setup()
{
    // initialize serial communications at 9600 bps
    Serial.begin(9600);
}


void loop()
{
    Serial.println("Hello world!");
    delay(10000);
}
