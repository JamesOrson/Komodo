#include <komodo/core/ecs/components/sprite_component.h>
#include <komodo/core/ecs/components/drawable_2d_component.h>
#include <spdlog/spdlog.h>

namespace komodo::core::ecs::components
{
#pragma region Constructors  
  SpriteComponent::SpriteComponent(
    /*, Texture texture, Effect shader,*/
    bool isBillboard,
    bool isEnabled)
    : Drawable2DComponent(isBillboard, isEnabled)
  {

  }
  
  SpriteComponent::SpriteComponent(
    std::string texturePath,
    /*, Texture texture, Effect shader,*/
    bool isBillboard,
    bool isEnabled)
    : Drawable2DComponent(isBillboard, isEnabled)
  {
    if (!this->texture.loadFromFile(texturePath))
    {
      spdlog::critical("Failed to load texture from path: {}", texturePath);
    }
    else
    {
      this->refreshSprite();
    }
  }
#pragma endregion

  SpriteComponent::~SpriteComponent() {}

#pragma region Accessors
  float SpriteComponent::getHeight() const
  {
    return 0.0f;
  }
  
  sf::Sprite SpriteComponent::getSprite() const
  {
    return this->sprite;
  }

  std::string SpriteComponent::getTexturePath() const
  {
    return "";
  }
  
  float SpriteComponent::getWidth() const
  {
    return 0.0f;
  }
#pragma endregion

#pragma region Member Methods
  void SpriteComponent::refreshSprite()
  {
    this->sprite.setTexture(this->texture);
  }
#pragma endregion
} // namespace komodo::core::ecs::components