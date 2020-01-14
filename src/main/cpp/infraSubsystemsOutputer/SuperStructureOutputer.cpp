#include "infraSubsystemsOutputer/SuperStructureOutputer.h"

#include <iostream>

SuperStructureOutputer::SuperStructureOutputer() : m_subsystemList() {
    std::cout << "the loop SuperStructureOutputer instantiate!" << std::endl;
}

void SuperStructureOutputer::RegisterSubsystem(Subsystem* tempSubsystem) {
    m_subsystemList.push_back(tempSubsystem);
}

void SuperStructureOutputer::OnStart(double timeTamp) {
    for (auto s : m_subsystemList) {
        s->ZeroSensors();
        s->ReadInput();
        s->PrintToLog();
    }
}

void SuperStructureOutputer::OnLoop(double timeTamp) {
    for (auto s : m_subsystemList) {
        s->ReadInput();
        s->WriteOutput();
        s->PrintToLog();
    }
}

void SuperStructureOutputer::OnStop(double timeTamp) {
    for (auto s : m_subsystemList) {
        s->ReadInput();
        s->PrintToLog();
    }
}