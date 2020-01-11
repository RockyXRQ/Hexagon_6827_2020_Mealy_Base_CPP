#ifndef LOOP_H_
#define LOOP_H_
#pragma once

#include <subsystems/Subsystem.h>

class Loop {
   public:
    virtual void RegisterSubsystem(Subsystem*) = 0;
    virtual void OnStart(double timeTamp = 0) = 0;
    virtual void OnLoop(double timeTamp = 0) = 0;
    virtual void OnStop(double timeTamp = 0) = 0;
};

#endif
