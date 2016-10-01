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
                virtual IModule& child(size_t index) const noexcept { return m_childs[index]; }

                /*Return the number of child this module is connected to*/
                virtual size_t connectionCount() const noexcept { return m_childs.size(); }

                /*Return the type of module it is. Here, it is always composed*/
                generalModule::moduleType getModuleType() const noexcept { return generalModule::Composed; }
            };
        }
    }
}


#endif //!COMPOSEDMODULE_H_INCLUDED