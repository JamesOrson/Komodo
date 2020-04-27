#pragma once

#include <komodo/core/ecs/components/component.h>
#include <komodo/core/ecs/entities/entity.h>
#include <memory>

/*TODO: Waiting on BehaviorSystem implementation
class BehaviorSystem;*/
class Component;
class Entity;

namespace komodo::core::ecs::components
{
  class BehaviorComponent : public Component
  {
    /*TODO: Waiting on BehaviorSystem implementation
    friend class BehaviorSystem;*/
public:
#pragma region Constructors
    BehaviorComponent(
      std::weak_ptr<komodo::core::ecs::entities::Entity> parent,
      bool isEnabled = true);
#pragma endregion

    virtual ~BehaviorComponent();

#pragma region Member Methods
    virtual void update(float dt) = 0;
#pragma endregion
  };
} // namespace komodo::core::ecs::components