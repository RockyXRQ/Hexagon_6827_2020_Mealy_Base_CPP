#ifndef INTAKE_H_
#define INTAKE_H_

#include <ctre/Phoenix.h>

#include "subsystems/ServoMotorSubsystem.h"
#include "loops/Looper.h"

class Intake : public ServoMotorSubsystem {
    ctre::phoenix::motorcontrol::can::VictorSPX m_leftMotor{0};
    ctre::phoenix::motorcontrol::can::VictorSPX m_rightMotor{1};

	class PeriodicIO {
       public:
        // INPUT
        
        // OUTPUT
        double m_o_spinDemand;
        
    } m_periodicIO;

   public:
    Intake();

    void RegisterEnabledloop(Looper&) override;

    void ReadInput() override;
    void WriteOutput() override;
    void ZeroSensors() override;
    void PrintToLog() override;

	void SetOpenLoopState();
	void SetPositionPIDState();
};

#endif
