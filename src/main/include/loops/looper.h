#ifndef LOOPER_H_
#define LOOPER_H_

#include <list>
#include <string>

#include "loops/Loop.h"

class Looper {
   private:
    std::list<Loop &> m_loopList;
    std::string m_looperName;
    bool m_Running = false;

    double m_timesTamp;

   public:
    Looper();
    Looper(std::list<Loop &> &, const char *name = "default");

    Looper(const Looper &) = default;
    Looper(Looper &&) = default;

    ~Looper() = default;

    void MutiRegister(std::list<Loop &> &);
    void SingleRegister(Loop &);

    void StartLoop();
    void RunLoop();
    void StopLoop();

    void OutputToSmartDashboard();
};

#endif
