#pragma once
#include "Scene.h"
#include "Pathfinder/NodeMap.h"
#include "Pathfinder/PathAgent.h"

class SampleScene :
    public Scene
{
public:
    void start() override;
    void update(float deltaTime) override;
    void end() override;

private:
    Pathfinding::NodeMap m_nodeMap;
    Pathfinding::PathAgent* m_pathAgent;
};