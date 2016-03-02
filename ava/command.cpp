#include "commands.h"
#include "statemachine.h"


MBotCommand::MBotCommand(MBotStateContext *machine)
:   _machine(machine)
{}


void ButtonPressedCommand::execute(void)
{
    _machine->buttonPressed();
}


void ButtonReleasedCommand::execute(void)
{
    _machine->buttonReleased();
}


void FrontPathBlockedCommand::execute(void)
{
    _machine->frontPathBlocked();
}


void FrontPathClearedCommand::execute(void)
{
    _machine->frontPathCleared();
}


MoveCommand::MoveCommand(DIRECTION dir, Moveable *move, CommandQueue *queue, int milli)
:   _direction(dir),
    _move(move),
    _queue(queue),
    _milli(milli)
{}

void MoveCommand::execute(void)
{
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
    
    _queue->pause(_milli);
}
