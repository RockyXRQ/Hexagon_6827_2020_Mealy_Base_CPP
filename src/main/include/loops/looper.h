#ifndef LOOPER_H_
#define LOOPER_H_

#include <list>
#include <string>

#include "loops/loop.h"

class looper {
   private:
    std::list<loop &> m_loopList;
    std::string m_looperName;
    bool m_Running = false;

    double m_timesTamp;

   public:
    looper();
    looper(std::list<loop &> &, const char *name = "default");

    looper(const looper &) = default;
    looper(looper &&) = default;

    ~looper() = default;

    void MutiRegister(std::list<loop &> &);
    void SingleRegister(loop &);

    void StartLoop();
    void RunLoop();
    void StopLoop();

    void OutputToSmartDashboard();
};

#endif
