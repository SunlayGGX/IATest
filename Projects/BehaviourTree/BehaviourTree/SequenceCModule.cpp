#include "SequenceCModule.h"


using namespace slgLib::IAModule::BehaviourTree;

generalModule::returnState SequenceCModule::operator()()
{
    for (size_t iter = 0; iter < m_childs.size(); ++iter)
    {
        if (m_childs[iter]() == generalModule::returnState::Fail)
        {
            return generalModule::returnState::Fail;
        }
    }

    return generalModule::returnState::Success;
}