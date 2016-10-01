#include "DecorationModule.h"

#include <stdexcept>

using slgLib::IAModule::BehaviourTree::DecorationModule;


class ErrorCannotDisconnect : public std::exception
{
public:
    ErrorCannotDisconnect() : std::exception{"AIE ! A decoration module must always be attached !"}
    {}
};

void DecorationModule::disconnect(IModule* otherModule)
{
    throw ErrorCannotDisconnect{};
}