#ifndef SUPERSTRUCTURE_OUTPUTER_H_
#define SUPERSTRUCTURE_OUTPUTER_H_

#include <vector>

#include "subsystems/Subsystem.h"
#include "loops/Loop.h"

class SuperStructureOutputer : public Loop {
   private:
    std::vector<Subsystem *> m_subsystemList;

   public:
    SuperStructureOutputer();

    void RegisterSubsystem(Subsystem *) override;
    void OnStart(double timeTamp = 0) override;
    void OnLoop(double timeTamp = 0) override;
    void OnStop(double timeTamp = 0) override;
};

#endif