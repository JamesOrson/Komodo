#include <komodo/core/ecs/components/behavior_component.h>
#include <komodo/core/ecs/systems/behavior_system.h>
#include <komodo/core/game.h>
#include <memory>
#include <typeinfo>

namespace komodo::core::ecs::systems
{
#pragma region Constructors
  BehaviorSystem::BehaviorSystem() {}
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
    if (auto parent = component->getParent().lock())
    {
      if (this->entities.count(parent->getId()) == 0)
      {
        return this->addEntity(parent);
      }
      else
      {
        if (!component->getIsInitialized())
        {
          this->uninitializedComponents.push(component);
        }
        this->components.push_back(component);
        return true;
      }
    }
    return false;
  }

  bool BehaviorSystem::addEntity(
    std::shared_ptr<komodo::core::ecs::entities::Entity> entityToAdd)
  {
    if (entityToAdd && this->entities.count(entityToAdd->getId()) == 0)
    {
      this->entities[entityToAdd->getId()] = entityToAdd;

      for (auto componentToAdd : entityToAdd->getComponents())
      {
        if (auto component = std::dynamic_pointer_cast<
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

  void BehaviorSystem::update([[maybe_unused]] float dt)
  {
    for (auto component : this->components)
    {
      if (auto parent = component->getParent().lock())
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