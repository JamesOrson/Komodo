#include <komodo/core/ecs/components/drawable_2d_component.h>

namespace komodo::core::ecs::components
{
#pragma region Constructors
  Drawable2DComponent::Drawable2DComponent(
    std::weak_ptr<komodo::core::ecs::entities::Entity> parent,
    bool isBillboard,
    bool isEnabled)
    : Component(parent, isEnabled)
  {
    this->isBillboard = isBillboard;
  }
#pragma endregion

  Drawable2DComponent::~Drawable2DComponent() {}

#pragma region Accessors
  /*TODO: Waiting on Vector2 implementation
  virtual Vector2 getCenter() const;*/
  bool Drawable2DComponent::getIsBillboard() const
  {
    return this->isBillboard;
  }
  /*TODO: Waiting on Effect implementation
  Effect Drawable2DComponent::getShader() const
  {
      return this->shader;
  }*/
#pragma endregion

#pragma region Mutators
  void Drawable2DComponent::setIsBillboard(bool value)
  {
    this->isBillboard = value;
  }
  /*TODO: Waiting on Effect implementation
  void Drawable2DComponent::setShader(Effect value)
  {
      this->shader = value;
  }*/
#pragma endregion
} // namespace komodo::core::ecs::components