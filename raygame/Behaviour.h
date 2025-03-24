#pragma once
#include "Agent.h"

enum Status
{
	BH_INVALID,
	BH_SUCCESS,
	BH_FAILURE,
	BH_RUNNING,
	BH_ABORTED
};


class Behaviour
{
public:

	// empty constructors and destructors for base class
	Behaviour() {}
	virtual ~Behaviour() {}

	// pure virtual function for executing the behaviour
	virtual bool Update(Agent* agent, float deltaTime) = 0;
	virtual Status update(Agent* agent, float deltaTime) = 0;
	Status tick(Agent* agent, float deltaTime);
	virtual void onInitialize() {}
	virtual void onTerminate(Status status) {}
private:
	Status m_eStatus;
};
