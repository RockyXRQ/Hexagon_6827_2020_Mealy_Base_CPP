#ifndef INFRA_SUBSYSTEM_OUTPUTER_H_
#define INFRA_SUBSYSTEM_OUTPUTER_H_

#include <list>

#include "subsystems/Subsystem.h"
#include "loops/Looper.h"

class InfraSubsystemOutputer {
   public:
    virtual void RegisterEnabledloops(Looper &) = 0;
    virtual void RegisterDisabledloops(Looper &) = 0;
};

#endif
