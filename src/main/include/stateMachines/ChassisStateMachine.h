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
    void WantManualRudeMode(double tempLeftDemand = 0,
                            double tempRightDemand = 0);
    void WantManualCarefulMode(double tempLeftDemand = 0,
                               double tempRightDemand = 0);
    bool IsChassisRudeMode();
};

#endif
