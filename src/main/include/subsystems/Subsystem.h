#ifndef SUBSYSTEM_H_
#define SUBSYSTEM_H_

#include "loops/Looper.h"
class Subsystem {
   public:
    virtual void ReadInput() = 0;
    virtual void WriteOutput() = 0;
    virtual void PrintToLog() = 0;
    virtual void ZeroSensors() = 0;
};

#endif