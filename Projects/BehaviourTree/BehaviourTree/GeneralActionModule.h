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
            template<class Foncteur>
            class GeneralActionModule : public ActionModule
            {
            private:
                Foncteur m_Foncteur;


            public:
                GeneralActionModule() = delete;

                GeneralActionModule(const Foncteur& fonct) noexcept :
                    m_Foncteur{ fonct }
                {}

                /*
                Set the foncteur to use. 
                This foncteur :
                - MUST Return a generalModule::returnState variable
                - doesn't have any parameter in the operator()
                -> no parameter between () the lambda. Use the capture...
                */
                void setAnActionModule(const Foncteur& fonct) const noexcept
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
