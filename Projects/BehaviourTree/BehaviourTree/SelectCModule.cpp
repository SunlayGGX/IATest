#include "SelectCModule.h"


using namespace slgLib::IAModule::BehaviourTree;


generalModule::returnState SelectCModule::operator()()
{
    for (size_t iter = 0; iter < m_childs.size(); ++iter)
    {
        if (m_childs[iter]() == generalModule::returnState::Success)
        {
            return generalModule::returnState::Success;
        }
    }

    return generalModule::returnState::Fail;
}