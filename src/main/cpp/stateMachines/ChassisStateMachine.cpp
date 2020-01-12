#include "stateMachines/ChassisStateMachine.h"

ChassisStateMachine::ChassisStateMachine() {
    m_isChassisRudeMode = false;
}

void ChassisStateMachine::RegisterChassis(Chassis* tempChassis) {
    m_chassis = tempChassis;
}

void ChassisStateMachine::WantAutoMode() {
    m_chassis->SetLowSpeedMode();
    m_chassis->SetPositionPIDState();
}

void ChassisStateMachine::WantManualRudeMode(double tempLeftDemand,
                                             double tempRightDemand) {
    m_chassis->SetHighSpeedMode();
    m_chassis->SetOpenLoopState(tempLeftDemand, tempRightDemand);
}

void ChassisStateMachine::WantManualCarefulMode(double tempLeftDemand,
                                                double tempRightDemand) {
    m_chassis->SetLowSpeedMode();
    m_chassis->SetOpenLoopState(tempLeftDemand, tempRightDemand);
}

bool ChassisStateMachine::IsChassisRudeMode() {
    return m_isChassisRudeMode;
}