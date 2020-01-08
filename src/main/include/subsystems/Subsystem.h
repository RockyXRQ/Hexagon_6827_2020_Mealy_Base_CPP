#ifndef SUBSYSTEM_H_
#define SUBSYSTEM_H_

#pragma once

class Subsystem {
   public:
    Subsystem();
    virtual ~Subsystem();

    virtual void PrintToLog() = 0;
    virtual void ReadInputs() = 0;
    virtual void WriteOutputs() = 0;
    virtual void RegisterEnabledLoops() = 0;
    virtual void ResetSensors() = 0;
    virtual void WentToDefaultState() = 0;
};

#endif