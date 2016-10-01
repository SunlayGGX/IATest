#ifndef DECORATIONMODULE_H_INCLUDED
#define DECORATIONMODULE_H_INCLUDED

#include "IModule.h"


namespace slgLib
{
    namespace IAModule
    {
        namespace BehaviourTree
        {
            /*Interface for all decoration behaviour tree modules*/
            class DecorationModule : public IModule
            {
            protected:
                IModule& m_Child;

            public:
                DecorationModule() = delete;

                DecorationModule(IModule& child) noexcept : 
                    m_Child{child}
                {}

                virtual IModule& child(size_t index)   const noexcept
                {
                    return m_Child;
                }

                virtual size_t connectionCount()       const noexcept
                {
                    return 1;
                }

                virtual generalModule::moduleType getModuleType() const noexcept
                {
                    return generalModule::Decoration;
                }

                virtual void connect(IModule& otherModule)
                {
                    m_Child = otherModule;
                }

                /*Do nothing because a decorated module exists only when connected*/
                void disconnect(IModule& otherModule) 
                {}

                virtual generalModule::returnState operator()() = 0;
            };
        }
    }
}


#endif //!DECORATIONMODULE_H_INCLUDED