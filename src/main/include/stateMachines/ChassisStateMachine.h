#ifndef CHASSIS_STATEMACHINE_H_
#define CHASSIS_STATEMACHINE_H_

#include "subsystems/Chassis.h"

class ChassisStateMachine {
   private:
    Chassis *m_chassis;

   public:
    ChassisStateMachine(Chassis *);
    void WantAutoMode();
    void WantManualRudeMode(double tempLeftDemand = 0,
                            double tempRightDemand = 0);
    void WantManualCarefulMode(double tempLeftDemand = 0,
                               double tempRightDemand = 0);
};

#endif
