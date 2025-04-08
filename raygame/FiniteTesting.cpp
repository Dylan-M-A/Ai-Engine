#include "raylib.h"
#include <iostream>
#include "pathfinding.h"
#include "NodeMapAI.h"
#include "Agent.h"
#include "GoToPointBehavior.h"
#include "WanderBehavior.h"
#include "FollowBehavior.h"
#include "SelectorBehavior.h"
#include "DistanceCondition.h"
#include "State.h"
#include "Finite State Machine.h"
#include "UtilityAI.h"
#include "Utilities.h"
#include "FiniteTesting.h"

using namespace AIForGames;

void FiniteTesting::start()
{
    Scene::start();

    int screenWidth = 800;
    int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    NodeMap nodeMap;
    nodeMap.m_cellSize = 32;
    std::vector<std::string> asciiMap;

    asciiMap.push_back("000000000000000000000000");
    asciiMap.push_back("011101111111111111111110");
    asciiMap.push_back("011101111111111111111110");
    asciiMap.push_back("011101100000000000000110");
    asciiMap.push_back("011101111111110111111110");
    asciiMap.push_back("011101111111110111000000");
    asciiMap.push_back("011101111101110111111110");
    asciiMap.push_back("011101111101110000011110");
    asciiMap.push_back("011101111101111111111110");
    asciiMap.push_back("011111111100000000001110");
    asciiMap.push_back("011110111101111111111110");
    asciiMap.push_back("011110111101111111111110");
    asciiMap.push_back("011110111101111111111110");
    asciiMap.push_back("011110111111111111111110");
    asciiMap.push_back("000000000000000000000000");

    nodeMap.Initialise(asciiMap);

    Node* start = nodeMap.GetNode(1, 1);
    Node* end = nodeMap.GetNode(10, 2);
    std::vector<Node*> nodeMapPath = DijkstrasSearch(start, end);
    Color lineColor = { 255, 255, 255, 255 };

    AIForGames::Agent agent(&nodeMap, new AIForGames::GotoPointBehavior());
    agent.SetNode(start);

    AIForGames::Agent agent2(&nodeMap, new WanderBehaviour());
    agent2.SetNode(nodeMap.GetRandomNode());

    DistanceCondition* closerThan5 = new DistanceCondition(5.0f * nodeMap.m_cellSize, true);
    DistanceCondition* furtherThan7 = new DistanceCondition(7.0f * nodeMap.m_cellSize, false);

    State* wanderState = new State(new WanderBehaviour());
    State* followState = new State(new FollowBehaviour());
    wanderState->AddTransition(closerThan5, followState);
    followState->AddTransition(furtherThan7, wanderState);

    FiniteStateMachine* fsm = new FiniteStateMachine(wanderState);
    fsm->AddState(wanderState);
    fsm->AddState(followState);

    UtilityAI* utilityAI = new UtilityAI();
    utilityAI->AddBehaviour(new WanderBehaviour());
    utilityAI->AddBehaviour(new FollowBehaviour());

    AIForGames::Agent agent3(&nodeMap, utilityAI);
    agent3.SetNode(nodeMap.GetRandomNode());
    agent3.SetTarget(&agent);
    agent3.SetSpeed(32);

    float time = (float)GetTime();
    float deltaTime;

    while (!WindowShouldClose())
    {
        float fTime = (float)GetTime();
        deltaTime = fTime - time;
        time = fTime;

        if (deltaTime > 0.1f)
            deltaTime = 0.1f;

        BeginDrawing();

        ClearBackground(BLACK);

        bool drawNodeMap = true;

        nodeMap.Draw(true);
        AIForGames::DrawPath(agent.GetPath(), lineColor);

        agent.Update(deltaTime);
        agent.Draw();

        agent2.Update(deltaTime);
        agent2.Draw();

        agent3.Update(deltaTime);
        agent3.Draw();

        EndDrawing();

    }
    CloseWindow();        
}

void FiniteTesting::update(float deltaTime)
{
}
