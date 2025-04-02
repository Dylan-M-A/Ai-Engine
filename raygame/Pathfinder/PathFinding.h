#pragma once
#include "raylib.h"
#include <vector>
#include <algorithm>

namespace Pathfinding {
	struct Node;

	struct Edge {
		Edge() { target = nullptr; cost = 0; }
		Edge(Node* _target, float _cost) : target(_target), cost(_cost) {}

		Node* target;
		float cost;
	};

	struct Node {

		Node() {}
		Node(float x, float y) { position.x = x; position.y = y; gScore = 0; previous = nullptr; }

		Vector2 position;

		float gScore;
		float heuristic;
		float finalScore;
		Node* previous;

		std::vector<Edge> connections;

		void ConnectTo(Node* other, float cost);

		// Function to calculate distance
		float distance(int x1, int y1, int x2, int y2) 
		{
			return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		}

	};
	std::vector<Node*> DijkstrasSearch(Node* startNode, Node* endNode);
	void DrawPath(std::vector<Node*>& path, Color lineColor);
	void DrawNode(Node* node, bool selected = false);
	void DrawGraph(Node* node, std::vector<Node*>* drawnList);

	std::vector<Node*> AStarSearch(Node* startNode, Node* endNode);


}