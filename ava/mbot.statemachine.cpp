#include <Arduino.h>
#include "mbot.statemachine.h"
#include "robot.h"
#include "commandqueue.h"
#include "commands.h"


void MBotStateMachine::buttonPressed(MBotStateContext *context)
{
    // Serial.println("MBotStateMachine::buttonPressed");
}


void MBotStateMachine::buttonReleased(MBotStateContext *context)
{
    // Serial.println("MBotStateMachine::buttonReleased");
}


void MBotStateMachine::frontPathBlocked(MBotStateContext *context)
{
    // Serial.println("MBotStateMachine::frontPathBlocked");
}


void MBotStateMachine::frontPathCleared(MBotStateContext *context)
{
    // Serial.println("MBotStateMachine::frontPathCleared");
}


/**************************************************************************
 ***** MBotIdleState
 **************************************************************************/

MBotStateMachine *MBotIdleState::_instance = NULL;

MBotStateMachine *MBotIdleState::instance(void)
{
    if (NULL == _instance)
        _instance = new MBotIdleState();
    return _instance;
}

void MBotIdleState::buttonReleased(MBotStateContext *context)
{
    // Serial.println("MBotIdleState::buttonReleased");
    Robot::instance()->alertUser();

    MoveCommand::queue(MoveCommand::FORWARD);
    context->changeState(MBotMovingState::instance());
}

void MBotIdleState::frontPathCleared(MBotStateContext *context)
{
    // Serial.println("MBotIdleState::frontPathCleared");
    MoveCommand::queue(MoveCommand::FORWARD);
    context->changeState(MBotMovingState::instance());
}


/**************************************************************************
 ***** MBotMovingState
 **************************************************************************/

MBotStateMachine *MBotMovingState::_instance = NULL;

MBotStateMachine *MBotMovingState::instance(void)
{
    if (NULL == _instance)
        _instance = new MBotMovingState();
    return _instance;
}

void MBotMovingState::buttonPressed(MBotStateContext *context)
{
    // Serial.println("MBotMovingState::buttonPressed");
    Robot::instance()->commandQueue()->reset();
    MoveCommand::queue(MoveCommand::STOP);
    context->changeState(MBotIdleState::instance());
}

void MBotMovingState::frontPathBlocked(MBotStateContext *context)
{
    // Serial.println("MBotMovingState::frontPathBlocked");
    Robot::instance()->commandQueue()->reset();

    MoveCommand::queue(MoveCommand::STOP, 100);
    MoveCommand::queue(MoveCommand::REVERSE, 1000);
    MoveCommand::queue(MoveCommand::ROTATE_RIGHT, 300);
    MoveCommand::queue(MoveCommand::STOP);

    context->queueChangeState(MBotIdleState::instance());
}


/**************************************************************************
 ***** MBotBlockedPathState
 **************************************************************************/

MBotStateMachine *MBotBlockedPathState::_instance = NULL;

MBotStateMachine *MBotBlockedPathState::instance(void)
{
    if (NULL == _instance)
        _instance = new MBotBlockedPathState();
    return _instance;
}


/**************************************************************************
 ***** MBotStateContext
 **************************************************************************/

MBotStateContext *MBotStateContext::_instance = NULL;

MBotStateContext *MBotStateContext::instance(void)
{
    if (NULL == _instance)
        _instance = new MBotStateContext();
    return _instance;
}


MBotStateContext::MBotStateContext()
:   _state(MBotIdleState::instance())
{}


void MBotStateContext::buttonPressed(void)
{
    setButtonPressed(true);
    _state->buttonPressed(this);
}


void MBotStateContext::buttonReleased(void)
{
    setButtonPressed(false);
    _state->buttonReleased(this);
}


void MBotStateContext::frontPathBlocked(void)
{
    setPathBlocked(true);
    _state->frontPathBlocked(this);
}


void MBotStateContext::frontPathCleared(void)
{
    setPathBlocked(false);
    _state->frontPathCleared(this);
}


void MBotStateContext::changeState(MBotStateMachine *state)
{
    _state = state;
}


bool MBotStateContext::queueChangeState(MBotStateMachine *state)
{
    return ChangeStateCommand::queue(this, state);
}


Command *MBotStateContext::buttonPressedCommand(void)
{
    return new ContextEventCommand(this, &MBotStateContext::buttonPressed);
}


Command *MBotStateContext::buttonReleasedCommand(void)
{
    return new ContextEventCommand(this, &MBotStateContext::buttonReleased);
}


Command *MBotStateContext::frontPathBlockedCommand(void)
{
    return new ContextEventCommand(this, &MBotStateContext::frontPathBlocked);
}


Command *MBotStateContext::frontPathClearedCommand(void)
{
    return new ContextEventCommand(this, &MBotStateContext::frontPathCleared);
}


bool MBotStateContext::isButtonPressed(void)
{
    return _isButtonPressed;
}


void MBotStateContext::setButtonPressed(bool flag)
{
    _isButtonPressed = flag;
}


bool MBotStateContext::isPathBlocked(void)
{
    return _isPathBlocked;
}


void MBotStateContext::setPathBlocked(bool flag)
{
    _isPathBlocked = flag;
}
