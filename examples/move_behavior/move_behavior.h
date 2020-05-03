#pragma once

#include <komodo/core/ecs/components/behavior_component.h>
#include <komodo/core/ecs/entities/entity.h>
#include <komodo/core/game.h>

class MoveBehavior : public komodo::core::ecs::components::BehaviorComponent
{
  public:
#pragma region Constructors
  MoveBehavior(bool isEnabled = true)
    : komodo::core::ecs::components::BehaviorComponent(isEnabled)
  {}
#pragma endregion

  virtual ~MoveBehavior() {}

  void initialize() {}

#pragma region Member Methods
  void update([[maybe_unused]] float dt) {}
#pragma endregion
};