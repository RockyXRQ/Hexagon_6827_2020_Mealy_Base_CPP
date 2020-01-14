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

void SuperStructureStateMachine::RegisterGear(Gear *tempGear) {
    m_gear = tempGear;
}

void SuperStructureStateMachine::IntakeIntake() {
    m_intake->ManualSpin(-1);
}

void SuperStructureStateMachine::IntakeOutTake() {
    m_intake->ManualSpin(1);
}

void SuperStructureStateMachine::IntakeLock() {
    m_intake->ManualSpin(0);
}

void SuperStructureStateMachine::MagazineLoad() {
    m_magazine->ManualLoad(1);
}

void SuperStructureStateMachine::MagazineUnload() {
    m_magazine->ManualLoad(-1);
}

void SuperStructureStateMachine::MagazineLock() {
    m_magazine->ManualLoad(0);
}

void SuperStructureStateMachine::TurretLeftSpin() {
    m_turret->MaunalSpin(1);
}

void SuperStructureStateMachine::TurretRightSpin() {
    m_turret->MaunalSpin(-1);
}

void SuperStructureStateMachine::TurretShoot() {
    m_turret->ManualShoot(1);
}

void SuperStructureStateMachine::TurretLock() {
    m_turret->MaunalSpin(0);
}