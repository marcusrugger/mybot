#ifndef COMMAND_MOVE_H
#define COMMAND_MOVE_H

#include "interfaces.h"
#include "commandqueue.h"


class MBotStateContext;


class MoveCommand : public Command
{
public:

    enum DIRECTION
    {
        STOP,
        FORWARD,
        REVERSE,
        ROTATE_LEFT,
        ROTATE_RIGHT
    };

    static bool queue(DIRECTION dir, int milli = 0);

    MoveCommand(DIRECTION dir, Moveable *move, CommandQueue *queue = NULL, int milli = 0);
    MoveCommand(DIRECTION dir, int milli = 0);

    void execute(void);


private:

    DIRECTION _direction;
    Moveable *_move;
    CommandQueue *_queue;
    int _milli;

};


#endif
