#pragma once

#include <komodo/core/ecs/components/component.h>

#include <memory>

namespace komodo::core::ecs::systems
{
  class Render2DSystem;
} // namespace komodo::core::ecs

namespace komodo::core::ecs::components
{
  class Drawable2DComponent : public Component
  {
    friend komodo::core::ecs::systems::Render2DSystem;

public:
#pragma region Constructors
    Drawable2DComponent(
      /*, Effect shader,*/
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