#include "Pursue.h"

Pursue::Pursue()
{
}

bool Pursue::Update(Default::Agent* agent, float deltaTime)
{
	Vector2 j = Vector2Add(m_destination, m_position);
	Vector2 v = Vector2Subtract(j, agent->GetPosition());

	if (v.x == 0 && v.y == 0)
	{
		// if seeker on top of target, v is 0 so following calculations are not needed
		return true;
	}

	Vector2 desiredVelocity = Vector2Scale(Vector2Normalize(v), agent->GetMaxSpeed());
	Vector2 steeringForce = Vector2Subtract(desiredVelocity, agent->GetVelocity());

	agent->AddForce(steeringForce);

	return true;
}