#pragma once
#include "Behaviour.h"
class Component;

class Seek : public Default::Behaviour
{
public:
	Seek();
	virtual ~Seek() {};

	virtual bool Update(Default::Agent* agent, float deltaTime) override;
	void SetDestination(Vector2 destination) { m_destination = destination; }

private:
	Vector2 m_destination;
};