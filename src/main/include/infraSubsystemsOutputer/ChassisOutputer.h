#ifndef CHASSIS_OUTPUTER_H_
#define CHASSIS_OUTPUTER_H_

#include "infraSubsystemsOutputer/InfraSubsystemOutputer.h"
#include "subsystems/Chassis.h"
#include "loops/Looper.h"
#include "loops/Loop.h"
class ChassisOutputer : public InfraSubsystemOutputer {
   private:
    static Chassis *m_chassis;
    class EnabledLoop : public Loop {
       public:
        EnabledLoop();
        void onStart(double timeTamp = 0) override;
        void onLoop(double timeTamp = 0) override;
        void onStop(double timeTamp = 0) override;
    } m_ChassisEnabledLoop;

    class DisabledLoop : public Loop {
       public:
        DisabledLoop();
        void onStart(double timeTamp = 0) override;
        void onLoop(double timeTamp = 0) override;
        void onStop(double timeTamp = 0) override;
    } m_ChassisDisabledLoop;

   public:
    ChassisOutputer(Chassis *);

    void RegisterEnabledloops(Looper &) override;
    void RegisterDisabledloops(Looper &) override;
};

#endif