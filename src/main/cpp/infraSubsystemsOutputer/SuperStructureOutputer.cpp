#include "infraSubsystemsOutputer/SuperStructureOutputer.h"

SuperStructureOutputer::SuperStructureOutputer(
    std::list<Subsystem &> &tempSubsystemList) {
    m_subsystemList = tempSubsystemList;
}

void SuperStructureOutputer::EnabledLoop::onStart(double timeTamp = 0) {
    for (auto &s : m_subsystemList) {
        s.ReadInput();
        s.PrintToLog();
    }
}

void SuperStructureOutputer::EnabledLoop::onLoop(double timeTamp = 0) {
    for (auto &s : m_subsystemList) {
        s.ReadInput();
        s.WriteOutput();
        s.PrintToLog();
    }
}

void SuperStructureOutputer::EnabledLoop::onStop(double timeTamp = 0) {
    for (auto &s : m_subsystemList) {
        s.ReadInput();
        s.PrintToLog();
    }
}

void SuperStructureOutputer::DisabledLoop::onStart(double timeTamp = 0) {
    for (auto &s : m_subsystemList) {
        s.ReadInput();
        s.PrintToLog();
    }
}

void SuperStructureOutputer::DisabledLoop::onLoop(double timeTamp = 0) {
    for (auto &s : m_subsystemList) {
        s.ReadInput();
        s.PrintToLog();
    }
}

void SuperStructureOutputer::DisabledLoop::onStop(double timeTamp = 0) {
    for (auto &s : m_subsystemList) {
        s.ReadInput();
        s.PrintToLog();
    }
}

void SuperStructureOutputer::RegisterEnabledloops(Looper &tempEnabledLooper) {
    tempEnabledLooper.Register(m_superStructureEnabledLoop);
}

void SuperStructureOutputer::RegisterDisabledloops(Looper &tempDisabledLooper) {
    tempDisabledLooper.Register(m_superStructureDisabledLoop);
}
