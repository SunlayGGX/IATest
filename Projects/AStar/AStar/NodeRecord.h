#ifndef NODERECORD_H_INCLUDED
#define NODERECORD_H_INCLUDED



namespace IA
{
	class Node;

	class NodeRecord
	{
	private:
		NodeRecord* m_NextRecord;
		NodeRecord* m_PreviousRecord;

		Node& m_RecordedNode;


	public:
		NodeRecord(Node& current) :
			m_RecordedNode{ current },
			m_NextRecord{ nullptr },
			m_PreviousRecord{ nullptr }
		{}

		/* 
		Please ! Use new... 
		And do not pass a nullptr if you don't want the record to be broken in 2
		You have been warned !
		*/
		NodeRecord(Node& current, NodeRecord* previous) :
			m_RecordedNode{ current },
			m_NextRecord{ nullptr },
			m_PreviousRecord{ previous }
		{}


		~NodeRecord()
		{
			NodeRecord* iter = this->m_NextRecord;
			delete iter;
		}


	public:
		Node& node() const noexcept
		{
			return m_RecordedNode;
		}

		NodeRecord* nextRecord() const noexcept
		{
			return m_NextRecord;
		}

		NodeRecord* previousRecord() const noexcept
		{
			return m_PreviousRecord;
		}

		bool isStartRecord() const noexcept
		{
			return m_PreviousRecord == nullptr;
		}

		bool isEndRecord() const noexcept
		{
			return m_NextRecord == nullptr;
		}

		NodeRecord* breakPoint() noexcept
		{
			return this;
		}


	public:
		void record(Node& nodeToRecord)
		{
			m_NextRecord = new NodeRecord(nodeToRecord, this);
		}

		void eraseRecordFrom(NodeRecord* point)
		{
			NodeRecord* iter = this;

			for (; !(iter == point || iter == nullptr); iter = iter->nextRecord());

			delete iter;
		}
	};
}


#endif //!NODERECORD_H_INCLUDED