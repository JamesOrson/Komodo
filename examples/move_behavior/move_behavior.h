#pragma once

#include <komodo/core/ecs/components/behavior_component.h>
#include <komodo/core/ecs/entities/entity.h>

#include <iostream>
#include <spdlog/spdlog.h>

class MoveBehavior : public komodo::core::ecs::components::BehaviorComponent
{
  public:
#pragma region Constructors
  MoveBehavior(bool isEnabled = true)
    : komodo::core::ecs::components::BehaviorComponent(isEnabled)
  {}
#pragma endregion

  virtual ~MoveBehavior()
  {
    std::cout << "Deleting\n";
  }

  void initialize()
  {
    this->parent =
      komodo::core::ecs::entities::Entity::getEntity(this->parentId);
  }

#pragma region Member Methods
  void update([[maybe_unused]] float dt)
  {
  }
#pragma endregion

  private:
#pragma region Members
  komodo::core::ecs::entities::Entity *parent;
#pragma endregion
};