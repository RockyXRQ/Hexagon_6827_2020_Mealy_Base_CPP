#ifndef ROBOT_H_
#define ROBOT_H_

#include "loops/Looper.h"

#include "controlBoard/ControlBoard.h"

#include "subsystems/Chassis.h"

#include "subsystems/JetsonNanoCamera.h"

#include "subsystems/Intake.h"
#include "subsystems/Magazine.h"
#include "subsystems/Turret.h"
#include "subsystems/Gear.h"

#include "stateMachines/ChassisStateMachine.h"
#include "stateMachines/SuperStructureStateMachine.h"

#include "states/SuperStructureSate.h"

#include "infraSubsystemsOutputer/ChassisOutputer.h"
#include "infraSubsystemsOutputer/SuperStructureOutputer.h"

#include "auto/AutoExcutor.h"

#include <frc/TimedRobot.h>

class Robot : public frc::TimedRobot {
   public:
    // ControlBoard
    static ControlBoard m_controlBoard;

    // Chassis
    static Chassis m_chassis;

    // Subsystems
    static JetsonNanoCamera m_camera;

    static Intake m_intake;
    static Magazine m_magazine;
    static Turret m_turret;
    static Gear m_gear;

    // InfraSubsystemsOutputer
    static ChassisOutputer m_chassisOutputer;
    static SuperStructureOutputer m_superStructreOutputer;

    // StateMachines
    static ChassisStateMachine m_chassisStateMachine;
    static SuperStructureStateMachine m_superStructureStateMachine;

    // States
    static SuperStructureSate m_SuperStructureSate;

    // Looper
    static Looper m_EnabledLooper;
    static Looper m_DisabledLooper;

    // AutoExcutor
    static AutoExcutor m_autoExcutor;

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