#pragma once
#include "raylib.h"
#include "pathfinding.h"
#include <vector>

namespace Pathfinding
{
	class PathAgent
	{
	public:
		Vector2 position;

		std::vector<Node*> path;
		int currentIndex;
		Node* currentNode;

		float speed;

		void SetNode(Node* node);
		void Update(float deltaTime);
		void GoToNode(Node* node);

		void Draw();
	};
}
