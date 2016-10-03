#ifndef NODEGRAPH_H_INCLUDED
#define NODEGRAPH_H_INCLUDED


#include "Node.h"


namespace IA
{
	struct LevelInfo
	{
		size_t columnCount;
		size_t rowCount;
		unsigned int turnCount;

		LevelInfo(size_t columnCount, size_t rowCount, unsigned int turnCount) :
			columnCount{ columnCount },
			rowCount{ rowCount },
			turnCount{ turnCount }
		{}
	};


	class NodeGraph
	{
	private:
		std::vector<Node*> m_NodeArray;
		std::vector<Node*> m_TargetNodeArray;
		
		LevelInfo m_LevelInfo;


	public:
		NodeGraph(const LevelInfo& levelInfo) :
			m_LevelInfo{ levelInfo },
			m_NodeArray{ levelInfo.columnCount * levelInfo.rowCount },
			m_TargetNodeArray{}
		{
			computeGraph();
			linkEachNode();
		}


	public:
		std::vector<Node*> nodeArray() const noexcept
		{
			return m_NodeArray;
		}

		std::vector<Node*> targetNodeArray() const noexcept
		{
			return m_TargetNodeArray;
		}

		Node* targetNode(size_t index) const noexcept
		{
			return m_TargetNodeArray[index];
		}

		size_t targetCount() const noexcept
		{
			return m_TargetNodeArray.size();
		}

		size_t nodeCount() const noexcept
		{
			return m_NodeArray.size();
		}

		LevelInfo levelInfo() const noexcept
		{
			return m_LevelInfo;
		}


	public:
		bool nodeAtLastColumn(const Node& node) const noexcept
		{
			return columnNumberFor(node) == (m_LevelInfo.columnCount - 1);
		}

		bool nodeAtFirstColumn(const Node& node) const noexcept
		{
			return columnNumberFor(node) == 0;
		}

		bool nodeAtLastRow(const Node& node) const noexcept
		{
			return rowNumberFor(node) == (m_LevelInfo.rowCount - 1);
		}

		bool nodeAtFirstRow(const Node& node) const noexcept
		{
			return rowNumberFor(node) == 0;
		}

		unsigned int rowNumberFor(const Node& node) const noexcept
		{
			return node.getId() / m_LevelInfo.columnCount;
		}

		unsigned int columnNumberFor(const Node& node) const noexcept
		{
			return node.getId() % m_LevelInfo.columnCount;
		}

		bool onAnOddRow(const Node& node) const noexcept
		{
			return static_cast<bool>(rowNumberFor(node) % 2);
		}

		unsigned int manhattanDistanceTo(const Node& current, const Node& destination) const noexcept
		{
			return absoluteMinus(columnNumberFor(destination), columnNumberFor(current)) +
				absoluteMinus(rowNumberFor(destination), rowNumberFor(current));
		}


	private:
		unsigned int absoluteMinus(unsigned int value1, unsigned int value2) const noexcept
		{
			return (value1 < value2) ? value2 - value1 : value1 - value2;
		}



	public:
		template<typename ... Args>
		void playWithNodeCaracteristics(Args ... arguments);


	private:
		void computeGraph();

		void linkEachNode();
	};
}


#endif //!NODEGRAPH_H_INCLUDED