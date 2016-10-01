#include "InvertDModule.h"


using namespace slgLib::IAModule::BehaviourTree;


generalModule::returnState InvertDModule::operator()()
{
    generalModule::returnState state = m_Child();

    switch (state)
    {
    case generalModule::returnState::Success:
        return generalModule::returnState::Fail;

    case generalModule::returnState::Fail:
        return generalModule::returnState::Success;

    default:
        return state;
    }
}