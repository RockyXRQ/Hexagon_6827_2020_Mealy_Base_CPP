#include <cmath>

#include "controlBoard/ControlBoard.h"

ControlBoard::ControlBoard()
    : m_joystickDrive(constants::joystick::JOYSTICK_DRIVE_PORT),
      m_joystickSuperStructure(
          constants::joystick::JOYSTICK_SUPERSTRUCTURE_PORT) {
}

double ControlBoard::GetDriveStrightSpeed() {
    return m_joystickDrive.GetRawAxis(3) - m_joystickDrive.GetRawAxis(2);
}

double ControlBoard::GetDriveTurnSpeed() {
    return m_joystickDrive.GetRawAxis(0);
}

bool ControlBoard::WantChassisAutoControl() {
    //@Todo: Add auto test Button.
    return m_joystickDrive.GetRawButton(5) && m_joystickDrive.GetRawButton(6) &&
           m_joystickDrive.GetRawAxis(2) && m_joystickDrive.GetRawAxis(3);
}

bool ControlBoard::WantChassisManualControl() {
    return (m_joystickDrive.GetRawAxis(3) - m_joystickDrive.GetRawAxis(2)) >
               constants::joystick::JOYSTICK_DRIVE_STRIGHT_DEAD_AREA ||
           fabs(m_joystickDrive.GetRawAxis(0)) >
               constants::joystick::JOYSTICK_DRIVE_TURN_DEAD_AREA;
}

bool ControlBoard::WantChassisManualRudeControl() {
    return m_joystickDrive.GetRawButton(4);
}

bool ControlBoard::WantChassisManualCarefulControl() {
    return m_joystickDrive.GetRawButton(1);
}

bool ControlBoard::WantIntakeBall() {
    return m_joystickSuperStructure.GetRawButton(6) &&
           !(m_joystickSuperStructure.GetRawButton(5));
}

bool ControlBoard::WantOuttakeBall() {
    return m_joystickSuperStructure.GetRawButton(5) &&
           !(m_joystickSuperStructure.GetRawButton(6));
}

bool ControlBoard::WantLockIntake() {
    return m_joystickSuperStructure.GetRawButton(5) ==
           m_joystickSuperStructure.GetRawButton(6);
}

bool ControlBoard::WantLoadBall() {
    return m_joystickSuperStructure.GetRawButton(4) &&
           !(m_joystickSuperStructure.GetRawButton(1));
}

bool ControlBoard::WantStopLoadBall() {
    return m_joystickSuperStructure.GetRawButton(4) ==
           m_joystickSuperStructure.GetRawButton(1);
}

bool ControlBoard::WantUnloadBall() {
    return m_joystickSuperStructure.GetRawButton(1) &&
           !(m_joystickSuperStructure.GetRawButton(4));
}

bool ControlBoard::WantTurretManualLeftSpin() {
    return m_joystickSuperStructure.GetRawButton(3) &&
           !(m_joystickSuperStructure.GetRawButton(2));
}

bool ControlBoard::WantTurretManualRightSpin() {
    return m_joystickSuperStructure.GetRawButton(2) &&
           !(m_joystickSuperStructure.GetRawButton(3));
}

bool ControlBoard::WantTurretLock() {
    return m_joystickSuperStructure.GetRawButton(2) ==
           m_joystickSuperStructure.GetRawButton(3);
}

bool ControlBoard::WantTurretAutoCaptureHighHole() {
    return m_joystickSuperStructure.GetRawButton(6) &&
           m_joystickSuperStructure.GetRawButton(4);
}

bool ControlBoard::WantTurretAutoCaptureLowHole() {
    return m_joystickSuperStructure.GetRawButton(6) &&
           m_joystickSuperStructure.GetRawButton(1);
}

bool ControlBoard::WantTurretShoot() {
    return (bool) m_joystickSuperStructure.GetRawAxis(3);
}