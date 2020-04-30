#pragma once

#include <komodo/core/ecs/components/drawable_2d_component.h>
#include <komodo/core/ecs/components/sprite_component.h>
#include <komodo/core/ecs/components/text_component.h>
#include <komodo/core/ecs/entities/entity.h>
#include <komodo/core/ecs/systems/system.h>

#include <memory>
#include <queue>
#include <vector>

namespace komodo::core::ecs::systems
{
  class Render2DSystem : public System
  {
    friend komodo::core::ecs::entities::Entity;

public:
#pragma region Constructors
    Render2DSystem();
#pragma endregion

    virtual ~Render2DSystem();

#pragma region Accessors
    std::vector<
      std::shared_ptr<komodo::core::ecs::components::Drawable2DComponent>>
    getComponents() const;
#pragma endregion

#pragma region Member Methods
    void initialize();
    void draw(float dt);
#pragma endregion

private:
#pragma region Members
    std::vector<
      std::shared_ptr<komodo::core::ecs::components::Drawable2DComponent>>
      components;
    std::queue<
      std::shared_ptr<komodo::core::ecs::components::Drawable2DComponent>>
      uninitializedComponents;
#pragma endregion

#pragma region Member Methods
    bool addComponent(
      std::shared_ptr<komodo::core::ecs::components::Drawable2DComponent>
        component);
    bool
    addEntity(const unsigned int entityId);
    void drawComponent(
      std::shared_ptr<komodo::core::ecs::components::Drawable2DComponent> component);
    void initializeComponents();
    bool removeEntity(const unsigned int entityId);
#pragma endregion
  };
} // namespace komodo::core::ecs::systems