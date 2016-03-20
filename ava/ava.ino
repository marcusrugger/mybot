#include <Arduino.h>

#include "mcore.h"
#include "interfaces.h"
#include "mbot.factory.h"
#include "mbot.builder.h"
#include "mbot.director.h"
#include "robot.h"
#include "hardware.segmentdisplay.h"


static Runnable *idleloop;
static ORION_PINMAP pinmap;
static MBotFactory factory(&pinmap);


void createRobot(void)
{
    MBotBuilder builder(factory);
    MBotDirector::buildThermometer(builder);
}


void setup()
{
    Serial.begin(9600);

    createRobot();
    idleloop = Robot::instance()->idleloop();
    Robot::instance()->alertUser();
}


void loop()
{
    static uint16_t value = 0;
    idleloop->run();
    Robot::instance()->display()->showDec(value++);
    delay(100);
}
