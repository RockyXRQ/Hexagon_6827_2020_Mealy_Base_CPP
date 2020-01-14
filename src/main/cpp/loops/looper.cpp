#include "loops/Looper.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Timer.h>

Looper::Looper(const char *name) {
     m_timesTamp = frc::Timer::GetFPGATimestamp();
    m_looperName = name;
}

void Looper::Register(Loop *tempLoop) {
    m_loopList->push_back(tempLoop);
}

void Looper::StartLoop() {
    std::cout << m_looperName << " start looping" << std::endl;
    for (auto l : *m_loopList) {
        l->OnStart();
    }
    m_Running = true;
}

void Looper::RunLoop() {
    std::cout << m_looperName << " is looping" << std::endl;
    for (auto l : *m_loopList) {
        l->OnLoop();
    }
}

void Looper::StopLoop() {
    std::cout << m_looperName << " stop looping" << std::endl;
    for (auto l : *m_loopList) {
        l->OnStop();
    }
    m_Running = false;
}

void Looper::OutputToSmartDashboard() {
    double m_dt = -(m_timesTamp - frc::Timer::GetFPGATimestamp());
    m_timesTamp = frc::Timer::GetFPGATimestamp();
    frc::SmartDashboard::PutNumber(m_looperName + " Loop rate", 1.0 / m_dt);
}
