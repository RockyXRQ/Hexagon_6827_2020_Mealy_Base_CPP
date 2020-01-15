#include "states/SuperStructureSate.h"

SuperStructureSate::SuperStructureSate() {
    m_targetX = 0;
    m_targetY = 0;

    m_actualX = 0;
    m_actualY = 0;
}

double SuperStructureSate::GetTargetX() {
    return m_targetX;
}

double SuperStructureSate::GetTargetY() {
    return m_targetY;
}

double SuperStructureSate::GetActualX() {
    return m_actualX;
}

double SuperStructureSate::GetActualY() {
    return m_actualY;
}