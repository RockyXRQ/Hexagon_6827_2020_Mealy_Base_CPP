#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
    m_chassisOutputer.RegisterSubsystem(&m_chassis);

    m_superStructreOutputer.RegisterSubsystem(&m_intake);
    m_superStructreOutputer.RegisterSubsystem(&m_magazine);
    m_superStructreOutputer.RegisterSubsystem(&m_turret);

    m_EnabledLooper.Register(&m_chassisOutputer);
    m_EnabledLooper.Register(&m_superStructreOutputer);

    m_chassisStateMachine.RegisterChassis(&m_chassis);

    m_superStructureStateMachine.RegisterIntake(&m_intake);
    m_superStructureStateMachine.RegisterMagazine(&m_magazine);
    m_superStructureStateMachine.RegisterTurret(&m_turret);

    m_EnabledLooper.StartLoop();
    m_DisabledLooper.StartLoop();
}

void Robot::RobotPeriodic() {
    m_EnabledLooper.OutputToSmartDashboard();
}
void Robot::AutonomousInit() {
    m_EnabledLooper.StartLoop();
    m_chassisStateMachine.WantAutoMode();
}

void Robot::AutonomousPeriodic() {
    m_EnabledLooper.RunLoop();
    m_chassisStateMachine.WantAutoMode();
}

void Robot::TeleopInit() {
    m_EnabledLooper.StartLoop();
    m_chassisStateMachine.WantManualRudeMode(0, 0);
}

void Robot::TeleopPeriodic() {
    if (m_controlBoard.WantChassisManualRudeControl)
        m_chassisStateMachine.WantManualRudeMode();
    if (m_controlBoard.WantChassisManualCarefulControl())
        m_chassisStateMachine.WantManualCarefulMode();
    if (m_controlBoard.WantChassisManualControl()) {
        if (m_chassisStateMachine.IsChassisRudeMode())
            m_chassisStateMachine.WantManualRudeMode(
                m_controlBoard.GetDriveStrightSpeed() +
                    m_controlBoard.GetDriveTurnSpeed(),
                m_controlBoard.GetDriveStrightSpeed() -
                    m_controlBoard.GetDriveTurnSpeed());
        else
            m_chassisStateMachine.WantManualCarefulMode(
                m_controlBoard.GetDriveStrightSpeed() +
                    m_controlBoard.GetDriveTurnSpeed(),
                m_controlBoard.GetDriveStrightSpeed() -
                    m_controlBoard.GetDriveTurnSpeed());
    }
    if (m_controlBoard.WantIntakeBall()) {
        m_superStructureStateMachine.IntakeIntake();
        m_superStructureStateMachine.MagazineLoad();
    }
    if (m_controlBoard.WantOuttakeBall()) {
        m_superStructureStateMachine.IntakeOutTake();
    }
    if (m_controlBoard.WantLockIntake()) {
        m_superStructureStateMachine.IntakeLock();
    }
    if (m_controlBoard.WantLoadBall()) {
        m_superStructureStateMachine.IntakeOutTake();
        m_superStructureStateMachine.MagazineLoad();
    }
    if (m_controlBoard.WantUnloadBall()) {
        m_superStructureStateMachine.MagazineUnload();
    }
    if (m_controlBoard.WantStopLoadBall()) {
        m_superStructureStateMachine.MagazineLock();
    }
    if (m_controlBoard.WantTurretManualLeftSpin()) {
        m_superStructureStateMachine.TurretLeftSpin();
    }
    if (m_controlBoard.WantTurretManualRightSpin()) {
        m_superStructureStateMachine.TurretRightSpin();
    }
    if (m_controlBoard.WantTurretLock()) {
        m_superStructureStateMachine.TurretLock();
    }
    if (m_controlBoard.WantTurretShoot()) {
        m_superStructureStateMachine.IntakeIntake();
        m_superStructureStateMachine.MagazineLoad();
        m_superStructureStateMachine.TurretShoot();
    }
    if (m_controlBoard.WantTurretAutoCaptureHighHole()) {
    }
    if (m_controlBoard.WantTurretAutoCaptureLowHole()) {
    }
    m_EnabledLooper.RunLoop();
}

void Robot::TestPeriodic() {
}

void Robot::DisabledInit() {
    m_DisabledLooper.StartLoop();
}

void Robot::DisabledPeriodic() {
    m_EnabledLooper.StopLoop();
    m_DisabledLooper.RunLoop();
}

#ifndef RUNNING_FRC_TESTS
int main() {
    return frc::StartRobot<Robot>();
}
#endif