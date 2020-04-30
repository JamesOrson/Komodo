#include <komodo/core/game.h>
#include <komodo/core/ecs/entities/entity.h>
#include <komodo/core/ecs/components/sprite_component.h>
#include <memory>

int main(/*int argc, const char **argv*/)
{
  auto game = komodo::core::Game();
  auto entity = komodo::core::ecs::entities::Entity(game);
  auto system = game.createRender2DSystem();
  entity.setRender2DSystem(system);
  auto component = std::make_shared<komodo::core::ecs::components::SpriteComponent>(std::string("../../assets/player.png"));
  entity.addComponent(std::dynamic_pointer_cast<komodo::core::ecs::components::Drawable2DComponent>(component));
  game.run();

  return 0;
}
