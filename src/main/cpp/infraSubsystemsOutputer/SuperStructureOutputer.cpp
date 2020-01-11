#include "infraSubsystemsOutputer/SuperStructureOutputer.h"

SuperStructureOutputer::SuperStructureOutputer(
    std::vector<Subsystem *> *tempSubsystemList) {
    m_subsystemList = tempSubsystemList;
}

void SuperStructureOutputer::EnabledLoop::onStart(double timeTamp) {
    for (auto s : *m_subsystemList) {
        s->ReadInput();
        s->PrintToLog();
    }
}

void SuperStructureOutputer::EnabledLoop::onLoop(double timeTamp) {
    for (auto s : *m_subsystemList) {
        s->ReadInput();
        s->WriteOutput();
        s->PrintToLog();
    }
}

void SuperStructureOutputer::EnabledLoop::onStop(double timeTamp) {
    for (auto s : *m_subsystemList) {
        s->ReadInput();
        s->PrintToLog();
    }
}

void SuperStructureOutputer::DisabledLoop::onStart(double timeTamp) {
    for (auto s : *m_subsystemList) {
        s->ReadInput();
        s->PrintToLog();
    }
}

void SuperStructureOutputer::DisabledLoop::onLoop(double timeTamp) {
    for (auto s : *m_subsystemList) {
        s->ReadInput();
        s->PrintToLog();
    }
}

void SuperStructureOutputer::DisabledLoop::onStop(double timeTamp) {
    for (auto s : *m_subsystemList) {
        s->ReadInput();
        s->PrintToLog();
    }
}

void SuperStructureOutputer::RegisterEnabledloops(Looper &tempEnabledLooper) {
    tempEnabledLooper.Register(&m_superStructureEnabledLoop);
}

void SuperStructureOutputer::RegisterDisabledloops(Looper &tempDisabledLooper) {
    tempDisabledLooper.Register(&m_superStructureDisabledLoop);
}
