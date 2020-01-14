#include "subsystems/Gear.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

Gear::Gear(double kp, double ki, double kd) : ServoMotorSubsystem(kp, ki, kd) {
    std::cout << "the subsystem Gear instantiate!" << std::endl;
}

void Gear::ReadInput() {
}

void Gear::WriteOutput() {
    switch (m_state) {
        case OPEN_LOOP:
            m_armMotor.Set(ControlMode::PercentOutput,
                           m_periodicIO.m_o_armDemand);
            m_handMotor.Set(ControlMode::PercentOutput,
                            -m_periodicIO.m_o_handDemand);
            break;
        case POSITION_PID:
            m_armMotor.Set(ControlMode::PercentOutput,
                           m_periodicIO.m_o_armDemand);
            m_handMotor.Set(ControlMode::PercentOutput,
                            -m_periodicIO.m_o_handDemand);
            break;
    }
}

void Gear::ZeroSensors() {
    m_periodicIO.m_o_armDemand = 0;
    m_periodicIO.m_o_handDemand = 0;
}

void Gear::PrintToLog() {
    switch (m_state) {
        case OPEN_LOOP:
            frc::SmartDashboard::PutString("Gear Control State", "OPEN_LOOP");
            break;
        case POSITION_PID:
            frc::SmartDashboard::PutString("Gear Control State",
                                           "POSITION_PID");
            break;
    }
    frc::SmartDashboard::PutNumber("Gear Arm Speed",
                                   m_periodicIO.m_o_armDemand);
    frc::SmartDashboard::PutNumber("Gear Hand Speed",
                                   m_periodicIO.m_o_handDemand);
}

void Gear::SetOpenLoopState() {
    if (m_state != OPEN_LOOP) {
        std::cout << "Gear mode switch to OPEN_LOOP" << std::endl;
        m_state = OPEN_LOOP;
    }
}

void Gear::SetPositionPIDState() {
    if (m_state != OPEN_LOOP) {
        std::cout << "Gear mode switch to OPEN_LOOP" << std::endl;
        m_state = OPEN_LOOP;
    }
}

void Gear::ManualArmSpin(double tempSpinSpeed) {
    m_periodicIO.m_o_armDemand = tempSpinSpeed;
}

void Gear::ManualHandSpin(double tempSpinSpeed) {
    m_periodicIO.m_o_handDemand = tempSpinSpeed;
}