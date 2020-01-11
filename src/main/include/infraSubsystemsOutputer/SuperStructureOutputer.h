#ifndef SUPERSTRUCTURE_OUTPUTER_H_
#define SUPERSTRUCTURE_OUTPUTER_H_

#include <vector>

#include "infraSubsystemsOutputer/InfraSubsystemOutputer.h"
#include "subsystems/Subsystem.h"
#include "loops/Looper.h"
#include "loops/Loop.h"
class SuperStructureOutputer : public InfraSubsystemOutputer {
   private:
    static std::vector<Subsystem *> *m_subsystemList;
    class EnabledLoop : public Loop {
       public:
        EnabledLoop();
        void onStart(double timeTamp = 0) override;
        void onLoop(double timeTamp = 0) override;
        void onStop(double timeTamp = 0) override;
    } m_superStructureEnabledLoop;

    class DisabledLoop : public Loop {
       public:
        DisabledLoop();
        void onStart(double timeTamp = 0) override;
        void onLoop(double timeTamp = 0) override;
        void onStop(double timeTamp = 0) override;
    } m_superStructureDisabledLoop;

   public:
    SuperStructureOutputer(std::vector<Subsystem *> *);

    void RegisterEnabledloops(Looper &) override;
    void RegisterDisabledloops(Looper &) override;
};

#endif