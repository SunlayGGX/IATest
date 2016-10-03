#include "AStar.h"

#include "NodeRecord.h"


#include <algorithm>


using namespace IA;



std::vector<Node*> AStar::pathFinding(unsigned int start, unsigned int goal, const NodeGraph& graph) const noexcept
{
	NodeRecord* recordedPath = makePathRecord(start, goal, graph);

	std::vector<Node*> path = nodeRecordToNodeVector(*recordedPath);

	delete recordedPath;

	return path;
}





Node* AStar::searchBetweenNeighbour(Node& current, Node& goal, const NodeGraph& graph) const noexcept
{
	size_t iter = 0;

	unsigned int minDistanceOrCost = 0xFFFFFFFF;
	unsigned int saveDistanceIntermediary;

	Node* nearest;

	std::for_each(
		current.neighbourNodesArray().begin(),
		current.neighbourNodesArray().end(),
		
		[	
			&graph, 
			&iter, 
			&goal, 
			&minDistanceOrCost, 
			&saveDistanceIntermediary, 
			&nearest
		] (Node* neighboor) {

			saveDistanceIntermediary = graph.manhattanDistanceTo(*neighboor, goal);
			if (minDistanceOrCost > saveDistanceIntermediary)
			{
				minDistanceOrCost = saveDistanceIntermediary;
				nearest = neighboor;
			}
		}
	);

	return nearest;
}

NodeRecord* AStar::makePathRecord(unsigned int start, unsigned int goal, const NodeGraph & graph) const noexcept
{
	Node current(start, Tile::Caracteristics::ZONE);
	Node end(goal, Tile::Caracteristics::TARGET);

	NodeRecord* pathRecord = new NodeRecord(current);

	unsigned int turn = 0;


	//Can evaluate the opened and closed list if we leaving this loop for example (to find another path)
	while (!(current.getId() == end.getId() || turn == graph.levelInfo().turnCount))
	{
		current = *searchBetweenNeighbour(current, end, graph);

		pathRecord->record(current);
	}

	return pathRecord;
}


std::vector<Node*> IA::AStar::nodeRecordToNodeVector(const NodeRecord& recordedPath) const
{
	std::vector<Node*> path;

	for (NodeRecord* iter = &const_cast<NodeRecord&>(recordedPath); iter != nullptr; iter = iter->nextRecord())
	{
		path.push_back(&iter->node());
	}

	return path;
}
