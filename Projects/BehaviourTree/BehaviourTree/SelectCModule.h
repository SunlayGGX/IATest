#ifndef SELECTCMODULE_H_INCLUDED
#define SELECTCMODULE_H_INCLUDED


#include "ComposedModule.h"


namespace slgLib
{
    namespace IAModule
    {
        namespace BehaviourTree
        {
            /*Selection module that executes each of its childs until one succeed.
            Return a fail status if all failed. Success if not.*/
            class SelectCModule : public ComposedModule
            {
            public:
                virtual generalModule::returnState operator()();
            };
        }
    }
}


#endif //!SELECTCMODULE_H_INCLUDED