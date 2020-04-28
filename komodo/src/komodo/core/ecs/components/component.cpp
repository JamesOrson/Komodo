#include <komodo/core/ecs/components/component.h>

namespace komodo::core::ecs::entities
{
  class Entity;
}

namespace komodo::core::ecs::components
{
#pragma region Constructors
  Component::Component(
    std::weak_ptr<komodo::core::ecs::entities::Entity> parent,
    bool isEnabled)
  {
    this->id = nextId++;
    this->isEnabled = isEnabled;
    this->isInitialized = false;
    this->parent = parent;
    // this->position = Vector3();
    // this->rotation= Vector3();
    // this->scale = Vector3();
  }
#pragma endregion

  Component::~Component() {}

#pragma region Static Members
  unsigned int Component::nextId = 0u;
#pragma endregion

#pragma region Accessors
  unsigned int Component::getId() const
  {
    return this->id;
  }

  bool Component::getIsEnabled() const
  {
    return this->isEnabled;
  }

  bool Component::getIsInitialized() const
  {
    return this->isInitialized;
  }

  std::weak_ptr<komodo::core::ecs::entities::Entity> Component::getParent() const
  {
    return this->parent;
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
  void Component::setIsEnabled(bool value)
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
  /*TODO: Waiting on Matrix implementation
  Matrix getRotationMatrix() const;*/
  /*TODO: Waiting on Quaternion implementation
  Matrix getRotationQuaternion() const;*/
#pragma endregion
} // namespace komodo::core::ecs::components