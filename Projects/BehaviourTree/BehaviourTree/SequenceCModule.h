#ifndef SEQUENCECMODULE_H_INCLUDED
#define SEQUENCECMODULE_H_INCLUDED

#include "ComposedModule.h"


namespace slgLib
{
    namespace IAModule
    {
        namespace BehaviourTree
        {
            /*Sequence module that execute each of its childs until one fails.
            Return a fail status if one has failed. Success if not.*/
            class SequenceCModule : public ComposedModule
            {
            public:
                virtual generalModule::returnState operator()();
            };
        }
    }
}


#endif //!SEQUENCECMODULE_H_INCLUDED
