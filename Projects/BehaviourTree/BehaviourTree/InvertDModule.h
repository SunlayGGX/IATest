#ifndef INVERTDMODULE_H_INCLUDED
#define INVERTDMODULE_H_INCLUDED

#include "DecorationModule.h"

namespace slgLib
{
    namespace IAModule
    {
        namespace BehaviourTree
        {
            /*Module that invert the result*/
            class InvertDModule : public DecorationModule
            {
            public:
                InvertDModule(IModule& child) :
                    DecorationModule{child}
                {}

                generalModule::returnState operator()();
            };
        }
    }
}


#endif //!INVERTDMODULE_H_INCLUDED