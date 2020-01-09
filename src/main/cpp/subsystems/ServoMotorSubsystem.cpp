#include "subsystems/ServoMotorSubsystem.h"

ServoMotorSubsystem::ServoMotorSubsystem(double kp = 0, double ki = 0,
                                         double kd = 0) {
    m_kp = kp;
    m_ki = ki;
    m_kd = kd;
}

void ServoMotorSubsystem::SetMaxIOutput(double MaxIOutput = 1) {
    m_maxIOutput = MaxIOutput;
}

void ServoMotorSubsystem::SetMaxDOutput(double MaxDOutput = 1) {
    m_maxDoutput = MaxDOutput;
}

double ServoMotorSubsystem::PositionPIDOutput(double actualPosition,
                                              double targetPosition) {
    m_error = targetPosition - actualPosition;
    double pOutput = m_kp * m_error;
    m_integral += m_error;
    double iOutput = m_ki * m_integral;
    double dOutput = m_kd * (m_error - m_lastError);
    m_lastError = m_error;
    return pOutput + iOutput + dOutput;
}