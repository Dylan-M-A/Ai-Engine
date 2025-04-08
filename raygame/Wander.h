#pragma once
#include "Behaviour.h"
class Component;

class Wander : public Default::Behaviour
{
public:
	Wander();
	virtual ~Wander() {};

	virtual bool Update(Default::Agent* agent, float deltaTime) override;

	void Draw(Default::Agent* agent);	// for debug only

private:
	Vector2 SetAngle(Vector2 vector, float value);

private:
	float m_circleDistance = 60;
	float m_circleRadius = 50;
	float m_wanderAngle = 0;

	const float m_angleChange = 50;

	/// DEBUG ONLY
private:
	Vector2 debug_cirleCenter;
	Vector2 debug_displacement;
	/// DEBUG ONLY
};

