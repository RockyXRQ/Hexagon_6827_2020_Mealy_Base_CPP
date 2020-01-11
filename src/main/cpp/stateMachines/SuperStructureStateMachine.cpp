#include "stateMachines/SuperStructureStateMachine.h"

SuperStructureStateMachine::SuperStructureStateMachine() {
}

void SuperStructureStateMachine::RegisterSubsystem(Subsystem* tempSubsystem) {
    m_subsystemList.push_back(tempSubsystem);
}