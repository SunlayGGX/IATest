#ifndef ICANBEPARENTMODULE_H_INCLUDED
#define ICANBEPARENTMODULE_H_INCLUDED


#include "IModule.h"


namespace slgLib
{
    namespace IAModule
    {
        namespace BehaviourTree
        {
            /*Interface for all behaviour tree modules*/
            class ICanBeParentModule : public IModule
            {
            public:
                virtual IModule& child(size_t index)   noexcept       = 0;
                virtual size_t connectionCount()       const noexcept = 0;

                virtual void connect(IModule& otherModule) = 0;

                virtual void disconnect(IModule& otherModule) = 0;
                virtual void disconnect(size_t index) = 0;
            };
        }
    }
}


#endif //!ICANBEPARENTMODULE_H_INCLUDED