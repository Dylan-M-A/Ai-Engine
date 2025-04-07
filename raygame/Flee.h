#pragma once
#include "Behaviour.h"
class Component;

class Flee : public Behaviour
{
public:
	Flee();
	virtual ~Flee() {};

	virtual bool Update(Agent* agent, float deltaTime) override;
	void SetDestination(Vector2 destination) { m_destination = destination; }

private:
	Vector2 m_destination;
	float m_fleeRadius = 100;
};
