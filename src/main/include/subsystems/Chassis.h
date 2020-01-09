#ifndef CHASSIS_H_
#define CHASSIS_H_

#include "subsystems/Subsystem.h"

class Chassis : public Subsystem {
   public:
    Chassis();

    void RegisterEnabledloop(Looper&) override;

    void ReadInput() override;
    void WriteOutput() override;
    void PrintToLog() override;
    void ZeroSensors() override;
};

#endif