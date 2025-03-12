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
    pathfinding::NodeMap m_nodeMap;
    pathfinding::PathAgent* m_pathAgent;
};