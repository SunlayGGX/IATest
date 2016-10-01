#ifndef IMODULE_H_INCLUDED
#define IMODULE_H_INCLUDED


namespace slgLib
{
    namespace IAModule
    {
        namespace BehaviourTree
        {
            namespace generalModule
            {
                /*Return type of the module execution*/
                enum returnState
                {
                    Fail        = 0,
                    Success     = 1,
                    InProcess   = 2
                };

                /*
                The type of the module : 
                Is it a composed module ?
                Is it an action module ?
                Or a decoration module ?
                */
                enum moduleType
                {
                    Composed,
                    Decoration,
                    Action
                };
            }


            /*Interface for all behaviour tree modules*/
            class IModule
            {
            public:
                virtual generalModule::moduleType getModuleType() const noexcept = 0;

                virtual generalModule::returnState operator()() = 0;
            };
        }
    }
}


#endif //!IMODULE_H_INCLUDED