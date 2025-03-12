#include "SampleScene.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Pathfinder/PathFinding.h"

void SampleScene::start()
{
	Scene::start();

		// create a map of nodes from some grid-based ASCII art
		m_nodeMap.cellSize = 32;
		std::vector<std::string> asciiMap;
		asciiMap.push_back("000000000000");
		asciiMap.push_back("010111011100");
		asciiMap.push_back("010101110110");
		asciiMap.push_back("011100000010");
		asciiMap.push_back("010111111110");
		asciiMap.push_back("010000001000");
		asciiMap.push_back("011111111110");
		asciiMap.push_back("000000000000");
		m_nodeMap.Initialise(asciiMap);

		m_pathAgent = new pathfinding::PathAgent();
		m_pathAgent->SetNode(m_nodeMap.GetNode(1, 1));
		m_pathAgent->speed = 64;
}

void SampleScene::update(float deltaTime)
{
	bool drawNodeMap = true;
	Color lineColor = { 255, 255, 255, 255 };

	m_nodeMap.Draw(true);
	DrawPath(m_pathAgent->path, lineColor);

	// read mouseclicks, left for start node, end for right node
	if (IsMouseButtonPressed(0))
	{
		Vector2 mousePos = GetMousePosition();
		pathfinding::Node* endNode = m_nodeMap.GetClosestNode(mousePos);
		m_pathAgent->GoToNode(endNode);
	}

	m_pathAgent->Update(deltaTime);
	m_pathAgent->Draw();
}

void SampleScene::end()
{

}