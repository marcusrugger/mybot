#include "commands.h"
#include "mbot.statemachine.h"
#include "robot.h"
#include "latch.timer.h"


bool MoveCommand::queue(DIRECTION dir, int milli)
{
    CommandQueue *queue = Robot::instance()->commandQueue();
    return queue->add(new MoveCommand(dir, milli));
}

MoveCommand::MoveCommand(DIRECTION dir, Moveable *move, CommandQueue *queue, int milli)
:   _direction(dir),
    _move(move),
    _queue(queue),
    _milli(milli)
{}

MoveCommand::MoveCommand(DIRECTION dir, int milli)
:   _direction(dir),
    _move(Robot::instance()->movement()),
    _queue(Robot::instance()->commandQueue()),
    _milli(milli)
{}

void MoveCommand::execute(void)
{
    // Serial.print("MoveCommand::execute: direction: ");
    // Serial.print(_direction);
    // Serial.print(", millis: ");
    // Serial.println(millis());
    switch (_direction)
    {
        case STOP:
            _move->stop();
        break;

        case FORWARD:
            _move->forward();
        break;

        case REVERSE:
            _move->backward();
        break;

        case ROTATE_LEFT:
            _move->rotateLeft();
        break;

        case ROTATE_RIGHT:
            _move->rotateRight();
        break;
    }

    if (_queue && _milli)
        _queue->setLatch(new TimerLatch(_milli));
}
