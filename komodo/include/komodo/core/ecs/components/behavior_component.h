#pragma once

#include <komodo/core/ecs/components/component.h>
#include <memory>

namespace komodo::core::ecs::entities
{
  class Entity;
}

namespace komodo::core::ecs::components
{
  class BehaviorComponent : public Component
  {
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