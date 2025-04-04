#pragma once
#include "Composite.h"

namespace DecisionTree
{ 
	class Sequence : public Composite
	{
	protected:
		virtual ~Sequence();
	
		virtual void onInitialize();
	
		virtual Status update(Agent* agent, float deltaTime);
	
	protected:
		Behaviours::iterator m_current;
	};
}

