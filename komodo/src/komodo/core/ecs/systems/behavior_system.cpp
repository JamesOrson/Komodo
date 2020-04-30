#include <komodo/core/ecs/systems/behavior_system.h>

namespace komodo::core::ecs::systems
{
#pragma region Constructors
  BehaviorSystem::BehaviorSystem(komodo::core::Game &game)
    : System(game)
  {}
#pragma endregion

  BehaviorSystem::~BehaviorSystem() {}

#pragma region Accessors
  std::vector<std::shared_ptr<komodo::core::ecs::components::BehaviorComponent>>
  BehaviorSystem::getComponents() const
  {
    return this->components;
  }
#pragma endregion

#pragma region Member Methods
  bool BehaviorSystem::addComponent(
    std::shared_ptr<komodo::core::ecs::components::BehaviorComponent> component)
  {
    auto parentId = component->getParentId();
    if (this->entities.count(parentId) == 0)
    {
      return this->addEntity(parentId);
    }
    else
    {
      component->parentId = parentId;
      if (!component->getIsInitialized())
      {
        this->uninitializedComponents.push(component);
      }
      this->components.push_back(component);
      return true;
    }
  }

  bool BehaviorSystem::addEntity(unsigned int entityId)
  {
    if (auto entityToAdd = entities::Entity::getEntity(entityId))
    {
      if (this->entities.count(entityId) == 0)
      {
        this->entities.insert(entityId);
        for (auto componentToAdd : entityToAdd->getComponents())
        {
          if (
            auto component = std::dynamic_pointer_cast<
              komodo::core::ecs::components::BehaviorComponent>(componentToAdd))
          {
            this->addComponent(component);
          }
        }
        return true;
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false;
    }
  }

  void BehaviorSystem::initialize()
  {
    this->isInitialized = true;
    this->initializeComponents();
  }

  void BehaviorSystem::initializeComponents()
  {
    while (!this->uninitializedComponents.empty())
    {
      auto component = this->uninitializedComponents.front();
      if (!component->getIsInitialized())
      {
        component->isInitialized = true;
        component->initialize();
      }
      this->uninitializedComponents.pop();
    }
  }

  void BehaviorSystem::postUpdate([[maybe_unused]] float dt)
  {
    this->initialize();
  }

  void BehaviorSystem::preUpdate([[maybe_unused]] float dt)
  {
    this->initialize();
  }

  bool BehaviorSystem::removeEntity(const unsigned int entityId)
  {
    if (this->entities.count(entityId) == 1)
    {
      if (auto entity = entities::Entity::getEntity(entityId))
      {
        // Remove all components from BehaviorSystem that were part of the Entity
        for (auto component : entity->getComponents())
        {
          // Check that Component is of type BehaviorComponent
          if (
            auto componentToRemove = std::dynamic_pointer_cast<
              komodo::core::ecs::components::BehaviorComponent>(component))
          {
            // Erase the component from the vector
            this->components.erase(std::remove_if(
              this->components.begin(),
              this->components.end(),
              [componentToRemove](
                std::shared_ptr<
                  komodo::core::ecs::components::BehaviorComponent>
                  systemComponent) {
                return systemComponent->getId() == componentToRemove->getId();
              }));
          }
        }
        this->entities.erase(entityId);
        return true;
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false;
    }
  }

  void BehaviorSystem::update([[maybe_unused]] float dt)
  {
    for (auto component : this->components)
    {
      if (auto parent = entities::Entity::getEntity(component->getParentId()))
      {
        if (parent->getIsEnabled() && component->getIsEnabled())
        {
          component->update(dt);
        }
      }
    }
  }
#pragma endregion
} // namespace komodo::core::ecs::systems