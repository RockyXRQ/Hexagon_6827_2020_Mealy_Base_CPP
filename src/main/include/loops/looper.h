#ifndef LOOPER_H_
#define LOOPER_H_

#include <vector>
#include <string>

#include "loops/Loop.h"

class Looper {
   protected:
    std::vector<Loop *> *m_loopList;
    std::string m_looperName;
    bool m_Running = false;

    double m_timesTamp;

   public:
    Looper();
    Looper(std::vector<Loop *> *, const char *name = "default");

    virtual ~Looper() = default;

    void MutiRegister(std::vector<Loop *> *);
    void Register(Loop *);

    void StartLoop();
    void RunLoop();
    void StopLoop();

    void OutputToSmartDashboard();
};

#endif
