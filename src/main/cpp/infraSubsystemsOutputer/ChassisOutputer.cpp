#include "infraSubsystemsOutputer/ChassisOutputer.h"

ChassisOutputer::ChassisOutputer() {
    std::cout << "the loop ChassisOutputer instantiate!" << std::endl;
}

void ChassisOutputer::RegisterSubsystem(Chassis* tempChassis) {
    m_chassis = tempChassis;
}

void ChassisOutputer::OnStart(double timeTamp) {
    m_chassis->ReadInput();
    m_chassis->PrintToLog();
}

void ChassisOutputer::OnLoop(double timeTamp) {
    m_chassis->ReadInput();
    m_chassis->WriteOutput();
    m_chassis->PrintToLog();
}

void ChassisOutputer::OnStop(double timeTamp) {
    m_chassis->ReadInput();
    m_chassis->PrintToLog();
}
