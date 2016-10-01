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