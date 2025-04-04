#include "raylib.h"
#include "Agent.h"
#include "Arrive.h"
#include "Evade.h"
#include "Flee.h"
#include "Pursue.h"
#include "Seek.h"
#include "Wander.h"
#include "Finite State Machine.h"

class Scene;

void Start()
{
	int screenWidth = 800;
	int screenHeight = 450;

	SetWindowSize(screenWidth, screenHeight);


	Vector2 target = { (float)(screenWidth >> 1), (float)(screenHeight >> 1) };

	Agent* arrive = new Agent();
	Arrive* arriveBehavior = new Arrive();
	arriveBehavior->SetDestination(target);
	arrive->AddBehaviour(arriveBehavior);

	//Agent* evade = new Agent();
	//Evade* evadeBehavior = new Evade();
	//evadeBehavior->SetDestination(target);
	//evade->AddBehaviour(evadeBehavior);
	//
	//Agent* flee = new Agent();
	//Flee* fleeBehavior = new Flee();
	//fleeBehavior->SetDestination(target);
	//flee->AddBehaviour(fleeBehavior);
	//
	//Agent* pursue = new Agent();
	//Pursue* pursueBehavior = new Pursue();
	//pursueBehavior->SetDestination(target);
	//pursue->AddBehaviour(pursueBehavior);
	//
	//Agent* seek = new Agent();
	//Seek* seekBehavior = new Seek();
	//seekBehavior->SetDestination(target);
	//seek->AddBehaviour(seekBehavior);
	//
	//Agent* wander = new Agent();
	//wander->SetPosition({ (float)(screenWidth >> 1), (float)(screenHeight >> 1) });
	//wander->SetMaxSpeed(50);
	//Wander* wanderBehavior = new Wander();
	//wander->AddBehaviour(wanderBehavior);
	
}