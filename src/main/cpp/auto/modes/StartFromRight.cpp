#include "auto/modes/StartFromRight.h"

#include <iostream>

void StartFromRight::Start() {
    std::cout << "Auto Mode StartFromRight Start" << std::endl;
}

void StartFromRight::Resume() {
    switch (m_runStage) {
        case 1:
            GoToNextState(m_chassis->AutoDriveByLengenth(1));
            break;
        case 2:
            GoToNextState(m_chassis->AutoTurnByDegree(-90));
            break;
        case 3:
            GoToNextState(m_chassis->AutoDriveByLengenth(1));
            break;
        case 4:
            GoToNextState(m_turret->AutoAimHighHole());
            break;
        case 5:
            GoToNextState(m_magazine->AutoLoad(1) && m_turret->AutoShoot());
            break;
    }
}

void StartFromRight::Stop() {
    std::cout << "Auto Mode StartFromRight Stop" << std::endl;
}

void StartFromRight::GoToNextState(bool isDone) {
    if (isDone) ++m_runStage;
}
