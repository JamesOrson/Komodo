#pragma once

#include <komodo/core/ecs/components/behavior_component.h>
#include <komodo/core/ecs/entities/entity.h>

#include <iostream>
#include <spdlog/spdlog.h>

class SimpleBehavior : public komodo::core::ecs::components::BehaviorComponent
{
  /*TODO: Waiting on BehaviorSystem implementation
  friend class BehaviorSystem;*/
  public:
#pragma region Constructors
  SimpleBehavior(bool isEnabled = true)
    : komodo::core::ecs::components::BehaviorComponent(isEnabled)
  {}
#pragma endregion

  virtual ~SimpleBehavior()
  {
    std::cout << "Deleting\n";
  }

#pragma region Member Methods
  void update([[maybe_unused]] float dt)
  {
    std::cout << "Updating\n";
  }
#pragma endregion
};