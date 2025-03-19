#pragma once
#include "Behaviour.h"

class Component;

class  Evade
{
public:
	Evade();
	virtual ~Evade() {};

	virtual bool Update(Agent* agent, float deltaTime);
	void SetDestination(Vector2 destination) { m_destination = destination; }

private:
	Vector2 m_destination;
	float m_fleeRadius = 100;
	Vector2 m_position = { 0, 0 };
	Vector2 m_velocity = { 0, 0 };
};