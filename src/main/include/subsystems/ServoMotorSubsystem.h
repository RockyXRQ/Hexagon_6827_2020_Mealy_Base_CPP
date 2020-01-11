#ifndef SERVO_MOTOR_SUBSYSTEM_H_
#define SERVO_MOTOR_SUBSYSTEM_H_

#include "subsystems/Subsystem.h"
#include "loops/Looper.h"

class ServoMotorSubsystem : public Subsystem {
   protected:
    enum ControlState { OPEN_LOOP, POSITION_PID } m_state = OPEN_LOOP;

   private:
    double m_kp, m_ki, m_kd;
    double m_integral;

    double m_ka, m_kf;

    double m_maxIOutput = 1;
    double m_maxDoutput = 1;

    double m_error = 0;
    double m_lastError = 0;

   public:
    ServoMotorSubsystem(double kp = 0, double ki = 0, double kd = 0);

    double PositionPIDOutput(double actualPosition, double targetPosition);
    void SetMaxIOutput(double MaxIOutput = 1);
    void SetMaxDOutput(double MaxDOutput = 1);
};

#endif