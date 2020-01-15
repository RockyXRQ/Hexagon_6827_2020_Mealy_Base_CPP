#ifndef SUPERSTRUCTURE_STATE_
#define SUPERSTRUCTURE_STATE_

class SuperStructureSate {
   private:
    friend class JetsonNanoCamera;

    double m_targetX = 0;
    double m_targetY = 0;

   public:
    SuperStructureSate();
    double GetTargetX();
    double GetTargetY();
};

#endif