#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

#include "subsystems/Intake.h"

Intake::Intake() {
    std::cout << "the subsystem Intake instantiate!" << std::endl;
}

void Intake::ReadInput() {
}

void Intake::WriteOutput() {
    switch (m_state) {
        case OPEN_LOOP:
            m_leftMotor.Set(ControlMode::PercentOutput,
                            m_periodicIO.m_o_spinDemand);
            m_rightMotor.Set(ControlMode::PercentOutput,
                             -m_periodicIO.m_o_spinDemand);
            break;
        case POSITION_PID:
            m_leftMotor.Set(ControlMode::PercentOutput,
                            m_periodicIO.m_o_spinDemand);
            m_rightMotor.Set(ControlMode::PercentOutput,
                             -m_periodicIO.m_o_spinDemand);
            break;
    }
}

void Intake::ZeroSensors() {
}

void Intake::PrintToLog() {
    switch (m_state) {
        case OPEN_LOOP:
            frc::SmartDashboard::PutString("Intake Control State", "OPEN_LOOP");
            break;
        case POSITION_PID:
            frc::SmartDashboard::PutString("Intake Control State", "OPEN_LOOP");
            break;
    }
}

void Intake::SetOpenLoopState(double tempSpinSpeed) {
    if (m_state != OPEN_LOOP) {
        std::cout << "Intake mode switch to OPEN_LOOP" << std::endl;
        m_state = OPEN_LOOP;
    }
    m_periodicIO.m_o_spinDemand = (bool) tempSpinSpeed;
}

void Intake::SetPositionPIDState() {
    if (m_state != POSITION_PID) {
        std::cout << "Intake mode switch to POSITION_PID" << std::endl;
        m_state = POSITION_PID;
    }
}
