#pragma once

#include <komodo/core/ecs/components/drawable_2d_component.h>

#include <memory>
#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>
#include <string>

namespace komodo::core::ecs::components
{
  class SpriteComponent : public Drawable2DComponent
  {
    friend komodo::core::ecs::systems::Render2DSystem;

public:
#pragma region Constructors
    SpriteComponent(
      /*, Texture texture, Effect shader,*/
      bool isBillboard = false,
      bool isEnabled = true);
    SpriteComponent(
      std::string texturePath,
      /*, Texture texture, Effect shader,*/
      bool isBillboard = false,
      bool isEnabled = true);
#pragma endregion

    virtual ~SpriteComponent();

#pragma region Accessors
    /*TODO: Waiting on Vector2 implementation
    Vector2 getCenter() const;*/
    float getHeight() const;
    /*TODO: Waiting on Effect implementation
    Effect getShader() const;*/
    /*TODO: Waiting on Texture implementation
    Texture getTexture() const;
    */
    std::string getTexturePath() const;
    float getWidth() const;
#pragma endregion

#pragma region Mutators
    /*TODO: Waiting on Texture implementation
    void setTexture(Texture value);*/
#pragma endregion

private:
#pragma region Members
    /*TODO: Waiting on texture implementation
    Texture texture;*/
    sf::Sprite sprite;
    sf::Texture texture;
    std::string texturePath;
#pragma endregion

#pragma region Member Methods
    void refreshSprite();
#pragma endregion
  };
} // namespace komodo::core::ecs::components