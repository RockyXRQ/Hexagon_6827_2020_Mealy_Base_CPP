#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Timer.h>

#include "loops/looper.h"

looper::looper() {
    m_timesTamp = frc::Timer::GetFPGATimestamp();
}

looper::looper(std::list<loop &> &tempLoopList, const char *name = "default")
    : looper() {
    m_looperName = name;
    for (auto &l : tempLoopList) {
        SingleRegister(l);
    }
}

void looper::SingleRegister(loop &tempLoop) {
    m_loopList.push_back(tempLoop);
}

void looper::MutiRegister(std::list<loop &> &tempLoopList) {
    for (auto &l : tempLoopList) {
        SingleRegister(l);
    }
}

void looper::StartLoop() {
    std::cout << m_looperName << " start looping" << std::endl;
    for (auto &l : m_loopList) {
        l.onStart();
    }
    m_Running = true;
}

void looper::RunLoop() {
    std::cout << m_looperName << " is looping" << std::endl;
    for (auto &l : m_loopList) {
        l.onLoop();
    }
}

void looper::StopLoop() {
    std::cout << m_looperName << " stop looping" << std::endl;
    for (auto &l : m_loopList) {
        l.onStop();
    }
    m_Running = false;
}

void looper::OutputToSmartDashboard() {
    double m_dt =
        -(m_timesTamp - (m_timesTamp = frc::Timer::GetFPGATimestamp()));
    frc::SmartDashboard::PutNumber(m_looperName + " loop rate", 1.0 / m_dt);
}
