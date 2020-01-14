#ifndef CONTROL_BOARD_H_
#define CONTROL_BOARD_H_

#include "Constants.h"

#include <frc/Joystick.h>

class ControlBoard {
   private:
    frc::Joystick m_joystickDrive;
    frc::Joystick m_joystickSuperStructure;

   public:
    ControlBoard();

    // Chassis Control
    double GetDriveStrightSpeed();
    double GetDriveTurnSpeed();
    bool WantChassisAutoControl();
    bool WantChassisManualControl();
    bool WantChassisManualRudeControl();
    bool WantChassisManualCarefulControl();

    // Intake Control
    bool WantIntakeBall();
    bool WantOuttakeBall();
    bool WantLockIntake();

    // Magazine Control
    bool WantLoadBall();
    bool WantStopLoadBall();
    bool WantUnloadBall();

    // Turret Control()
    bool WantTurretManualLeftSpin();
    bool WantTurretManualRightSpin();
    bool WantTurretLock();
    bool WantTurretAutoCaptureHighHole();
    bool WantTurretAutoCaptureLowHole();
    bool WantTurretShoot();
};

#endif