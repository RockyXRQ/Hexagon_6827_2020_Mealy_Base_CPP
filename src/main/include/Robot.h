/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/TimedRobot.h>
#include <frc/WPILib.h>
#include <frc/commands/Command.h>

#include "loops/Looper.h"

#include "controlBoard/ControlBoard.h"

#include "subsystems/Chassis.h"

#include "stateMachines/ChassisStateMachine.h"
#include "stateMachines/SuperStructureStateMachine.h"

#include "infraSubsystemsOutputer/ChassisOutputer.h"
#include "infraSubsystemsOutputer/SuperStructureOutputer.h"

class Robot : public frc::TimedRobot {
   private:

   
    void RobotInit() override;
    void RobotPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void TestPeriodic() override;
};
