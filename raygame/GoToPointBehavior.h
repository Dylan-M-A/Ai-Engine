#pragma once
#include "Behaviour.h"

namespace AIForGames
{
    class GotoPointBehavior : public AIForGames::Behaviour
    {
    public:
        virtual void Update(Agent* agent, float deltaTime);
    };
}
