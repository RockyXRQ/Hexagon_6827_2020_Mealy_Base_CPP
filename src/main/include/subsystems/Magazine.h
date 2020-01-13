#ifndef MAGAZINE_H_
#define MAGAZINE_H_

#include <ctre/Phoenix.h>

#include "subsystems/ServoMotorSubsystem.h"
#include "Constants.h"

class Magazine : public ServoMotorSubsystem {
   private:
    ctre::phoenix::motorcontrol::can::VictorSPX m_spinMotorA{
        constants::magazine::MAGAZINE_SPIN_A_MOTOR_ID};
    ctre::phoenix::motorcontrol::can::VictorSPX m_spinMotorB{
        constants::magazine::MAGAZINE_SPIN_B_MOTOR_ID};

    class PeriodicIO {
       public:
        // INPUT

        // OUTPUT
        double m_o_spinDemand;

    } m_periodicIO;

   public:
    Magazine(double kp = 0, double ki = 0, double kd = 0);
    void ReadInput() override;
    void WriteOutput() override;
    void ZeroSensors() override;
    void PrintToLog() override;

    void SetOpenLoopState(double tempSpinSpeed = 0);
    void SetPositionPIDState();
};

#endif
