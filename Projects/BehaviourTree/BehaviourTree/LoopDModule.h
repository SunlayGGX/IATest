#ifndef LOOPDMODULE_H_INCLUDED
#define LOOPDMODULE_H_INCLUDED


#include "DecorationModule.h"


namespace slgLib
{
    namespace IAModule
    {
        namespace BehaviourTree
        {
            /*Loop its child a number of time predetermined and return the last ret*/
            class LoopDModule : public DecorationModule
            {
            protected:
                size_t m_IterationCount;


            public:
                LoopDModule() = delete;

                LoopDModule(IModule& child, size_t countLoop) noexcept : 
                    DecorationModule{ child },
                    m_IterationCount{ countLoop }
                {}

                virtual generalModule::returnState operator()() = 0;
            };
        }
    }
}


#endif //!LOOPDMODULE_H_INCLUDED