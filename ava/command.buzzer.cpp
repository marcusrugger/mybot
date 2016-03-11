#include "command.buzzer.h"
#include "robot.h"
#include "commandqueue.h"


bool BuzzerCommand::queue(void)
{
    CommandQueue *queue = Robot::instance()->commandQueue();
    return queue->add(new BuzzerCommand());
}


void BuzzerCommand::execute(void)
{
    Robot::instance()->alertUser();
}
