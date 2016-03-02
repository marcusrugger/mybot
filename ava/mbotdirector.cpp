#include "mcore.h"
#include "mbotdirector.h"
#include "robot.h"
#include "subject.h"


MBotDirector::MBotDirector(RobotBuilder &builder)
:   _builder(builder)
{}


void MBotDirector::buildRobot(void)
{
    _builder.buildCommandQueue();
    _builder.buildButtonProcessor();
    _builder.buildUltrasonicProcessor();
}
