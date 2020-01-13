#ifndef TURRET_H_
#define TURRET_H_

#include <ctre/Phoenix.h>

#include "subsystems/ServoMotorSubsystem.h"
#include "Constants.h"

class Turret : public ServoMotorSubsystem {
   private:
    ctre::phoenix::motorcontrol::can::VictorSPX m_spinMotor{
        constants::turret::TURRET_SPIN_MOTOR_ID};
    ctre::phoenix::motorcontrol::can::VictorSPX m_shootMotor{
        constants::turret::TURRET_SHOOT_MOTOR_ID};

    class PeriodicIO {
       public:
        // INPUT

        // OUTPUT
        double m_o_shootDemand;
        double m_o_spinDemand;

    } m_periodicIO;

   public:
    Turret(double kp = 0, double ki = 0, double kd = 0);
    void ReadInput() override;
    void WriteOutput() override;
    void ZeroSensors() override;
    void PrintToLog() override;

    void SetOpenLoopState(double tempSpinSpeed = 0, double tempShootSpeed = 0);
    void SetPositionPIDState();
};

#endif