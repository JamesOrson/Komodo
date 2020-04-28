#pragma once

#include <komodo/core/ecs/components/behavior_component.h>
#include <komodo/core/ecs/entities/entity.h>
#include <memory>

#include <iostream>

namespace komodo::core::ecs::components
{
  class MoveBehavior : public komodo::core::ecs::components::BehaviorComponent
  {
    /*TODO: Waiting on BehaviorSystem implementation
    friend class BehaviorSystem;*/
public:
#pragma region Constructors
    MoveBehavior(
      std::weak_ptr<komodo::core::ecs::entities::Entity> parent,
      bool isEnabled = true)
      : komodo::core::ecs::components::BehaviorComponent(parent, isEnabled)
    {}
#pragma endregion

    virtual ~MoveBehavior() {}

#pragma region Member Methods
    void update([[maybe_unused]] float dt)
    {
    }
#pragma endregion
  };
} // namespace komodo::core::ecs::components