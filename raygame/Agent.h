#pragma once
#include "raymath.h"
#include <vector>
#include "PathAgentAI.h"


namespace Default
{
	class Behaviour;

	class Agent
	{
	public:
		Agent();
		Agent(int, int);
		virtual ~Agent();
	
		// Update the agent and its behaviours
		virtual void Update(float deltaTime);
	
		// Draw the agent
		virtual void Draw();
	
		// Add a behaviour to the agent
		void AddBehaviour(Behaviour* behaviour);
	
		// Movement functions
		void SetPosition(Vector2 position) { m_position = position; }
		Vector2 GetPosition() { return m_position; }
	
		void SetVelocity(Vector2 velocity) { m_velocity = velocity; }
		Vector2 GetVelocity() { return m_velocity; }
	
		void SetMaxSpeed(float speed) { m_maxSpeed = speed; }
		float GetMaxSpeed() { return m_maxSpeed; }
	
		void AddForce(Vector2 force) { m_force = Vector2Add(force, m_force); }
	
	private:
		Vector2 Truncate(Vector2 v, float max);
	
	protected:
		std::vector<Behaviour*> m_behaviourList;
	
		Vector2 m_position = { 0, 0 };
		Vector2 m_velocity = { 0, 0 };
		float m_maxSpeed = 100;
	
		//Keep between 0 and 1, 0 is max friction, 1 is no friction
		float m_frictionModifier = 0.99;
	
		Vector2 m_force = { 0, 0 };
	};
}

namespace DecisionTree
{
	class Behaviour;
	class Agent
	{
	public:
		Agent(float x, float y);
		virtual ~Agent();

		// Update the agent and its behaviours
		virtual void Update(float deltaTime);

		// Draw the agent
		virtual void Draw();

		void SetAttack(bool state) { m_bAttack = state; }

	protected:
		Behaviour* m_pBehaviourTree;
		bool m_bAttack;

	public:
		float m_maxSpeed;

		Vector2 m_acceleration;
		Vector2 m_velocity;
		Vector2 m_position;
	};
}

namespace AIForGames
{
	class NodeMap;
	class Behaviour;
	class Agent
	{
	public:
		Agent();
		Agent(NodeMap* _nodeMap, Behaviour* _behaviour);
		~Agent();

		void Update(float deltaTime);
		void Draw();

		void GoTo(Vector2 point);
		void GoTo(Node* node);

		std::vector<Node*>& GetPath() { return m_pathAgent.GetPath(); }

		void SetNode(Node* node);

		bool PathComplete();

		NodeMap* GetNodeMap() { return m_nodeMap; }
		Vector2 GetPosition() { return m_pathAgent.GetPosition(); }

		void SetSpeed(float speed) { m_pathAgent.SetSpeed(speed); }

		void SetTarget(Agent* target) { m_target = target; }
		Agent* GetTarget() { return m_target; }
		void SetColor(Color col) { m_color = col; }

		void Reset() { m_pathAgent.GetPath().clear(); }

	private:
		PathAgent m_pathAgent;
		Behaviour* m_current;
		NodeMap* m_nodeMap;

		Agent* m_target;

		Color m_color;
	};
}