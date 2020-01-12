#ifndef SUPERSTRUCTURE_STATEMACHINE_H_
#define SUPERSTRUCTURE_STATEMACHINE_H_

#include <vector>

#include "subsystems/Subsystem.h"

class SuperStructureStateMachine {
   private:
    std::vector<Subsystem *> m_subsystemList;

   public:
    SuperStructureStateMachine();
    void RegisterSubsystem(Subsystem *);
    
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
