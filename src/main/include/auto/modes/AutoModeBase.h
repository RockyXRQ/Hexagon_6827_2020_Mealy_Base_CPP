#ifndef AUTO_MODE_BASE
#define AUTO_MODE_BASE

class AutoModeBase {
   protected:
    int m_runStage = 1;

   public:
    virtual void Start() = 0;
    virtual void Resume() = 0;
    virtual void Stop() = 0;
};

#endif