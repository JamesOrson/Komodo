#include <komodo/core/ecs/components/behavior_component.h>
#include <komodo/core/ecs/components/component.h>

namespace komodo::core::ecs::components
{
#pragma region Constructors
  BehaviorComponent::BehaviorComponent(
    std::weak_ptr<komodo::core::ecs::entities::Entity> parent,
    bool isEnabled)
    : Component(parent, isEnabled)
  {}
#pragma endregion

  BehaviorComponent::~BehaviorComponent() {}

#pragma region Member Methods
  void BehaviorComponent::initialize()
  {
    this->isInitialized = true;
  }
#pragma endregion
} // namespace komodo::core::ecs::components