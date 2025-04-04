#pragma once
#include "Behaviour.h"
#include <vector>

namespace DecisionTree
{
	class Composite : public Behaviour
	{
	public:
		Composite* add(Behaviour* child);
		void remove(Behaviour* child);
		void clear();
	
	protected:
		typedef std::vector<Behaviour*> Behaviours;
		Behaviours m_children;
	};
}

