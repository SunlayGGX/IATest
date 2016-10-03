#ifndef ASTAR_H_INCLUDED
#define ASTAR_H_INCLUDED


#include "NodeGraph.h"


namespace IA
{
	class NodeRecord;

	class AStar
	{
	public:
		std::vector<Node*> pathFinding(unsigned int start, unsigned int goal, const NodeGraph& graph) const noexcept;


	private:
		Node* searchBetweenNeighbour(Node& current, Node& goal, const NodeGraph& graph) const noexcept;

		NodeRecord* makePathRecord(unsigned int start, unsigned int goal, const NodeGraph& graph) const noexcept;

		std::vector<Node*> nodeRecordToNodeVector(const NodeRecord& recordedPath) const;
	};
}


#endif //!ASTAR_H_INCLUDED