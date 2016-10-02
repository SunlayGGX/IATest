#ifndef GENERALACTIONMODULE_H_INCLUDED
#define GENERALACTIONMODULE_H_INCLUDED

#include "ActionModule.h"


namespace slgLib
{
    namespace IAModule
    {
        namespace BehaviourTree
        {
            /*General Action when we want to create an action easily and quickly without thinking too much*/
            class GeneralActionModule : public ActionModule
            {
            private:
                generalModule::returnState (*m_Foncteur)();


            public:
                GeneralActionModule() = delete;

                GeneralActionModule(generalModule::returnState(*fonct)()) noexcept :
                    m_Foncteur{ fonct }
                {}

                /*
                Set the foncteur to use. 
                This foncteur :
                - MUST Return a generalModule::returnState variable
                - doesn't have any parameter in the operator()
                -> no parameter between () the lambda. Use the capture...
                */
                void setAnActionModule(generalModule::returnState(*fonct)()) noexcept
                {
                    m_Foncteur = fonct;
                }

                generalModule::returnState operator()()
                {
                    return m_Foncteur();
                }
            };
        }
    }
}



#endif //!GENERALACTIONMODULE_H_INCLUDED
