#include "mcore.h"
#include "mbot.director.h"
#include "robot.h"
#include "subject.base.h"


MBotDirector::MBotDirector(RobotBuilder &builder)
:   _builder(builder)
{}


void MBotDirector::buildRobot(void)
{
    _builder.buildCommandQueue();
    _builder.buildCommandButtonProcessor();
    _builder.buildUltrasonicProcessor();
    _builder.buildLightProcessor();
    _builder.buildBlinker();
    // _builder.buildBuzzer();
}
