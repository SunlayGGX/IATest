#ifndef COMPOSEDMODULE_H_INCLUDED
#define COMPOSEDMODULE_H_INCLUDED

#include "IModule.h"

namespace slgLib
{
    namespace IAModule
    {
        namespace BehaviourTree
        {
            /*Interface for all composed behaviour tree modules*/
            class ComposedModule : public IModule
            {
            public:
                /*Return the type of module it is. Here, it is always composed*/
                generalModule::moduleType getModuleType() const noexcept { return generalModule::Composed; }
            };
        }
    }
}


#endif //!COMPOSEDMODULE_H_INCLUDED