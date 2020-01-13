#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

#include "subsystems/Magazine.h"

Magazine::Magazine(double kp, double ki, double kd)
    : ServoMotorSubsystem(kp, ki, kd) {
    std::cout << "the subsystem Magazine instantiate!" << std::endl;
}

void Magazine::ReadInput() {
}

void Magazine::WriteOutput() {
    switch (m_state) {
        case OPEN_LOOP:
            m_spinMotorA.Set(ControlMode::PercentOutput,
                             m_periodicIO.m_o_spinDemand);
            m_spinMotorB.Set(ControlMode::PercentOutput,
                             -m_periodicIO.m_o_spinDemand);
            break;
        case POSITION_PID:
            m_spinMotorA.Set(ControlMode::PercentOutput,
                             m_periodicIO.m_o_spinDemand);
            m_spinMotorB.Set(ControlMode::PercentOutput,
                             -m_periodicIO.m_o_spinDemand);
            break;
    }
}

void Magazine::ZeroSensors() {
    m_periodicIO.m_o_spinDemand = 0;
}

void Magazine::PrintToLog() {
    switch (m_state) {
        case OPEN_LOOP:
            frc::SmartDashboard::PutString("Magazine Control State",
                                           "OPEN_LOOP");
            break;
        case POSITION_PID:
            frc::SmartDashboard::PutString("Magazine Control State",
                                           "POSITION_PID");
            break;
    }
    frc::SmartDashboard::PutNumber("Magazine Speed",
                                   m_periodicIO.m_o_spinDemand);
}

void Magazine::SetOpenLoopState(double tempSpinSpeed) {
    if (m_state != OPEN_LOOP) {
        std::cout << "Magazine mode switch to OPEN_LOOP" << std::endl;
        m_state = OPEN_LOOP;
    }
    m_periodicIO.m_o_spinDemand = tempSpinSpeed;
}
void Magazine::SetPositionPIDState() {
    if (m_state != POSITION_PID) {
        std::cout << "Magazine mode switch to POSITION_PID" << std::endl;
        m_state = POSITION_PID;
    }
}
