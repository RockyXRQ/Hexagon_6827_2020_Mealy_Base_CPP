#ifndef CHASSIS_STATEMACHINE_H_
#define CHASSIS_STATEMACHINE_H_

#include "subsystems/Chassis.h"

class ChassisStateMachine {
   private:
    Chassis *m_chassis;
    bool m_isChassisRudeMode;

   public:
    ChassisStateMachine();
    void RegisterChassis(Chassis *);
    void WantAutoMode();
    void WantManualRudeMode();
    void WantManualCarefulMode();
    void WantManualDrive(double tempStrightSpeed = 0, double tempTurnSpeed = 0);
    bool IsChassisRudeMode();
};

#endif
