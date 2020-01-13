#include "stateMachines/SuperStructureStateMachine.h"

SuperStructureStateMachine::SuperStructureStateMachine() {
}

void SuperStructureStateMachine::RegisterCamera(JetsonNanoCamera *tempCamera) {
    m_camera = tempCamera;
}

void SuperStructureStateMachine::RegisterIntake(Intake *tempIntake) {
    m_intake = tempIntake;
}

void SuperStructureStateMachine::RegisterMagazine(Magazine *tempMagazine) {
    m_magazine = tempMagazine;
}

void SuperStructureStateMachine::RegisterTurret(Turret *tempTurret) {
    m_turret = tempTurret;
}

void SuperStructureStateMachine::IntakeIntake() {
}

void SuperStructureStateMachine::IntakeOutTake() {
}

void SuperStructureStateMachine::IntakeLock() {
}

void SuperStructureStateMachine::MagazineLoad() {
}

void SuperStructureStateMachine::MagazineUnload() {
}

void SuperStructureStateMachine::MagazineLock() {
}

void SuperStructureStateMachine::TurretLeftSpin() {
}

void SuperStructureStateMachine::TurretRightSpin() {
}

void SuperStructureStateMachine::TurretShoot() {
}

void SuperStructureStateMachine::TurretLock() {
}