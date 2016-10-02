#include "ActionModule.h"

#include <stdexcept>

using namespace slgLib::IAModule::BehaviourTree;


IModule& ActionModule::child(size_t index)
{
    throw std::runtime_error{ "Aie ! No child from an action module !" };
}