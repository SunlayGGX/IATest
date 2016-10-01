#ifndef FAILDMODULE_H_INCLUDED
#define FAILDMODULE_H_INCLUDED


#include "DecorationModule.h"


namespace slgLib
{
    namespace IAModule
    {
        namespace BehaviourTree
        {
            /*Module that execute its child and always return fail, whatever the result is*/
            class FailDModule : public DecorationModule
            {
                generalModule::returnState operator()();
            };
        }
    }
}


#endif //!FAILDMODULE_H_INCLUDED
