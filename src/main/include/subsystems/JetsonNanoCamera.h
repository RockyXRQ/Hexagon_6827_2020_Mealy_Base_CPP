#ifndef JETSON_NANO_CAMERA_H_
#define JETSON_NANO_CAMERA_H_

#include "Subsystem.h"

class JetsonNanoCamera : public Subsystem {
   public:
    JetsonNanoCamera();
    void ReadInput() override;
    void WriteOutput() override;
    void ZeroSensors() override;
    void PrintToLog() override;
};

#endif
