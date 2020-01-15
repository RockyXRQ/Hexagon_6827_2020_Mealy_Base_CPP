#include "auto/modes/StartFromLeft.h"

#include <iostream>

void StartFromLeft::Start() {
    std::cout << "Auto Mode StartFromLeft Start" << std::endl;
}

void StartFromLeft::Resume() {
    switch (m_runStage) {
        case 1:
            GoToNextState(m_chassis->AutoDriveByLengenth(1));
            break;
        case 2:
            GoToNextState(m_chassis->AutoTurnByDegree(90));
            break;
        case 3:
            GoToNextState(m_chassis->AutoDriveByLengenth(1));
            break;
        case 4:
            GoToNextState(m_turret->AutoAimHighHole());
            break;
        case 5:
            GoToNextState(m_turret->AutoShoot());
            break;
    }
}

void StartFromLeft::Stop() {
    std::cout << "Auto Mode StartFromLeft Stop" << std::endl;
}

void StartFromLeft::GoToNextState(bool isDone) {
    if (isDone) ++m_runStage;
}