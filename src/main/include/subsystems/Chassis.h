#ifndef CHASSIS_H_
#define CHASSIS_H_

#include "subsystems/ServoMotorSubsystem.h"
#include "Constants.h"

#include <ctre/Phoenix.h>

class Chassis : public ServoMotorSubsystem {
   private:
    ctre::phoenix::motorcontrol::can::VictorSPX m_leftMotor{
        constants::chassis::CHASSIS_LEFT_MOTOR_ID};
    ctre::phoenix::motorcontrol::can::VictorSPX m_rightMotor{
        constants::chassis::CHASSIS_RIGHT_MOTOR_ID};

    class PeriodicIO {
       public:
        // INPUT
        double m_i_kSpeedRate = 1;
        // OUTPUT
        double m_o_leftDemand;
        double m_o_rightDemand;
    } m_periodicIO;

   public:
    Chassis(double kp = 0, double ki = 0, double kd = 0);

    void ReadInput() override;
    void WriteOutput() override;
    void ZeroSensors() override;
    void PrintToLog() override;

    void SetOpenLoopState();
    void SetPositionPIDState();

    void ManualDrive(double tempStrightSpeed = 0, double tempTurnSpeed = 0);
    void SetHighSpeedMode();
    void SetLowSpeedMode();
};

#endif