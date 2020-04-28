#include <komodo/core/ecs/components/behavior_component.h>
#include <komodo/core/ecs/systems/behavior_system.h>
#include <komodo/core/game.h>
#include <memory>

namespace komodo::core::ecs::systems
{
  class system;
#pragma region Constructors
  BehaviorSystem::BehaviorSystem()
  {
  }
#pragma endregion

  BehaviorSystem::~BehaviorSystem()
  {
  }

#pragma region Accessors
  std::vector<std::shared_ptr<komodo::core::ecs::components::BehaviorComponent>> BehaviorSystem::getComponents() const
  {
    return this->components;
  }
#pragma endregion

#pragma region Member Methods
  void BehaviorSystem::initialize()
  {

  }

  void BehaviorSystem::postUpdate([[maybe_unused]] float dt)
  {

  }

  void BehaviorSystem::preUpdate([[maybe_unused]] float dt)
  {

  }

  void BehaviorSystem::update([[maybe_unused]] float dt)
  {
    for (auto component : this->components)
    {
      component->update(dt);
    }
  }
#pragma endregion
} // namespace komodo::core::ecs::systems