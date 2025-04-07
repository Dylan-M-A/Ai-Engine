#include "raylib.h"
#include "Agent.h"

int Start()
{
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);
 
    Agent agent(100, 100);

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

    return 0;
}