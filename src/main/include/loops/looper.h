#ifndef LOOPER_H_
#define LOOPER_H_

#include "loops/Loop.h"

#include <vector>
#include <string>

class Looper {
   protected:
    std::vector<Loop *> m_loopList;
    std::string m_looperName;
    bool m_Running = false;

    double m_timesTamp;

   public:
    Looper(const char *name = "default");

    void Register(Loop *);

    void StartLoop();
    void RunLoop();
    void StopLoop();

    void OutputToSmartDashboard();
};

#endif
