#include "raylib.h"
#include "Agent.h"
#include "Arrive.h"
#include "Evade.h"
#include "Flee.h"
#include "Pursue.h"
#include "Seek.h"
#include "Wander.h"
#include "Finite State Machine.h"
#include "SteeringTest.h"

class Scene;

void SteeringTest::start()
{
	Scene::start();

	int screenWidth = 800;
	int screenHeight = 450;

	SetWindowSize(screenWidth, screenHeight);

	Vector2 target = { (float)(screenWidth >> 1), (float)(screenHeight >> 1) };

	Default::Agent* arrive = new Default::Agent();
	Arrive* arriveBehavior = new Arrive();
	arriveBehavior->SetDestination(target);
	arrive->AddBehaviour(arriveBehavior);

	Default::Agent* evade = new Default::Agent();
	Evade* evadeBehavior = new Evade();
	evadeBehavior->SetDestination(target);
	evade->AddBehaviour(evadeBehavior);
	
	Default::Agent* flee = new Default::Agent();
	flee->SetPosition({ (float)(screenWidth >> 1), (float)(screenHeight >> 1) });
	Flee* fleeBehavior = new Flee();
	fleeBehavior->SetDestination(target);
	flee->AddBehaviour(fleeBehavior);
	
	Default::Agent* pursue = new Default::Agent();
	pursue->SetPosition({ (float)(screenWidth >> 1), (float)(screenHeight >> 1) });
	Pursue* pursueBehavior = new Pursue();
	pursueBehavior->SetDestination(target);
	pursue->AddBehaviour(pursueBehavior);
	
	Default::Agent* seek = new Default::Agent();
	Seek* seekBehavior = new Seek();
	seekBehavior->SetDestination(target);
	seek->AddBehaviour(seekBehavior);
	
	Default::Agent* wander = new Default::Agent();
	wander->SetPosition({ (float)(screenWidth >> 1), (float)(screenHeight >> 1) });
	wander->SetMaxSpeed(50);
	Wander* wanderBehavior = new Wander();
	wander->AddBehaviour(wanderBehavior);

	float deltaTime = 0;

	while (!WindowShouldClose())
	{
		deltaTime = GetFrameTime();

		if (arrive)
		{
			if (IsMouseButtonDown(0) == true)
			{
				target = GetMousePosition();
				arriveBehavior->SetDestination(target);
			}
			arrive->Update(deltaTime);
		}

		if (evade)
		{
			if (IsMouseButtonDown(0) == true)
			{
				target = GetMousePosition();
				evadeBehavior->SetDestination(target);
			}

			evade->Update(deltaTime);
		}

		if (flee)
		{
			if (IsMouseButtonDown(0) == true)
			{
				target = GetMousePosition();
				fleeBehavior->SetDestination(target);
			}

			flee->Update(deltaTime);
		}

		if (pursue)
		{
			if (IsMouseButtonDown(0) == true)
			{
				target = GetMousePosition();
				pursueBehavior->SetDestination(target);
			}

			pursue->Update(deltaTime);
		}

		if (seek)
		{
			if (IsMouseButtonDown(0) == true)
			{
				target = GetMousePosition();
				seekBehavior->SetDestination(target);
			}

			seek->Update(deltaTime);
		}

		if (wander)
		{
			wander->Update(deltaTime);

			Vector2 pos = wander->GetPosition();
			if (pos.y < 0)
				pos.y = screenHeight;
			if (pos.y > screenHeight)
				pos.y = 0;
			if (pos.x < 0)
				pos.x = screenWidth;
			if (pos.x > screenWidth)
				pos.x = 0;
			wander->SetPosition(pos);

		}

		BeginDrawing();

		ClearBackground(RAYWHITE);
		DrawText("Click anywhere to set a new target position", 20, 20, 12, RED);
		DrawLine(target.x - 5, target.y, target.x + 5, target.y, BLUE);
		DrawLine(target.x, target.y - 5, target.x, target.y + 5, BLUE);

		arrive->Draw();

		EndDrawing();
	}
	delete arriveBehavior;
	delete arrive;

	CloseWindow();
}

void SteeringTest::update(float deltaTime)
{
}
