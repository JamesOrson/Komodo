#include <komodo/core/ecs/components/behavior_component.h>

namespace komodo::core::ecs::components
{
#pragma region Constructors
  BehaviorComponent::BehaviorComponent(bool isEnabled)
    : Component(isEnabled)
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