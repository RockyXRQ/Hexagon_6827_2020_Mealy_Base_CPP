#ifndef LOOP_H_
#define LOOP_H_
#pragma once

class Loop {
   public:
    Loop();
    virtual ~Loop();

    virtual void onStart(double timeTamp = 0) = 0;
    virtual void onLoop(double timeTamp = 0) = 0;
    virtual void onStop(double timeTamp = 0) = 0;
};

#endif
