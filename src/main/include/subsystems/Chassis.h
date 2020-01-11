#ifndef CHASSIS_H_
#define CHASSIS_H_

#include <ctre/Phoenix.h>

#include "subsystems/ServoMotorSubsystem.h"
#include "loops/Looper.h"

class Chassis : public ServoMotorSubsystem {
   private:
    ctre::phoenix::motorcontrol::can::VictorSPX m_leftMotor{0};
    ctre::phoenix::motorcontrol::can::VictorSPX m_rightMotor{1};

    class PeriodicIO {
       public:
        // INPUT
        double m_i_kSpeerRate = 1;
        // OUTPUT
        double m_o_leftDemand;
        double m_o_rightDemand;
    } m_periodicIO;

   public:
    Chassis();

    void ReadInput() override;
    void WriteOutput() override;
    void ZeroSensors() override;
    void PrintToLog() override;

    void SetOpenLoopState(double tempLeftDemand = 0,
                          double tempRightDemand = 0);
    void SetPositionPIDState();

    void SetHighSpeedMode();
    void SetLowSpeedMode();
};

#endif