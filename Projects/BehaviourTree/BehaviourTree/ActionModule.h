#ifndef ACTIONMODULE_H_INCLUDED
#define ACTIONMODULE_H_INCLUDED

#include "IModule.h"


namespace slgLib
{
    namespace IAModule
    {
        namespace BehaviourTree
        {
            /*Interface for all Action behavior tree modules*/
            class ActionModule : public IModule
            {
            public:

                IModule& child(size_t index);

                virtual size_t connectionCount() const noexcept
                {
                    return 0;
                }

                virtual void connect(IModule& otherModule) {}

                virtual void disconnect(IModule& otherModule) {}
                virtual void disconnect(size_t index) {}

                generalModule::moduleType getModuleType() const noexcept
                {
                    return generalModule::moduleType::Action;
                }

                virtual generalModule::returnState operator()() = 0;
            };
        }
    }
}


#endif //!ACTIONMODULE_H_INCLUDED