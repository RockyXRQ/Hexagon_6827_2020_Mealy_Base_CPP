#ifndef JETSON_NANO_CAMERA_H_
#define JETSON_NANO_CAMERA_H_

#include "Subsystem.h"
#include "subsystems/Turret.h"
#include "states/SuperStructureSate.h"

#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>

class JetsonNanoCamera : public Subsystem {
   private:
    std::shared_ptr<nt::NetworkTable> m_networkTable =
        nt::NetworkTable::GetTable("VISION_TABLE");
    class PeriodicIO {
       public:
        // INPUT
        double m_i_targetX;
        double m_i_targetY;
        // OUTPUT
    } m_periodicIO;

    SuperStructureSate *m_superStructureState;

   public:
    JetsonNanoCamera();
    void RegisterState(SuperStructureSate *);

    void ReadInput() override;
    void WriteOutput() override;
    void ZeroSensors() override;
    void PrintToLog() override;
};

#endif
