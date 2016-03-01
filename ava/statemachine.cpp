#include <Arduino.h>
#include "statemachine.h"
#include "robot.h"


void MBotStateMachine::buttonPressed(MBotStateContext *context)
{}

void MBotStateMachine::buttonReleased(MBotStateContext *context)
{}


void MBotStateMachine::frontPathBlocked(MBotStateContext *context)
{}


void MBotStateMachine::frontPathCleared(MBotStateContext *context)
{}


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
    Robot::instance()->movement()->forward();
    context->changeState(MBotMovingState::instance());
}

void MBotIdleState::frontPathCleared(MBotStateContext *context)
{
    Robot::instance()->movement()->forward();
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
    Robot::instance()->movement()->stop();
    context->changeState(MBotIdleState::instance());
}

void MBotMovingState::frontPathBlocked(MBotStateContext *context)
{
    Moveable *move = Robot::instance()->movement();
    move->stop();
    delay(1000);
    move->rotateRight();
    delay(300);
    move->stop();
    context->changeState(MBotIdleState::instance());
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
