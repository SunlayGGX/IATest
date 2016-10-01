#include "ComposedModule.h"

#include <algorithm>

using namespace slgLib::IAModule::BehaviourTree;


void ComposedModule::disconnect(IModule& otherModule)
{
    for (size_t iter = 0; iter < m_childs.size(); ++iter)
    {
        if (&m_childs[iter] == &otherModule)
        {
            disconnect(iter);
            return;
        }
    }
}