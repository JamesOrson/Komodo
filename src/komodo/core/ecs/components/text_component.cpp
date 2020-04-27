#include <komodo/core/ecs/components/text_component.h>

namespace komodo::core::ecs::components
{
#pragma region Constructors
    TextComponent::TextComponent(
        std::weak_ptr<komodo::core::ecs::entities::Entity> parent /*, Font font, Effect shader*/, bool isBillboard,
        bool isEnabled)
        : Drawable2DComponent(parent, isBillboard, isEnabled)
    {
        /*TODO: Waiting on Font implementation
        this->font = font;*/
    }
    /*TODO: Waiting on Font implementation
    TextComponent::TextComponent(std::weak_ptr<komodo::core::ecs::entities::Entity> parent, string fontPath, Effect
    shader) : Drawable2DComponent(parent)
    {
        this->font = font;
    }*/
#pragma endregion

    TextComponent::~TextComponent() {}

#pragma region Accessors
    /*TODO: Waiting on Vector2 implementation
    virtual Vector2 getCenter() const;*/
    float TextComponent::getHeight() const
    {
        return 0.0f;
        /*TODO: Waiting on Texture implementation
        return this->texture.height * this->scale.y;*/
    }
    float TextComponent::getWidth() const
    {
        return 0.0f;
        /*TODO: Waiting on Texture implementation
        return this->texture.width * this->scale.x;*/
    }
#pragma endregion

#pragma region Mutators
    /*TODO: Waiting on Font implementation
    void setFont(Font value)
    {
        this->font = font;
    }
    */
#pragma endregion
} // namespace komodo::core::ecs::components