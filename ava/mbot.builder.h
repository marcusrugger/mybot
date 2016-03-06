#ifndef MBOTBUILDER_H
#define MBOTBUILDER_H


#include "interfaces.h"

class Robot;


class MBotBuilder : public RobotBuilder
{
public:

    MBotBuilder(RobotFactory &factory);

    void buildCommandQueue(void);
    void buildCommandButtonProcessor(void);
    void buildUltrasonicProcessor(void);
    void buildLightProcessor(void);

private:

    RobotFactory &_factory;
    Robot *_robot;

};


#endif
