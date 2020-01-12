#ifndef ROBOT_H_
#define ROBOT_H_

#include <frc/TimedRobot.h>

#include "loops/Looper.h"

#include "controlBoard/ControlBoard.h"

#include "subsystems/Chassis.h"
#include "subsystems/Intake.h"

#include "stateMachines/ChassisStateMachine.h"
#include "stateMachines/SuperStructureStateMachine.h"

#include "infraSubsystemsOutputer/ChassisOutputer.h"
#include "infraSubsystemsOutputer/SuperStructureOutputer.h"

#include "Constants.h"

class Robot : public frc::TimedRobot {
   private:
    //ControlBoard
    ControlBoard m_controlBoard;

    //Chassis
    Chassis m_chassis;

    //Subsystems
    Intake m_intake;

    //InfraSubsystemsOutputer
    ChassisOutputer m_chassisOutputer;
    SuperStructureOutputer m_superStructreOutputer;

    //StateMachines
    ChassisStateMachine m_chassisStateMachine;
    SuperStructureStateMachine m_superStructureStateMachine;
    
    //Looper
    Looper m_EnabledLooper{"EnabledLooper"};
    Looper m_DisabledLooper{"DisabledLooper"};

    void RobotInit() override;
    void RobotPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void TestPeriodic() override;
    void DisabledInit() override;
    void DisabledPeriodic() override;
};

#endif