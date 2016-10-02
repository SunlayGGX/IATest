#ifndef SUCCESSDMODULE_H_INCLUDED
#define SUCCESSDMODULE_H_INCLUDED


#include "DecorationModule.h"


namespace slgLib
{
    namespace IAModule
    {
        namespace BehaviourTree
        {
            /*Module that execute its child and always return success, whatever the result is*/
            class SuccessDModule : public DecorationModule
            {
            public:
                SuccessDModule(IModule& child) :
                    DecorationModule{ child }
                {}

                generalModule::returnState operator()();
            };
        }
    }
}


#endif //!SUCCESSDMODULE_H_INCLUDED