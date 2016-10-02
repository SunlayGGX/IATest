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
                std::vector<IModule*> m_childs;


            public:
                /*return its child at the specified index*/
                virtual IModule& child(size_t index) noexcept { return *m_childs[index]; }

                /*Return the number of child this module is connected to*/
                virtual size_t connectionCount() const noexcept { return m_childs.size(); }

                /*Return the type of module it is. Here, it is always composed*/
                generalModule::moduleType getModuleType() const noexcept { return generalModule::Composed; }

                /*Connect to a module child at the end of the child list*/
                virtual void connect(IModule& otherModule) { m_childs.push_back(&otherModule); }

                /*Disconnect from the specified child*/
                virtual void disconnect(IModule& otherModule);

                /*Disconnect from the indexed specified child*/
                virtual void disconnect(size_t index) { m_childs.erase(m_childs.begin() + index); }
            };
        }
    }
}


#endif //!COMPOSEDMODULE_H_INCLUDED