#ifndef CHASSIS_OUTPUTER_H_
#define CHASSIS_OUTPUTER_H_

#include "subsystems/Chassis.h"
#include "loops/Looper.h"
#include "loops/Loop.h"
class ChassisOutputer : public Loop {
   private:
    static Chassis *m_chassis;

   public:
    ChassisOutputer();

    void RegisterSubsystem(Subsystem *) override;
    void OnStart(double timeTamp = 0) override;
    void OnLoop(double timeTamp = 0) override;
    void OnStop(double timeTamp = 0) override;
};

#endif