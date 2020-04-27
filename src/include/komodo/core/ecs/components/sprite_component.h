#pragma once

#include <komodo/core/ecs/components/drawable_2d_component.h>
#include <komodo/core/ecs/entities/entity.h>
#include <memory>

class Drawable2DComponent;
class Entity;

namespace komodo::core::ecs::components
{
  class SpriteComponent : public Drawable2DComponent
  {
public:
#pragma region Constructors
    SpriteComponent(
      std::weak_ptr<komodo::core::ecs::entities::Entity>
        parent /*, Texture texture, Effect shader*/,
      bool isBillboard = false,
      bool isEnabled = true);
    /*SpriteComponent(std::weak_ptr<komodo::core::ecs::entities::Entity>
     * parent, string texturePath, Effect shader);*/
#pragma endregion

    ~SpriteComponent();

#pragma region Accessors
    /*TODO: Waiting on Vector2 implementation
    Vector2 getCenter() const;*/
    float getHeight() const;
    /*TODO: Waiting on Effect implementation
    Effect getShader() const;*/
    /*TODO: Waiting on Texture implementation
    Texture getTexture() const;
    std:;string getTexturePath() const
    */
    float getWidth() const;
#pragma endregion

#pragma region Mutators
    /*TODO: Waiting on Texture implementation
    void setTexture(Texture value);*/
#pragma endregion

#pragma region Members
    /*TODO: Waiting on texture implementation
    Texture texture;
    string texturePath;*/
#pragma endregion
  };
} // namespace komodo::core::ecs::components