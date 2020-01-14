#include "subsystems/Intake.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

Intake::Intake(double kp, double ki, double kd)
    : ServoMotorSubsystem(kp, ki, kd) {
    std::cout << "the subsystem Intake instantiate!" << std::endl;
}

void Intake::ReadInput() {
}

void Intake::WriteOutput() {
    switch (m_state) {
        case OPEN_LOOP:
            m_spinMotor.Set(ControlMode::PercentOutput,
                            m_periodicIO.m_o_spinDemand);
            break;
        case POSITION_PID:
            m_spinMotor.Set(ControlMode::PercentOutput,
                            m_periodicIO.m_o_spinDemand);
            break;
    }
}

void Intake::ZeroSensors() {
    m_periodicIO.m_o_spinDemand = 0;
}

void Intake::PrintToLog() {
    switch (m_state) {
        case OPEN_LOOP:
            frc::SmartDashboard::PutString("Intake Control State", "OPEN_LOOP");
            break;
        case POSITION_PID:
            frc::SmartDashboard::PutString("Intake Control State",
                                           "POSITION_PID");
            break;
    }
    frc::SmartDashboard::PutNumber("Intake Speed", m_periodicIO.m_o_spinDemand);
}

void Intake::SetOpenLoopState() {
    if (m_state != OPEN_LOOP) {
        std::cout << "Intake mode switch to OPEN_LOOP" << std::endl;
        m_state = OPEN_LOOP;
    }
}

void Intake::SetPositionPIDState() {
    if (m_state != POSITION_PID) {
        std::cout << "Intake mode switch to POSITION_PID" << std::endl;
        m_state = POSITION_PID;
    }
}

void Intake::ManualSpin(double tempSpinSpeed) {
    m_periodicIO.m_o_spinDemand = tempSpinSpeed;
}