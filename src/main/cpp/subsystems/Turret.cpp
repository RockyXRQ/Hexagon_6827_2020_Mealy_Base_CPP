#include "subsystems/Turret.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

Turret::Turret(double kp, double ki, double kd)
    : ServoMotorSubsystem(kp, ki, kd) {
    std::cout << "the subsystem Turret instantiate!" << std::endl;
}

void Turret::ReadInput() {
}

void Turret::WriteOutput() {
    switch (m_state) {
        case OPEN_LOOP:
            m_spinMotor.Set(ControlMode::PercentOutput,
                            m_periodicIO.m_o_spinDemand);
            m_shootMotor.Set(ControlMode::PercentOutput,
                             m_periodicIO.m_o_shootDemand);
            m_aimServo.Set(m_periodicIO.m_o_servoTargetPosition);
            break;
        case POSITION_PID:
            m_spinMotor.Set(ControlMode::PercentOutput,
                            m_periodicIO.m_o_spinDemand);
            m_shootMotor.Set(ControlMode::PercentOutput,
                             m_periodicIO.m_o_shootDemand);
            m_aimServo.Set(m_periodicIO.m_o_servoTargetPosition);
            break;
    }
}

void Turret::ZeroSensors() {
    m_periodicIO.m_i_actualPosition = 0;
    m_periodicIO.m_i_targetPosition = 0;

    m_periodicIO.m_o_servoTargetPosition =
        constants::turret::SERVO_HIGH_POSITION;
    m_periodicIO.m_o_spinDemand = 0;
    m_periodicIO.m_o_shootDemand = 0;
}

void Turret::PrintToLog() {
    switch (m_state) {
        case OPEN_LOOP:
            frc::SmartDashboard::PutString("Turret Control State", "OPEN_LOOP");
            break;
        case POSITION_PID:
            frc::SmartDashboard::PutString("Turret Control State",
                                           "POSITION_PID");
            break;
    }
    frc::SmartDashboard::PutNumber("Turret spin speed",
                                   m_periodicIO.m_o_spinDemand);
    frc::SmartDashboard::PutNumber("Turret shoot speed",
                                   m_periodicIO.m_o_shootDemand);
    frc::SmartDashboard::PutString("Turret aim positioin",
                                   m_periodicIO.m_o_servoTargetPosition ==
                                           constants::turret::SERVO_LOW_POSITION
                                       ? "High"
                                       : "Low");
}

void Turret::SetOpenLoopState() {
    if (m_state != OPEN_LOOP) {
        std::cout << "Turret mode switch to OPEN_LOOP" << std::endl;
        m_state = OPEN_LOOP;
    }
}

void Turret::SetPositionPIDState() {
    if (m_state != POSITION_PID) {
        std::cout << "Magazine mode switch to POSITION_PID" << std::endl;
        m_state = POSITION_PID;
    }
}
void Turret::MaunalSpin(double tempSpinSpeed) {
    m_periodicIO.m_o_spinDemand = tempSpinSpeed;
}
void Turret::ManualShoot(double tempShootSpeed) {
    m_periodicIO.m_o_shootDemand = tempShootSpeed;
}

void Turret::ManualAimHighHole() {
    m_periodicIO.m_o_servoTargetPosition =
        constants::turret::SERVO_HIGH_POSITION;
}

void Turret::ManualAimLowHole() {
    m_periodicIO.m_o_servoTargetPosition =
        constants::turret::SERVO_LOW_POSITION;
}