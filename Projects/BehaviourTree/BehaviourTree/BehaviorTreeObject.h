#ifndef BEHAVIORTREEOBJECT_H_INCLUDED
#define BEHAVIORTREEOBJECT_H_INCLUDED


#include "ComposedModuleList.h"
#include "DecorateModuleList.h"

#include "GeneralActionModule.h"



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
                ICanBeParentModule& m_Root;


            public:
                BehaviorTreeObject(ICanBeParentModule& root) noexcept :
                    m_Root{root}
                {}


                ICanBeParentModule& getRoot() noexcept
                {
                    return m_Root;
                }



                generalModule::moduleType getModuleType() const noexcept
                {
                    return m_Root.getModuleType();
                }

                generalModule::returnState operator()()
                {
                    return m_Root();
                }
            };
        }
    }
}


#endif //!BEHAVIORTREEOBJECT_H_INCLUDED