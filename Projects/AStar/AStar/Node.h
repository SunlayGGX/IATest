#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED


#include <vector>

namespace IA
{
	namespace Tile
	{
		enum Caracteristics
		{
			FORBIDDEN,
			TARGET,
			ZONE
		};
	}

	class Node
	{
	public:
		enum
		{
			NOFOUND = 0xFFFFFFFF
		};

	private:
		unsigned int m_CurrentId;
		std::vector<Node*> m_Link;

		Tile::Caracteristics m_Caracteristics;


	public:
		Node(unsigned int current, Tile::Caracteristics caracteristic) noexcept :
			m_CurrentId{ current },
			m_Link{},
			m_Caracteristics{ caracteristic }
		{}


	public:
		size_t connectionCount() const noexcept
		{
			return m_Link.size();
		}

		std::vector<Node*> neighbourNodesArray() const noexcept
		{
			return m_Link;
		}

		Node* getNeighbourNode(size_t connectionIndex) noexcept
		{
			return (*this)[connectionIndex];
		}

		Node* getNeighbourNode(size_t connectionIndex) const noexcept
		{
			return (*this)[connectionIndex];
		}

		Tile::Caracteristics caracteristic() const noexcept
		{
			return m_Caracteristics;
		}

		void setCaracteristic(Tile::Caracteristics newCaracteristic) noexcept
		{
			if (newCaracteristic == Tile::Caracteristics::FORBIDDEN)
			{
				detachAll();
			}

			m_Caracteristics = newCaracteristic;
		}

		unsigned int getId() const noexcept
		{
			return m_CurrentId;
		}


	public:
		void linkWith(Node& from) noexcept
		{
			if (!(this->m_Caracteristics == Tile::Caracteristics::FORBIDDEN || isLinkedWith(from)))
			{
				this->m_Link.push_back(&from);
				from.m_Link.push_back(this);
			}
		}

		void unlinkWith(Node& from) noexcept
		{
			size_t index = from.find(*this);

			if (index != NOFOUND)
			{
				from.m_Link.erase(from.m_Link.begin() + index);

				index = this->find(from);

				if (index != NOFOUND)
				{
					m_Link.erase(m_Link.begin() + index);
				}
			}
		}

		void detachAll() noexcept
		{
			size_t index;
			size_t intermediary;
			
			while (m_Link.size() != 0)
			{
				intermediary = m_Link.size() - 1;
				index = m_Link[intermediary]->find(*this);

				if (index != NOFOUND)
				{
					m_Link[intermediary]->m_Link.erase(m_Link[intermediary]->m_Link.begin() + index);
				}

				m_Link.pop_back();
			}
		}

		bool isLinkedWith(Node& from) const noexcept
		{
			for (size_t iter = 0; iter < m_Link.size(); ++iter)
			{
				if (m_Link[iter] == &from)
				{
					return true;
				}
			}

			return false;
		}

		size_t find(Node& from) noexcept
		{
			for (size_t iter = 0; iter < m_Link.size(); ++iter)
			{
				if (m_Link[iter] == &from)
				{
					return iter;
				}
			}

			return NOFOUND;
		}


	public:
		Node* operator[](size_t connectionIndex) noexcept
		{
			return m_Link[connectionIndex];
		}

		Node* operator[](size_t connectionIndex) const noexcept
		{
			return m_Link[connectionIndex];
		}
	};
}


#endif //!NODE_H_INCLUDED