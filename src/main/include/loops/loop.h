#pragma once

class loop {
   public:
    loop();
    virtual void onStart(double timeTamp = 0) = 0;
    virtual void onLoop(double timeTamp = 0) = 0;
    virtual void onStop(double timeTamp = 0) = 0;
};
