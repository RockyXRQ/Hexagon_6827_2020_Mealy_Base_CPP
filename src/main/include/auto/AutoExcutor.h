#ifndef AUTO_EXCUTOR_H_
#define AUTO_EXCUTOR_H_

#include "auto/modes/AutoModeBase.h"
#include "auto/modes/StartFromLeft.h"
#include "auto/modes/StartFromMid.h"
#include "auto/modes/StartFromRight.h"

class AutoExcutor {
   private:
    StartFromLeft m_startFromLeft;
    StartFromRight m_startFromRight;
    StartFromMid m_startFromMid;

    AutoModeBase* m_autoMode;

   public:
    AutoExcutor();
    
    void SetMode(int);

    void Start();
    void Run();
    void Stop();
};

#endif
