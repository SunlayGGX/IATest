#include "LoopDModule.h"


using namespace slgLib::IAModule::BehaviourTree;


generalModule::returnState LoopDModule::operator()()
{
    generalModule::returnState state;

    for (size_t iter = 0; iter < m_IterationCount; ++iter)
    {
        state = m_Child();
    }

    return state;
}