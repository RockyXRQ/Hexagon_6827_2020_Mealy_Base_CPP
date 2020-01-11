#ifndef SUPERSTRUCTURE_STATEMACHINE_H_
#define SUPERSTRUCTURE_STATEMACHINE_H_

#include <vector>

#include "subsystems/Subsystem.h"

class SuperStructureStateMachine {
   private:
    std::vector<Subsystem *> m_subsystemList;

   public:
    SuperStructureStateMachine();
    void RegisterSubsystem(Subsystem *);
};

#endif
