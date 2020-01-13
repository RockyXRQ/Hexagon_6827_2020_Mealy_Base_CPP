#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

#include "subsystems/Turret.h"

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
    }
}

void Turret::ZeroSensors() {
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
}

void Turret::SetOpenLoopState(double tempSpinSpeed, double tempShootSpeed) {
    if (m_state != OPEN_LOOP) {
        std::cout << "Turret mode switch to OPEN_LOOP" << std::endl;
        m_state = OPEN_LOOP;
    }
    m_periodicIO.m_o_spinDemand = tempSpinSpeed;
    m_periodicIO.m_o_shootDemand = tempShootSpeed;
}

void Turret::SetPositionPIDState() {
    if (m_state != POSITION_PID) {
        std::cout << "Magazine mode switch to POSITION_PID" << std::endl;
        m_state = POSITION_PID;
    }
}