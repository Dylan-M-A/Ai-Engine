#include "AStarTest.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Pathfinder/PathFinding.h"
#include <iostream>

void AStarTest::start()
{
	Scene::start();

	// create a map of nodes from some grid-based ASCII art
	m_nodeMap.cellSize = 32;
	std::vector<std::string> asciiMap;
	asciiMap.push_back("0000000000000000000000000000000");
	asciiMap.push_back("0101110111011111111111111111110");
	asciiMap.push_back("0101011101111111111111111111110");
	asciiMap.push_back("0111000000111111111111111111110");
	asciiMap.push_back("0101111111111111111111111111110");
	asciiMap.push_back("0100000010011111111111111111110");
	asciiMap.push_back("0111111111111111111111111111110");
	asciiMap.push_back("0111111111111111111111111111110");
	asciiMap.push_back("0111111111111111111111111111110");
	asciiMap.push_back("0111111111111111111111111111110");
	asciiMap.push_back("0111111111111111111111111111110");
	asciiMap.push_back("0111111111111111111111111111110");
	asciiMap.push_back("0111111111111111111111111111110");
	asciiMap.push_back("0111111111111111111111111111110");
	asciiMap.push_back("0111111111111111111111111111110");
	asciiMap.push_back("0111111111111111111111111111110");
	asciiMap.push_back("0111111111111111111111111111110");
	asciiMap.push_back("0111111111111111111111111111110");
	asciiMap.push_back("0111111111111111111111111111110");
	asciiMap.push_back("0111111111111111111111111111110");
	asciiMap.push_back("0111111111111111111111111111110");
	asciiMap.push_back("0111111111111111111111111111110");
	asciiMap.push_back("0111111111111111111111111111110");
	asciiMap.push_back("0111111111111111111111111111110");
	asciiMap.push_back("0000000000000000000000000000000");
	m_nodeMap.Initialise(asciiMap);

	m_pathAgent = new Pathfinding::PathAgent();
	m_pathAgent->SetNode(m_nodeMap.GetNode(1, 1));
	m_pathAgent->speed = 64;
}

void AStarTest::update(float deltaTime)
{
	bool drawNodeMap = true;
	Color lineColor = { 255, 255, 255, 255 };

	m_nodeMap.Draw(true);
	DrawPath(m_pathAgent->path, lineColor);

	// read mouseclicks, left for start node, end for right node
	if (IsMouseButtonPressed(0))
	{
		Vector2 mousePos = GetMousePosition();
		Pathfinding::Node* endNode = m_nodeMap.GetClosestNode(mousePos);
		m_pathAgent->GoToNode(endNode);
		std::cout << deltaTime << std::endl;
	}

	m_pathAgent->Update(deltaTime);
	m_pathAgent->Draw();
}
