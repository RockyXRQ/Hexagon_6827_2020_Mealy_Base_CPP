#include "auto/modes/StartFromMid.h"

#include <iostream>

void StartFromMid::Start() {
    std::cout << "Auto Mode StartFromMid Start" << std::endl;
}

void StartFromMid::Resume() {
    switch (m_runStage) {
        case 1:
            GoToNextState(m_chassis->AutoDriveByLengenth(1));
            break;
        case 2:
            GoToNextState(m_turret->AutoAimHighHole());
            break;
        case 3:
            GoToNextState(m_magazine->AutoLoad(1) && m_turret->AutoShoot());
            break;
    }
}

void StartFromMid::Stop() {
    std::cout << "Auto Mode StartFromMid Stop" << std::endl;
}

void StartFromMid::GoToNextState(bool isDone) {
    if (isDone) ++m_runStage;
}