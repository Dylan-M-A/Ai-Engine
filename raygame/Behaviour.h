#pragma once
#include "Agent.h"

namespace Default
{
	class Behaviour
	{
	public:

		// empty constructors and destructors for base class
		Behaviour() {}
		virtual ~Behaviour() {}

		// pure virtual function for executing the behaviour
		virtual bool Update(Agent* agent, float deltaTime) = 0;
	};
}

namespace AIForGames
{
	class Behaviour
	{
	public:
		virtual void Enter(Agent* agent) {}
		virtual void Update(Agent* agent, float deltaTime) = 0;
		virtual void Exit(Agent* agent) {}

		// used by UtilityAI to determine which behaviour to do
		virtual float Evaluate(Agent* agent) { return 0.0f; }
	};
}

namespace DecisionTree
{
	enum Status
	{
		BH_INVALID,
		BH_SUCCESS,
		BH_FAILURE,
		BH_RUNNING,
		BH_ABORTED
	};

	class Agent;

	// Base class for actions, conditions and composites
	class Behaviour
	{
	public:
		Behaviour() : m_eStatus(BH_INVALID) {}
		virtual ~Behaviour() {}

	public:
		virtual Status update(Agent* agent, float deltaTime) = 0;
		virtual void onInitialize() {}
		virtual void onTerminate(Status status) {}

		Status tick(Agent* agent, float deltaTime);
		void reset();
		void abort();

		bool isTerminated() const;
		bool isRunning() const;

		Status getStatus() const;

	private:
		Status m_eStatus;
	};


}
