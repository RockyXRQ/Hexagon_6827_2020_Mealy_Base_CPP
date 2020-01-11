#include "infraSubsystemsOutputer/ChassisOutputer.h"

ChassisOutputer::ChassisOutputer(Chassis* tempChassis) {
    m_chassis = tempChassis;
}

void ChassisOutputer::EnabledLoop::onStart(double timeTamp) {
    ChassisOutputer::m_chassis->ReadInput();
    ChassisOutputer::m_chassis->PrintToLog();
}

void ChassisOutputer::EnabledLoop::onLoop(double timeTamp) {
    ChassisOutputer::m_chassis->ReadInput();
    ChassisOutputer::m_chassis->WriteOutput();
    ChassisOutputer::m_chassis->PrintToLog();
}

void ChassisOutputer::EnabledLoop::onStop(double timeTamp) {
    ChassisOutputer::m_chassis->ReadInput();
    ChassisOutputer::m_chassis->PrintToLog();
}

void ChassisOutputer::DisabledLoop::onStart(double timeTamp) {
    ChassisOutputer::m_chassis->ReadInput();
    ChassisOutputer::m_chassis->PrintToLog();
}

void ChassisOutputer::DisabledLoop::onLoop(double timeTamp) {
    ChassisOutputer::m_chassis->ReadInput();
    ChassisOutputer::m_chassis->PrintToLog();
}

void ChassisOutputer::DisabledLoop::onStop(double timeTamp) {
    ChassisOutputer::m_chassis->ReadInput();
    ChassisOutputer::m_chassis->PrintToLog();
}

void ChassisOutputer::RegisterEnabledloops(Looper& tempEnabledLooper) {
    tempEnabledLooper.Register(&m_ChassisEnabledLoop);
}

void ChassisOutputer::RegisterDisabledloops(Looper& tempDisabledLooper) {
    tempDisabledLooper.Register(&m_ChassisDisabledLoop);
}
