#ifndef BEHAVIORTREEOBJECT_H_INCLUDED
#define BEHAVIORTREEOBJECT_H_INCLUDED


#include "ComposedModuleList.h"
#include "DecorateModuleList.h"

#include "GeneralActionModule.h"


#include <algorithm>


namespace slgLib
{
    namespace IAModule
    {
        namespace BehaviourTree
        {
            /*
            A huge behavior tree object.
            */
            class BehaviorTreeObject : public IModule
            {
            private:
                IModule& m_Root;


            public:
                BehaviorTreeObject(IModule& root) noexcept :
                    m_Root{root}
                {}


                IModule& getRoot() noexcept
                {
                    return m_Root;
                }


                virtual IModule& child(size_t index)   noexcept
                {
                    return m_Root.child(index);
                }

                virtual size_t connectionCount()       const noexcept
                {
                    return m_Root.connectionCount();
                }

                virtual void connect(IModule& otherModule)
                {
                    m_Root.connect(otherModule);
                }

                virtual void disconnect(IModule& otherModule)
                {
                    m_Root.disconnect(otherModule);
                }

                virtual void disconnect(size_t index)
                {
                    m_Root.disconnect(index);
                }


                generalModule::moduleType getModuleType() const noexcept
                {
                    return m_Root.getModuleType();
                }

                generalModule::returnState operator()()
                {
                    return m_Root();
                }

                template<class ... IntegerIndex>
                IModule* operator()(IntegerIndex ... indexes)
                {
                    IModule* iteratorMod= &m_Root;

                    size_t argument[] = { indexes... };

                    std::for_each(std::begin(argument),
                                  std::end(argument),
                                  [&iteratorMod](size_t index){
                                      iteratorMod = &iteratorMod->child(index);
                                  }
                    );
                    
                    return iteratorMod;
                }
            };
        }
    }
}


#endif //!BEHAVIORTREEOBJECT_H_INCLUDED