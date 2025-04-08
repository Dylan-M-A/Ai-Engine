#include "raylib.h"
#include "Agent.h"
#include "BehaviorTree.h"

void BehaviorTree::start()
{
    Scene::start();

    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    Default::Agent agent(100, 100);

    float deltaTime = 0;

    while (!WindowShouldClose())
    {
        deltaTime = GetFrameTime();

        agent.Update(deltaTime);

        BeginDrawing();

        ClearBackground(GRAY);

        agent.Draw();

        EndDrawing();
    }

    CloseWindow();
}

void BehaviorTree::update(float deltaTime)
{
}
