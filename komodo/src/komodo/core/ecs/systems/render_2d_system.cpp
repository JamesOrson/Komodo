#include <komodo/core/ecs/systems/render_2d_system.h>

namespace komodo::core::ecs::systems
{
#pragma region Constructors
  Render2DSystem::Render2DSystem(komodo::core::Game &game)
    : System(game)
  {}
#pragma endregion

  Render2DSystem::~Render2DSystem() {}

#pragma region Accessors
  std::vector<std::shared_ptr<komodo::core::ecs::components::Drawable2DComponent>>
  Render2DSystem::getComponents() const
  {
    return this->components;
  }
#pragma endregion

#pragma region Member Methods
  bool Render2DSystem::addComponent(
    std::shared_ptr<komodo::core::ecs::components::Drawable2DComponent> component)
  {
    auto parentId = component->getParentId();
    if (this->entities.count(parentId) == 0)
    {
      return this->addEntity(parentId);
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

  bool Render2DSystem::addEntity(unsigned int entityId)
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
              komodo::core::ecs::components::Drawable2DComponent>(componentToAdd))
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

  void Render2DSystem::draw([[maybe_unused]] float dt)
  {
    for (auto component : this->components)
    {
      if (auto parent = entities::Entity::getEntity(component->getParentId()))
      {
        if (parent->getIsEnabled() && component->getIsEnabled())
        {
          this->drawComponent(component);
        }
      }
    }
  }

  void Render2DSystem::drawComponent(
    std::shared_ptr<komodo::core::ecs::components::Drawable2DComponent> component)
  {
    if (auto spriteComponent = std::dynamic_pointer_cast < komodo::core::ecs::components::SpriteComponent>(component))
    {
      this->game.getWindow()->draw(spriteComponent->sprite);
    }
  }

  void Render2DSystem::initialize()
  {
    this->isInitialized = true;
    this->initializeComponents();
  }

  void Render2DSystem::initializeComponents()
  {
    while (!this->uninitializedComponents.empty())
    {
      auto component = this->uninitializedComponents.front();
      if (!component->getIsInitialized())
      {
        component->isInitialized = true;
      }
      this->uninitializedComponents.pop();
    }
  }

  bool Render2DSystem::removeEntity(const unsigned int entityId)
  {
    if (this->entities.count(entityId) == 1)
    {
      if (auto entity = entities::Entity::getEntity(entityId))
      {
        // Remove all components from Render2DSystem that were part of the Entity
        for (auto component : entity->getComponents())
        {
          // Check that Component is of type Drawable2DComponent
          if (
            auto componentToRemove = std::dynamic_pointer_cast<
              komodo::core::ecs::components::Drawable2DComponent>(component))
          {
            // Erase the component from the vector
            this->components.erase(std::remove_if(
              this->components.begin(),
              this->components.end(),
              [componentToRemove](
                std::shared_ptr<
                  komodo::core::ecs::components::Drawable2DComponent>
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
#pragma endregion
} // namespace komodo::core::ecs::systems