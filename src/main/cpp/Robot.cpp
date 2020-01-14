#include "Robot.h"
#include "Constants.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

/*
    TODO1:Add autonomou plan selector.
    TODO2:Add Camera Settings.
*/

// ControlBoard
ControlBoard Robot::m_controlBoard;

// Chassis
Chassis Robot::m_chassis{constants::chassis::CHASSIS_KP,
                         constants::chassis::CHASSIS_KI,
                         constants::chassis::CHASSIS_KD};

// Subsystems
JetsonNanoCamera Robot::m_camera;

Intake Robot::m_intake{constants::intake::INTAKE_KP,
                       constants::intake::INTAKE_KI,
                       constants::intake::INTAKE_KD};
Magazine Robot::m_magazine{constants::magazine::MAGAZINE_KP,
                           constants::magazine::MAGAZINE_KI,
                           constants::magazine::MAGAZINE_KD};
Turret Robot::m_turret{constants::turret::TURRET_KP,
                       constants::turret::TURRET_KI,
                       constants::turret::TURRET_KD};

// InfraSubsystemsOutputer
ChassisOutputer Robot::m_chassisOutputer;
SuperStructureOutputer Robot::m_superStructreOutputer;

// StateMachines
ChassisStateMachine Robot::m_chassisStateMachine;
SuperStructureStateMachine Robot::m_superStructureStateMachine;

// Looper
Looper Robot::m_EnabledLooper{"EnabledLooper"};
Looper Robot::m_DisabledLooper{"DisabledLooper"};

void Robot::RobotInit() {
    m_chassisOutputer.RegisterSubsystem(&m_chassis);

    m_superStructreOutputer.RegisterSubsystem(&m_camera);
    m_superStructreOutputer.RegisterSubsystem(&m_intake);
    m_superStructreOutputer.RegisterSubsystem(&m_magazine);
    m_superStructreOutputer.RegisterSubsystem(&m_turret);

    m_EnabledLooper.Register(&m_chassisOutputer);
    m_EnabledLooper.Register(&m_superStructreOutputer);

    m_chassisStateMachine.RegisterChassis(&m_chassis);

    m_superStructureStateMachine.RegisterCamera(&m_camera);
    m_superStructureStateMachine.RegisterIntake(&m_intake);
    m_superStructureStateMachine.RegisterMagazine(&m_magazine);
    m_superStructureStateMachine.RegisterTurret(&m_turret);

    m_EnabledLooper.StartLoop();
    m_DisabledLooper.StartLoop();
}

void Robot::RobotPeriodic() {
    m_EnabledLooper.OutputToSmartDashboard();
    m_DisabledLooper.OutputToSmartDashboard();
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
    m_chassisStateMachine.WantManualRudeMode();
}

void Robot::TeleopPeriodic() {
    if (m_controlBoard.WantChassisManualRudeControl())
        m_chassisStateMachine.WantManualRudeMode();

    if (m_controlBoard.WantChassisManualCarefulControl())
        m_chassisStateMachine.WantManualCarefulMode();

    if (m_controlBoard.WantChassisManualControl()) {
        m_chassisStateMachine.WantManualDrive(
            m_controlBoard.GetDriveStrightSpeed(),
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