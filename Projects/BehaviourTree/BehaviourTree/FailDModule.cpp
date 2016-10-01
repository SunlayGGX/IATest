#include "FailDModule.h"


using namespace slgLib::IAModule::BehaviourTree;


generalModule::returnState FailDModule::operator()()
{
    m_Child();

    return generalModule::returnState::Fail;
}