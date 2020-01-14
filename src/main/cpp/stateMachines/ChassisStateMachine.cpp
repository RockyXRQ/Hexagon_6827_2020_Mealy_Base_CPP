#include "stateMachines/ChassisStateMachine.h"

ChassisStateMachine::ChassisStateMachine() {
    m_isChassisRudeMode = false;
}

void ChassisStateMachine::RegisterChassis(Chassis* tempChassis) {
    m_chassis = tempChassis;
}

void ChassisStateMachine::WantAutoMode() {
    m_chassis->SetPositionPIDState();
    m_chassis->SetLowSpeedMode();
}

void ChassisStateMachine::WantManualRudeMode() {
    m_chassis->SetOpenLoopState();
    m_chassis->SetHighSpeedMode();
}

void ChassisStateMachine::WantManualCarefulMode() {
    m_chassis->SetOpenLoopState();
    m_chassis->SetLowSpeedMode();
}

void ChassisStateMachine::WantManualDrive(double tempStrightSpeed,
                                          double tempTurnSpeed) {
    m_chassis->SetOpenLoopState();
    m_chassis->ManualDrive(tempStrightSpeed, tempTurnSpeed);
}

bool ChassisStateMachine::IsChassisRudeMode() {
    return m_isChassisRudeMode;
}