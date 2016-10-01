#include "SuccessDModule.h"


using namespace slgLib::IAModule::BehaviourTree;


generalModule::returnState SuccessDModule::operator()()
{
    m_Child();

    return generalModule::returnState::Success;
}