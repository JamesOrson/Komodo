#pragma once

#include <komodo/core/ecs/components/component.h>
#include <komodo/core/ecs/entities/entity.h>
#include <memory>

class Component;
/*TODO: Waiting on Drawable2DSystem implementation
class Drawable2DSystem;*/
class Entity;

namespace komodo::core::ecs::components
{
  class Drawable2DComponent : public Component
  {
    /*TODO: Waiting on Drawable2DSystem implementation
    friend class Drawable2DSystem;*/
public:
#pragma region Constructors
    Drawable2DComponent(
      std::weak_ptr<komodo::core::ecs::entities::Entity>
        parent /*, Effect shader*/,
      bool isBillboard = false,
      bool isEnabled = true);
#pragma endregion

    virtual ~Drawable2DComponent();

#pragma region Accessors
    /*TODO: Waiting on Vector2 implementation
    virtual Vector2 getCenter() const = 0;*/
    virtual float getHeight() const = 0;
    bool getIsBillboard() const;
    /*TODO: Waiting on Effect implementation
    Effect getShader() const;*/
    virtual float getWidth() const = 0;
#pragma endregion

#pragma region Mutators
    void setIsBillboard(bool value);
    /*TODO: Waiting on Effect implementation
    void setShader(bool value);*/
#pragma endregion

#pragma region Members
    bool isBillboard;
    /*TODO: Waiting on Effect implementation
    Effect shader;*/
#pragma endregion
  };
} // namespace komodo::core::ecs::components