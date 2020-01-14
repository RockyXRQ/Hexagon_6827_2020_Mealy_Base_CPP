#include "states/SuperStructureSate.h"

SuperStructureSate::SuperStructureSate() {
    m_targetX = 0;
    m_targetY = 0;
}

double SuperStructureSate::GetTargetX() {
    return m_targetX;
}

double SuperStructureSate::GetTargetY() {
    return m_targetY;
}