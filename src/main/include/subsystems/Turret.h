#ifndef TURRET_H_
#define TURRET_H_

#include "subsystems/ServoMotorSubsystem.h"
#include "Constants.h"

#include <frc/Servo.h>
#include <ctre/Phoenix.h>

#include <Robot.h>

class Turret : public ServoMotorSubsystem {
   private:
    ctre::phoenix::motorcontrol::can::VictorSPX m_spinMotor{
        constants::turret::TURRET_SPIN_MOTOR_ID};
    ctre::phoenix::motorcontrol::can::VictorSPX m_shootMotor{
        constants::turret::TURRET_SHOOT_MOTOR_ID};
    frc::Servo m_aimServo{constants::turret::TURRET_AIM_SERVO_CHANNEL};
    class PeriodicIO {
       public:
        // INPUT
        double m_i_actualPosition;
        double m_i_targetPosition;
        // OUTPUT
        double m_o_shootDemand;
        double m_o_spinDemand;
        double m_o_servoTargetPosition;
    } m_periodicIO;

   public:
    Turret(double kp = 0, double ki = 0, double kd = 0);
    void ReadInput() override;
    void WriteOutput() override;
    void ZeroSensors() override;
    void PrintToLog() override;

    void SetOpenLoopState();
    void SetPositionPIDState();

    void MaunalSpin(double tempSpinSpeed = 0);
    void ManualShoot(double tempShootSpeed = 0);
    void ManualAimHighHole();
    void ManualAimLowHole();

    bool AutoAimHighHole();
    bool AutoShoot();
};

#endif