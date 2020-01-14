#ifndef INTAKE_H_
#define INTAKE_H_

#include "subsystems/ServoMotorSubsystem.h"
#include "Constants.h"

#include <ctre/Phoenix.h>

class Intake : public ServoMotorSubsystem {
    ctre::phoenix::motorcontrol::can::VictorSPX m_spinMotor{
        constants::intake::INTAKE_SPIN_MOTOR_ID};

    class PeriodicIO {
       public:
        // INPUT

        // OUTPUT
        double m_o_spinDemand;

    } m_periodicIO;

   public:
    Intake(double kp = 0, double ki = 0, double kd = 0);

    void ReadInput() override;
    void WriteOutput() override;
    void ZeroSensors() override;
    void PrintToLog() override;

    void SetOpenLoopState();
    void SetPositionPIDState();

    void ManualSpin(double tempSpinSpeed = 0);
};

#endif
