#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
    m_chassisOutputer.RegisterSubsystem(&m_chassis);
    m_superStructreOutputer.RegisterSubsystem(&m_intake);

    m_EnabledLooper.Register(&m_chassisOutputer);
    m_EnabledLooper.Register(&m_superStructreOutputer);

    m_chassisStateMachine.RegisterChassis(&m_chassis);
    m_superStructureStateMachine.RegisterSubsystem(&m_intake);

    m_EnabledLooper.StartLoop();
    m_DisabledLooper.StartLoop();
}

void Robot::RobotPeriodic() {
    m_EnabledLooper.OutputToSmartDashboard();
    m_DisabledLooper.OutputToSmartDashboard();
}
void Robot::AutonomousInit() {
    m_EnabledLooper.StartLoop();
    m_DisabledLooper.StartLoop();
}

void Robot::AutonomousPeriodic() {
    m_EnabledLooper.RunLoop();
    m_DisabledLooper.RunLoop();
}

void Robot::TeleopInit() {
    m_EnabledLooper.StartLoop();
    m_DisabledLooper.StartLoop();
}

void Robot::TeleopPeriodic() {
}

void Robot::TestPeriodic() {
}

void Robot::DisabledInit() {
    m_EnabledLooper.StartLoop();
    m_EnabledLooper.StartLoop();
}

void Robot::DisabledPeriodic() {
    m_EnabledLooper.StopLoop();
    m_DisabledLooper.StopLoop();
}

#ifndef RUNNING_FRC_TESTS
int main() {
    return frc::StartRobot<Robot>();
}
#endif

/*
    1. EnabledLooper & DisabledLooper contorl the state update.
    2. Subsystem manager controal the ReadInput() & WriteOutput().
*/
