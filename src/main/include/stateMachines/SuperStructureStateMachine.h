#ifndef SUPERSTRUCTURE_STATEMACHINE_H_
#define SUPERSTRUCTURE_STATEMACHINE_H_

#include "subsystems/Intake.h"
#include "subsystems/Magazine.h"
#include "subsystems/Turret.h"
#include "subsystems/Gear.h"

#include "subsystems/JetsonNanoCamera.h"

class SuperStructureStateMachine {
   private:
    JetsonNanoCamera *m_camera = nullptr;
    Intake *m_intake = nullptr;
    Magazine *m_magazine = nullptr;
    Turret *m_turret = nullptr;
    Gear *m_gear = nullptr;

   public:
    SuperStructureStateMachine();

    void RegisterCamera(JetsonNanoCamera *);
    void RegisterIntake(Intake *);
    void RegisterMagazine(Magazine *);
    void RegisterTurret(Turret *);
    void RegisterGear(Gear *);

    void IntakeIntake();
    void IntakeOutTake();
    void IntakeLock();

    void MagazineLoad();
    void MagazineUnload();
    void MagazineLock();

    void TurretLeftSpin();
    void TurretRightSpin();
    void TurretLock();
    void TurretShoot();
};

#endif
