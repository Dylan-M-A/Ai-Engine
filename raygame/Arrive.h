#pragma once
#include "Behaviour.h"
class Component;

class Arrive
{
public:
	Arrive();
	virtual ~Arrive() {};

	virtual bool Update(Agent* agent, float deltaTime);
	void SetDestination(Vector2 destination) { m_destination = destination; }

private:
	Vector2 m_destination;
	float m_slowingRadius = 100;
};

