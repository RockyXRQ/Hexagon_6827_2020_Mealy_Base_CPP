#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Timer.h>

#include "loops/Looper.h"

Looper::Looper() {
    m_timesTamp = frc::Timer::GetFPGATimestamp();
}

Looper::Looper(std::vector<Loop *> *tempLoopList, const char *name) : Looper() {
    m_looperName = name;
    for (auto l : *tempLoopList) {
        Register(l);
    }
}

void Looper::Register(Loop *tempLoop) {
    m_loopList->push_back(tempLoop);
}

void Looper::MutiRegister(std::vector<Loop *> *tempLoopList) {
    for (auto l : *tempLoopList) {
        Register(l);
    }
}

void Looper::StartLoop() {
    std::cout << m_looperName << " start looping" << std::endl;
    for (auto l : *m_loopList) {
        l->onStart();
    }
    m_Running = true;
}

void Looper::RunLoop() {
    std::cout << m_looperName << " is looping" << std::endl;
    for (auto l : *m_loopList) {
        l->onLoop();
    }
}

void Looper::StopLoop() {
    std::cout << m_looperName << " stop looping" << std::endl;
    for (auto l : *m_loopList) {
        l->onStop();
    }
    m_Running = false;
}

void Looper::OutputToSmartDashboard() {
    double m_dt = -(m_timesTamp - frc::Timer::GetFPGATimestamp());
    m_timesTamp = frc::Timer::GetFPGATimestamp();
    frc::SmartDashboard::PutNumber(m_looperName + " Loop rate", 1.0 / m_dt);
}
