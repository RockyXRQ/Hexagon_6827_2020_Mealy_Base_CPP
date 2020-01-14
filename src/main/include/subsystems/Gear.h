#ifndef GEAR_H_
#define GEAR_H_

#include "subsystems/ServoMotorSubsystem.h"
#include "Constants.h"

#include <ctre/Phoenix.h>

class Gear : public ServoMotorSubsystem {
   private:
    ctre::phoenix::motorcontrol::can::VictorSPX m_armMotor{
        constants::gear::GEAR_ARM_MOTOR_ID};
    ctre::phoenix::motorcontrol::can::VictorSPX m_handMotor{
        constants::gear::GEAR_HAND_MOTOR_ID};
    class PeriodicIO {
       public:
        // INPUT

        // OUTPUT
        double m_o_handDemand;
        double m_o_armDemand;
    } m_periodicIO;

   public:
    Gear(double kp = 0, double ki = 0, double kd = 0);
    void ReadInput() override;
    void WriteOutput() override;
    void ZeroSensors() override;
    void PrintToLog() override;

    void SetOpenLoopState();
    void SetPositionPIDState();

    void ManualArmSpin(double tempSpinSpeed = 0);
    void ManualHandSpin(double tempSpinSpeed = 0);
};

#endif