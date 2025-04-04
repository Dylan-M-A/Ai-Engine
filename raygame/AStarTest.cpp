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
	asciiMap.push_back("0100011111100001111100111111100");
	asciiMap.push_back("0111110000111111010101100100100");
	asciiMap.push_back("0000100111100000110111011101110");
	asciiMap.push_back("0000111100110001101101110011010");
	asciiMap.push_back("0000010000011001001000100110010");
	asciiMap.push_back("0110010011001111111111111100010");
	asciiMap.push_back("0100011110011000010000010111110");
	asciiMap.push_back("0110110011010001111111010001010");
	asciiMap.push_back("0011100001111111010001111111010");
	asciiMap.push_back("0000111000100010011110000100010");
	asciiMap.push_back("0100101101100111100011000111110");
	asciiMap.push_back("0111110111011100111001111100100");
	asciiMap.push_back("0010010001110110001111000111100");
	asciiMap.push_back("0011111011000100000100010010100");
	asciiMap.push_back("0110001110000100001110011110110");
	asciiMap.push_back("0011111011001111111011110000100");
	asciiMap.push_back("0000100001100000100000011100100");
	asciiMap.push_back("0111111111111111111111110111110");
	asciiMap.push_back("0001001000010000000010010000010");
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
