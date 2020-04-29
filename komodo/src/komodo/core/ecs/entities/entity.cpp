#include <komodo/core/ecs/entities/entity.h>

namespace komodo::core::ecs::components
{
  class BehaviorComponent;
}

namespace komodo::core::ecs::entities
{
#pragma region Constructors
  Entity::Entity(komodo::core::Game &game)
    : game(game)
  {
    this->id = nextId++;
    this->isEnabled = true;
    // this->position = Vector3();
    // this->rotation= Vector3();
    // this->scale = Vector3();

    entityStore[this->id] = this;
  }
#pragma endregion

  Entity::~Entity()
  {
    if (entityStore.count(this->id) != 0)
    {
      this->game.getBehaviorSystem()->removeEntity(this->id);
      entityStore.erase(this->id);
    }
  }

#pragma region Static Members
  std::unordered_map<unsigned int, Entity*> Entity::entityStore;
  unsigned int Entity::nextId = 1u;
  unsigned int Entity::emptyId = 0u;
#pragma endregion

#pragma region Accessors
  std::vector<std::shared_ptr<komodo::core::ecs::components::Component>>
  Entity::getComponents() const
  {
    return this->components;
  }

  komodo::core::Game& Entity::getGame() const
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
  bool Entity::addComponent(
    std::shared_ptr<komodo::core::ecs::components::BehaviorComponent> component)
  {
    if (auto parent = getEntity(component->getParentId()))
    {
      parent->removeComponent(component->getId());
    }
    component->parentId = this->id;
    this->components.push_back(component);
    if (auto behaviorSystem = this->game.getBehaviorSystem())
    {
      return behaviorSystem->addComponent(component);
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

  bool Entity::removeComponent([[maybe_unused]] unsigned int componentId)
  {
    for (auto component = this->components.begin();
         component != this->components.end();
         ++component)
    {
      if ((*component)->getId() == componentId)
      {
        (*component)->parentId = entities::Entity::emptyId;
        this->components.erase(component);
        return true;
      }
    }

    return false;
  }
#pragma endregion

#pragma region Static Member Methods
  Entity* Entity::getEntity(unsigned int entityId)
  {
    if (entityStore.count(entityId) == 1)
    {
      return entityStore[entityId];
    }
    else
    {
      return nullptr;
    }
  }
#pragma endregion
} // namespace komodo::core::ecs::entities