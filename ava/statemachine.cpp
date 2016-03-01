#include <Arduino.h>
#include "statemachine.h"
#include "robot.h"


MBotStateMachine *MBotIdleState::_instance = NULL;
MBotStateMachine *MBotMovingState::_instance = NULL;
MBotStateMachine *MBotBlockedPathState::_instance = NULL;



MBotStateMachine *MBotIdleState::instance(void)
{
    if (NULL == _instance)
        _instance = new MBotIdleState();
    return _instance;
}

void MBotIdleState::buttonPressed(MBotStateContext *context)
{
    Serial.println("MBotIdleState::buttonPressed");
}

void MBotIdleState::buttonReleased(MBotStateContext *context)
{
    Serial.println("MBotIdleState::buttonReleased");
    Robot::instance()->movement()->forward();
    context->changeState(MBotMovingState::instance());
}

void MBotIdleState::frontPathBlocked(MBotStateContext *context)
{
    Serial.println("MBotIdleState::frontPathBlocked");
}

void MBotIdleState::frontPathCleared(MBotStateContext *context)
{
    Serial.println("MBotIdleState::frontPathCleared");
    Robot::instance()->movement()->forward();
    context->changeState(MBotMovingState::instance());
}




MBotStateMachine *MBotMovingState::instance(void)
{
    if (NULL == _instance)
        _instance = new MBotMovingState();
    return _instance;
}

void MBotMovingState::buttonPressed(MBotStateContext *context)
{
    Serial.println("MBotMovingState::buttonPressed");
    Robot::instance()->movement()->stop();
    context->changeState(MBotIdleState::instance());
}

void MBotMovingState::buttonReleased(MBotStateContext *context)
{
    Serial.println("MBotMovingState::buttonReleased");
}

void MBotMovingState::frontPathBlocked(MBotStateContext *context)
{
    Serial.println("MBotMovingState::frontPathBlocked");
    Moveable *move = Robot::instance()->movement();
    move->stop();
    delay(1000);
    move->rotateRight();
    delay(300);
    move->stop();
    context->changeState(MBotIdleState::instance());
}

void MBotMovingState::frontPathCleared(MBotStateContext *context)
{
    Serial.println("MBotMovingState::frontPathCleared");
}




MBotStateMachine *MBotBlockedPathState::instance(void)
{
    if (NULL == _instance)
        _instance = new MBotBlockedPathState();
    return _instance;
}

void MBotBlockedPathState::buttonPressed(MBotStateContext *context)
{
    Serial.println("MBotBlockedPathState::buttonPressed");
}

void MBotBlockedPathState::buttonReleased(MBotStateContext *context)
{
    Serial.println("MBotBlockedPathState::buttonReleased");
}

void MBotBlockedPathState::frontPathBlocked(MBotStateContext *context)
{
    Serial.println("MBotBlockedPathState::frontPathBlocked");
}

void MBotBlockedPathState::frontPathCleared(MBotStateContext *context)
{
    Serial.println("MBotBlockedPathState::frontPathCleared");
}




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
    _state->buttonPressed(this);
}


void MBotStateContext::buttonReleased(void)
{
    _state->buttonReleased(this);
}


void MBotStateContext::frontPathBlocked(void)
{
    _state->frontPathBlocked(this);
}


void MBotStateContext::frontPathCleared(void)
{
    _state->frontPathCleared(this);
}


void MBotStateContext::changeState(MBotStateMachine *state)
{
    _state = state;
}


bool MBotStateContext::isPathBlocked(void)
{
    return _isPathBlocked;
}


void MBotStateContext::setPathBlocked(bool flag)
{
    _isPathBlocked = flag;
}
