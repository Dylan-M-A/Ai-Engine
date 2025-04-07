#pragma once
#include "Behaviour.h"

class Component;

class Pursue : public Behaviour
{
public:
	Pursue();
	virtual ~Pursue() {};

	virtual bool Update(Agent* agent, float deltaTime) override;
	void SetDestination(Vector2 destination) { m_destination = destination; }

private:
	Vector2 m_destination;
	Vector2 m_position = { 0, 0 };
	Vector2 m_velocity = { 0, 0 };
};