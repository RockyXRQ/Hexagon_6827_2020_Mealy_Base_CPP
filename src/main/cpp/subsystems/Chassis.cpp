#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

#include "subsystems/Chassis.h"

Chassis::Chassis() {
    std::cout << "the subsystem Chassis instantiate!" << std::endl;
}

void Chassis::ReadInput() {
}

void Chassis::WriteOutput() {
    switch (m_state) {
        case OPEN_LOOP:
            m_leftMotor.Set(
                ControlMode::PercentOutput,
                m_periodicIO.m_o_leftDemand * m_periodicIO.m_i_kSpeedRate);
            m_rightMotor.Set(
                ControlMode::PercentOutput,
                m_periodicIO.m_o_leftDemand * m_periodicIO.m_i_kSpeedRate);
            break;
        case POSITION_PID:
            m_leftMotor.Set(
                ControlMode::PercentOutput,
                m_periodicIO.m_o_leftDemand * m_periodicIO.m_i_kSpeedRate);
            m_rightMotor.Set(
                ControlMode::PercentOutput,
                m_periodicIO.m_o_leftDemand * m_periodicIO.m_i_kSpeedRate);
            break;
    }
}

void Chassis::ZeroSensors() {
    m_periodicIO.m_i_kSpeedRate = 1;
    m_periodicIO.m_o_leftDemand = 0;
    m_periodicIO.m_o_rightDemand = 0;
}

void Chassis::PrintToLog() {
    switch (m_state) {
        case OPEN_LOOP:
            frc::SmartDashboard::PutString("Chassis Control State",
                                           "OPEN_LOOP");
            break;
        case POSITION_PID:
            frc::SmartDashboard::PutString("Chassis Control State",
                                           "OPEN_LOOP");
            break;
    }
}

void Chassis::SetOpenLoopState(double tempLeftDemand, double tempRightDemand) {
    if (m_state != OPEN_LOOP) {
        std::cout << "Drive mode switch to OPEN_LOOP" << std::endl;
        m_state = OPEN_LOOP;
    }
    m_periodicIO.m_o_leftDemand = tempLeftDemand;
    m_periodicIO.m_o_rightDemand = tempRightDemand;
}

void Chassis::SetPositionPIDState() {
    if (m_state != POSITION_PID) {
        std::cout << "Drive mode switch to POSITION_PID" << std::endl;
        m_state = POSITION_PID;
    }
}

void Chassis::SetHighSpeedMode() {
    m_periodicIO.m_i_kSpeedRate = 1;
}

void Chassis::SetLowSpeedMode() {
    m_periodicIO.m_i_kSpeedRate = 0.6;
}