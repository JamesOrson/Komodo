#pragma once

#include <komodo/core/ecs/components/drawable_2d_component.h>
#include <komodo/core/ecs/entities/entity.h>
#include <memory>

class Drawable2DComponent;
class Entity;

namespace komodo::core::ecs::components
{
    class TextComponent : public Drawable2DComponent
    {
    public:
#pragma region Constructors
        TextComponent(std::weak_ptr<komodo::core::ecs::entities::Entity> parent/*, Font font, Effect shader*/);
        /*TextComponent(std::weak_ptr<komodo::core::ecs::entities::Entity> parent, string fontPath, Effect shader);*/
#pragma endregion

        ~TextComponent();

#pragma region Accessors
        /*TODO: Waiting on Vector2 implementation
        Vector2 getCenter() const;*/
        float getHeight() const;
        /*TODO: Waiting on Effect implementation
        Effect getShader() const;*/
        /*TODO: Waiting on Font implementation
        Font getFont() const;
        std:;string getFontPath() const
        */
        float getWidth() const;
#pragma endregion

#pragma region Mutators
        /*TODO: Waiting on Font implementation
        void setFont(Font value);*/
#pragma endregion

#pragma region Members
        /*TODO: Waiting on Font implementation
        Font font;
        string fontPath;*/
#pragma endregion
    };
}