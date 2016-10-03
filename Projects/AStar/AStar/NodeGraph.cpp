#include "NodeGraph.h"

#include <algorithm>


using IA::NodeGraph;



void NodeGraph::computeGraph()
{
	m_NodeArray.push_back(new Node(0, IA::Tile::ZONE));

	size_t size = m_LevelInfo.columnCount * m_LevelInfo.rowCount;

	for (size_t iter = 1; iter < size; ++iter)
	{
		m_NodeArray.push_back(new Node(iter, IA::Tile::ZONE));
		
		if (!nodeAtFirstColumn(*m_NodeArray[iter]))
		{
			m_NodeArray[iter]->linkWith(*m_NodeArray[iter - 1]);
		}
	}
}

void NodeGraph::linkEachNode()
{
	bool atFirst;
	bool atEnd;

	for (size_t iter = m_LevelInfo.columnCount; iter < m_NodeArray.size(); ++iter)
	{
		atFirst = nodeAtFirstColumn(*m_NodeArray[iter]);
		atEnd = nodeAtLastColumn(*m_NodeArray[iter]);

		if (!(atFirst || atEnd))
		{
			m_NodeArray[iter]->linkWith(*m_NodeArray[iter - m_LevelInfo.columnCount]);
			m_NodeArray[iter]->linkWith(*m_NodeArray[iter - m_LevelInfo.columnCount + 1]);
		}
		else if (atFirst)
		{
			if (onAnOddRow(*m_NodeArray[iter]))
			{
				m_NodeArray[iter]->linkWith(*m_NodeArray[iter - m_LevelInfo.columnCount]);
			}

			m_NodeArray[iter]->linkWith(*m_NodeArray[iter - m_LevelInfo.columnCount + 1]);
		}
		else
		{
			if (!onAnOddRow(*m_NodeArray[iter]))
			{
				m_NodeArray[iter]->linkWith(*m_NodeArray[iter - m_LevelInfo.columnCount + 1]);
			}

			m_NodeArray[iter]->linkWith(*m_NodeArray[iter - m_LevelInfo.columnCount]);
		}
	}
}



template<typename ... Args>
void NodeGraph::playWithNodeCaracteristics(Args ... arguments)
{
	size_t numberOfTarget = sizeof...(arguments) / 3;
	size_t iter = 0;

	unsigned int ids[] = { arguments... };

	std::for_each(
		std::begin(ids),
		std::end(ids),
		[this, &numberOfTarget, &iter](unsigned int id) {
			if(iter > numberOfTarget)
			{
				this->nodeArray()[id]->setCaracteristic(IA::Tile::FORBIDDEN);
			}
			else
			{
				this->nodeArray()[id]->setCaracteristic(IA::Tile::TARGET);
				++iter;
			}
		}
	)
}