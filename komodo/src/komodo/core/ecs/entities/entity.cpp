#include <komodo/core/ecs/entities/entity.h>

namespace komodo::core::ecs::components
{
  class BehaviorComponent;
}

namespace komodo::core::ecs::entities
{
#pragma region Constructors
  Entity::Entity(std::weak_ptr<Game> game)
  {
    this->id = nextId++;
    this->game = game;
    this->isEnabled = true;
    // this->position = Vector3();
    // this->rotation= Vector3();
    // this->scale = Vector3();
  }
#pragma endregion

  Entity::~Entity() {}

#pragma region Static Members
  unsigned int Entity::nextId = 0u;
#pragma endregion

#pragma region Accessors
  std::vector<std::shared_ptr<komodo::core::ecs::components::Component>> Entity::getComponents() const
  {
    return this->components;
  }

  std::weak_ptr<Game> Entity::getGame() const
  {
    return this->game;
  }

  unsigned int Entity::getId() const
  {
    return this->id;
  }

  bool Entity::getIsEnabled() const
  {
    return this->isEnabled;
  }
  /*TODO: Waiting on Vector3 implementation
  Vector3 Entity::getPosition() const
  {
      return this->position;
  }

  Vector3 Entity::getRotation() const
  {
      return this->rotation;
  }

  Vector3 Entity::getScale() const
  {
      return this->scale;
  }*/
#pragma endregion

#pragma region Mutators
  void Entity::setIsEnabled(bool value)
  {
    this->isEnabled = value;
  }

  /*TODO: Waiting on Vector3 implementation
  void setPosition(Vector3 value)
  {
      this->position = value;
  }

  void setRotation(Vector3 value)
  {
      this->rotation = value;
  }

  void setScale(Vector3 value)
  {
      this->scale = value;
  }
  */
#pragma endregion

#pragma region Member Methods
  bool Entity::addComponent(std::shared_ptr<komodo::core::ecs::components::BehaviorComponent> component)
  {
    if (auto g = this->game.lock())
    {
      this->components.push_back(component);
      if (auto behaviorSystem = g->getBehaviorSystem().lock())
      {
        return behaviorSystem->addComponent(component);
      }
    }
    return false;
  }

  bool Entity::clearComponents()
  {
    return false;
  }

  /*TODO: Waiting on Matrix implementation
  Matrix getRotationMatrix() const;*/
  /*TODO: Waiting on Quaternion implementation
  Matrix getRotationQuaternion() const;*/
  /*TODO: Waiting on Component implementation
  bool removeComponent(std::weak_ptr<Component> component)
  {
      if (auto componentToRemove = component.get())
      {
          return this->removeComponent(componentToRemove->id);
      }
      else
      {
          return false;
      }
  }*/

  bool removeComponent([[maybe_unused]] unsigned int componentId)
  {
    std::vector<unsigned int> ids; // TODO: iterate over all components instead
    for (auto component = ids.begin(); component != ids.end(); ++component)
    {
      if (*component == componentId)
      {
        //(*it)->setParent(nullptr);
        ids.erase(component);
        return true;
      }
    }
    return false;
  }
#pragma endregion
} // namespace komodo::core::ecs::entities