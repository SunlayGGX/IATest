#ifndef COMPOSEDMODULE_H_INCLUDED
#define COMPOSEDMODULE_H_INCLUDED

#include "IModule.h"

#include <vector>

namespace slgLib
{
    namespace IAModule
    {
        namespace BehaviourTree
        {
            /*Interface for all composed behaviour tree modules*/
            class ComposedModule : public IModule
            {
            protected:
                std::vector<IModule&> m_childs;


            public:
                /*Return the type of module it is. Here, it is always composed*/
                generalModule::moduleType getModuleType() const noexcept { return generalModule::Composed; }
            };
        }
    }
}


#endif //!COMPOSEDMODULE_H_INCLUDED