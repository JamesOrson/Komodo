#include <komodo/core/ecs/components/behavior_component.h>

namespace komodo::core::ecs::components
{
#pragma region Constructors
    BehaviorComponent::BehaviorComponent(std::weak_ptr<komodo::core::ecs::entities::Entity> parent) : Component(parent)
    {
    }
#pragma endregion

    BehaviorComponent::~BehaviorComponent()
    {
    }
}