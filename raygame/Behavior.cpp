#include "Behaviour.h"

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
