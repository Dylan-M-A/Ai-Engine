#include "Behaviour.h"

namespace DecisionTree
{
    Status Behaviour::tick(Agent* agent, float deltaTime)
    {
        if (m_eStatus != BH_RUNNING)
        {
            onInitialize();
        }
    
        m_eStatus = update(agent, deltaTime);
    
        if (m_eStatus != BH_RUNNING)
        {
            onTerminate(m_eStatus);
        }
        return m_eStatus;
    }
    void Behaviour::reset()
    {
    }
    void Behaviour::abort()
    {
    }
    bool Behaviour::isTerminated() const
    {
        return false;
    }
    bool Behaviour::isRunning() const
    {
        return false;
    }
    Status Behaviour::getStatus() const
    {
        return Status();
    }
}
