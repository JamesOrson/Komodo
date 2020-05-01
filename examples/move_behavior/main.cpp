#include <komodo/core/game.h>
#include <komodo/core/ecs/entities/entity.h>
#include <komodo/core/ecs/components/sprite_component.h>

#include <memory>

#include "move_behavior.h"

int main()
{
  auto game = komodo::core::Game();
  auto entity = komodo::core::ecs::entities::Entity(game);
  auto system = game.createRender2DSystem();
  entity.setRender2DSystem(system);
  auto spriteComponent =
    std::make_shared<komodo::core::ecs::components::SpriteComponent>(
      std::string("../../assets/player.png"));
  entity.addComponent(
    std::dynamic_pointer_cast<
      komodo::core::ecs::components::Drawable2DComponent>(spriteComponent));
  auto moveComponent = std::make_shared<MoveBehavior>();
  entity.addComponent(
    std::dynamic_pointer_cast<komodo::core::ecs::components::BehaviorComponent>(
      moveComponent));
  game.run();

  return 0;
}
