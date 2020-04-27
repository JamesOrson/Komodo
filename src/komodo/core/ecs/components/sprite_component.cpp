#include <komodo/core/ecs/components/sprite_component.h>

namespace komodo::core::ecs::components
{
#pragma region Constructors
    SpriteComponent::SpriteComponent(std::weak_ptr<komodo::core::ecs::entities::Entity> parent/*, Texture texture, Effect shader*/) : Drawable2DComponent(parent)
    {
        /*TODO: Waiting on Texture implementation
        this->texture = texture;*/
    }
    /*TODO: Waiting on Texture implementation
    SpriteComponent::SpriteComponent(std::weak_ptr<komodo::core::ecs::entities::Entity> parent, string texturePath, Effect shader) : Drawable2DComponent(parent)
    {
        this->texture = texture;
    }*/
#pragma endregion

    SpriteComponent::~SpriteComponent()
    {
    }

#pragma region Accessors
    /*TODO: Waiting on Vector2 implementation
    virtual Vector2 getCenter() const;*/
    float SpriteComponent::getHeight() const
    {
        return 0.0f;
        /*TODO: Waiting on Texture implementation
        return this->texture.height * this->scale.y;*/
    }
    float SpriteComponent::getWidth() const
    {
        return 0.0f;
        /*TODO: Waiting on Texture implementation
        return this->texture.width * this->scale.x;*/
    }
#pragma endregion

#pragma region Mutators
    /*TODO: Waiting on Texture implementation
    void setTexture(Texture value)
    {
        this->texture = texture;
    }
    */
#pragma endregion
}