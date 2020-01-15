#include "auto/AutoExcutor.h"

AutoExcutor::AutoExcutor()
    : m_startFromLeft(), m_startFromMid(), m_startFromRight() {
}

void AutoExcutor::SetMode(int tempMode) {
    switch (tempMode) {
        case 1:
            m_autoMode = &m_startFromRight;
            break;
        case 2:
            m_autoMode = &m_startFromMid;
            break;
        case 3:
            m_autoMode = &m_startFromLeft;
            break;
    }
}

void AutoExcutor::Start() {
    m_autoMode->Start();
}

void AutoExcutor::Run() {
    m_autoMode->Resume();
}

void AutoExcutor::Stop() {
    m_autoMode->Stop();
}