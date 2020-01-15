#ifndef START_FROM_LEFT_H_
#define START_FROM_LEFT_H_

#include <auto/modes/AutoModeBase.h>
#include <subsystems/Chassis.h>
#include <subsystems/Turret.h>
#include <subsystems/Magazine.h>
#include <Robot.h>

class StartFromLeft : public AutoModeBase {
   private:
    Chassis* m_chassis = &Robot::m_chassis;
    Turret* m_turret = &Robot::m_turret;
    Magazine* m_magazine = &Robot::m_magazine;

   public:
    void Start() override;
    void Resume() override;
    void Stop() override;

    void GoToNextState(bool);
};

#endif