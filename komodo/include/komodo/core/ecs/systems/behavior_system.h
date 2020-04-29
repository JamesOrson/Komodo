#pragma once

#include <komodo/core/ecs/components/behavior_component.h>
#include <komodo/core/ecs/systems/system.h>
#include <komodo/core/game.h>
#include <memory>
#include <queue>
#include <vector>

namespace komodo::core
{
  class Game;

  namespace ecs::entities
  {
    class Entity;
  }
} // namespace komodo::core

namespace komodo::core::ecs::systems
{
  class BehaviorSystem : public System
  {
    friend komodo::core::ecs::entities::Entity;

public:
#pragma region Constructors
    BehaviorSystem();
#pragma endregion

    virtual ~BehaviorSystem();

#pragma region Accessors
    std::vector<
      std::shared_ptr<komodo::core::ecs::components::BehaviorComponent>>
    getComponents() const;
#pragma endregion

#pragma region Member Methods
    void initialize();
    void postUpdate(float dt);
    void preUpdate(float dt);
    void update(float dt);
#pragma endregion

private:
#pragma region Members
    std::vector<
      std::shared_ptr<komodo::core::ecs::components::BehaviorComponent>>
      components;
    std::queue<
      std::shared_ptr<komodo::core::ecs::components::BehaviorComponent>>
      uninitializedComponents;
#pragma endregion

#pragma region Member Methods
    bool addComponent(
      std::shared_ptr<komodo::core::ecs::components::BehaviorComponent>
        component);
    bool
    addEntity(const unsigned int entityId);
    void initializeComponents();
    bool removeEntity(const unsigned int entityId);
#pragma endregion
  };
} // namespace komodo::core::ecs::systems