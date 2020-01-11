#ifndef INTAKE_H_
#define INTAKE_H_

#include <ctre/Phoenix.h>

#include "subsystems/ServoMotorSubsystem.h"
#include "loops/Looper.h"

class Intake : public ServoMotorSubsystem {
    ctre::phoenix::motorcontrol::can::VictorSPX m_leftMotor{2};
    ctre::phoenix::motorcontrol::can::VictorSPX m_rightMotor{3};

    class PeriodicIO {
       public:
        // INPUT

        // OUTPUT
        double m_o_spinDemand;

    } m_periodicIO;

   public:
    Intake();

    void ReadInput() override;
    void WriteOutput() override;
    void ZeroSensors() override;
    void PrintToLog() override;

    void SetOpenLoopState(double tempSpinSpeed = 0);
    void SetPositionPIDState();
};

#endif
