#ifndef IMODULE_H_INCLUDED
#define IMODULE_H_INCLUDED


namespace slgLib
{
    namespace IAModule
    {
        namespace BehaviourTree
        {
            namespace moduleType
            {
                enum returnValue
                {
                    Fail        = 0,
                    Success     = 1,
                    InProcess   = 2
                };
            }


            class IModule
            {
            public:
                virtual IModule* child(std::size_t index)   const noexcept = 0;
                virtual std::size_t connectionCount()       const noexcept = 0;

                virtual void connect(IModule* otherModule)      = 0;
                virtual void disconnect(IModule* otherModule)   = 0;

                virtual returnValue::returnType operator()() = 0;
            };
        }
    }
}


#endif //!IMODULE_H_INCLUDED