#include "PathFinding.h"
#include <stdio.h>

namespace Pathfinding
{
	bool NodeSort(Node* i, Node* j)
	{

	}

	void Node::ConnectTo(Node* other, float cost)
	{
		connections.pushBack(Edge(other, cost));
	}
	
	List<Node*> DijkstrasSearch(Node* startNode, Node* endNode)
	{
		//Validate the input
		if (startNode == nullptr || endNode == nullptr)
		{
			return List<Node*>();
		}

		if (startNode == endNode)
		{
			List<Node*> singleNodePath;
			singleNodePath.pushBack(startNode);
			return singleNodePath;
		}

		//Initialize the starting node
		startNode->gScore = 0;
		startNode->previous = nullptr;

		//Create our temporary lists for storing nodes
		List<Node*> openList;
		List<Node*> closedList;

		//Add the starting node to openList
		openList.pushBack(startNode);


		while (!openList.getLength() > 0)
		{
			//Set the current node to the first node in the openList
			Node* currentNode = openList.first();
			//Remove currentNode from openList
			openList.popFront();
			//Add currentNode to closedList
			closedList.pushBack(currentNode);

			//If the destination node was added to the closed list,
			//the shortest path has been found
			if (currentNode == endNode)
			{
				break;
			}

			//For each Edge e in currentNode's connections
			for (Edge edge : currentNode->connections)
			{
				//If the target node is in the closedList, ignore it
				if (closedList.find(edge.target) != closedList.end())
				{
					continue;
				}
				//If the target node is not in the openList, update it
				if (openList.find(edge.target) == openList.end()) {
					//Calculate the target node's G Score
					edge.target->gScore = currentNode->gScore + edge.cost;
					//Set the target node's previous to currentNode
					edge.target->previous = currentNode;
					auto insertionPos = openList.end();
					int index = 0;
					for (auto i = openList.begin(); i != openList.end(); i++, index++)
					{
						if (edge.target->gScore < (*i)->gScore)
						{
							insertionPos = i;
							break;
						}
					}
					//Insert the node at the appropriate position
					openList.insert(edge.target, index);
				}
				//Otherwise the target node IS in the open list
				else {
					//Compare the new G Score to the old one before updating
					if (currentNode->gScore + edge.cost < edge.target->gScore) {
						//Calculate the target node's G Score
						edge.target->gScore = currentNode->gScore + edge.cost;
						//Set the target node's previous to currentNode
						edge.target->previous = currentNode;
					}
				}
			}
		}
		//Create path in reverse from endNode to startNode
		List<Node*> path;
		Node* currentNode = endNode;

		while (currentNode != nullptr)
		{
			//Add the current node to the beginning of the path
			path.pushFront(currentNode);
			//Go to the previous node
			currentNode = currentNode->previous;
		}

		return path;
	}
	
	void DrawPath(List<Node*>& path, Color lineColor)
	{
		auto currentIter = path.begin();
		auto previousIter = currentIter;
		currentIter;

		for (int i = 1; i < path.getLength(); i++)
			DrawLine((*previousIter)->position.x, (*previousIter)->position.y, (*currentIter)->position.x, (*currentIter)->position.y, lineColor);
	}

	void DrawNode(Node* node, bool selected)
	{
		static char buffer[10];
		sprintf_s(buffer, "%.0f", node->gScore);

		//Draw the circle for the outline
		DrawCircle(node->position.x, node->position.y, 25, YELLOW);
		//Draw the inner circle
		if (selected)
		{
			DrawCircle(node->position.x, node->position.y, 22, BROWN);
		}
		else
		{
			DrawCircle(node->position.x, node->position.y, 22, BLACK);
		}
		//Draw the text
		DrawText(buffer, node->position.x - 10, node->position.y - 10, 15, WHITE);
	}

	void DrawGraph(Node* node, List<Node*>* drawnList)
	{
		DrawNode(node);
		drawnList->pushBack(node);

		//For each Edge in this node's connections
		for (Edge e : node->connections)
		{
			//Draw the Edge
			DrawLine(node->position.x, node->position.y, e.target->position.x, e.target->position.y, WHITE);
			//Draw the cost
			Vector2 costPos = { (node->position.x + e.target->position.x) / 2, (node->position.y + e.target->position.y) / 2 };
			static char buffer[10];
			sprintf_s(buffer, "%.0f", e.cost);
			DrawText(buffer, costPos.x, costPos.y, 15, WHITE);
			//Draw the target node
			if (std::find(drawnList->begin(), drawnList->end(), e.target) == drawnList->end())
			{
				DrawGraph(e.target, drawnList);
			}
		}
	}
}
