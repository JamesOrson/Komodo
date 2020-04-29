#pragma once

#include <komodo/core/ecs/components/component.h>
#include <memory>

namespace komodo::core::ecs
{
  namespace entities
  {
    class Entity;
  }

  namespace systems
  {
    class BehaviorSystem;
  }
} // namespace komodo::core::ecs

namespace komodo::core::ecs::components
{
  class BehaviorComponent : public Component
  {
    friend komodo::core::ecs::systems::BehaviorSystem;

public:
#pragma region Constructors
    BehaviorComponent(bool isEnabled = true);
#pragma endregion

    virtual ~BehaviorComponent();

#pragma region Member Methods
    virtual void update(float dt) = 0;
#pragma endregion

protected:
#pragma region Member Methods
    virtual void initialize();
#pragma endregion
  };
} // namespace komodo::core::ecs::components