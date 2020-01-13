#ifndef SUPERSTRUCTURE_STATEMACHINE_H_
#define SUPERSTRUCTURE_STATEMACHINE_H_

#include "subsystems/Intake.h"
#include "subsystems/Magazine.h"
#include "subsystems/Turret.h"
#include "subsystems/JetsonNanoCamera.h"

class SuperStructureStateMachine {
   private:
    JetsonNanoCamera *m_camera;
    Intake *m_intake;
    Magazine *m_magazine;
    Turret *m_turret;

   public:
    SuperStructureStateMachine();

    void RegisterCamera(JetsonNanoCamera *);
    void RegisterIntake(Intake *);
    void RegisterMagazine(Magazine *);
    void RegisterTurret(Turret *);

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
