#ifndef MBOTBUILDER_H
#define MBOTBUILDER_H


#include "interfaces.h"

class Robot;
class Moveable;


class MBotBuilder : public RobotBuilder
{
public:

    MBotBuilder(RobotFactory &factory);

    void buildCommandQueue(void);
    void buildButtonProcessor(void);
    void buildUltrasonicProcessor(void);

private:

    RobotFactory &_factory;
    Robot *_robot;

};


#endif
