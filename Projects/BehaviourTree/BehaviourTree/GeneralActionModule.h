#ifndef GENERALACTIONMODULE_H_INCLUDED
#define GENERALACTIONMODULE_H_INCLUDED

#include "ActionModule.h"


namespace slgLib
{
    namespace IAModule
    {
        namespace BehaviourTree
        {
            /*
            General Action when we want to create an action easily and quickly without thinking too much
            If you want to pass a lambda, use decltype()
            */
            template <class Functor>
            class GeneralActionModule : public ActionModule
            {
            private:
                Functor m_Functor;


            public:
                GeneralActionModule() = delete;

                /*
                Construct the module along with the functor to use.
                This foncteur :
                - MUST Return a generalModule::returnState variable
                - doesn't have any parameter in the operator()
                -> no parameter between () the lambda. Use the capture...


                To create with a lambda : 
                auto lambdaM = [capture](){ 
                    TODO
                    return generalModule::returnState::whatever;
                }

                ...

                GeneralActionModule<decltype(lambdaM)>(lambdaM);
                */
                GeneralActionModule(const Functor& functor) noexcept :
                m_Functor{ functor }
                {}

                generalModule::returnState operator()()
                {
                    return m_Functor();
                }
            };
        }
    }
}



#endif //!GENERALACTIONMODULE_H_INCLUDED
