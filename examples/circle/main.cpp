#include <komodo/core/game.h>
#include <komodo/core/ecs/entities/entity.h>
#include <komodo/core/ecs/components/sprite_component.h>
#include <memory>

int main(/*int argc, const char **argv*/)
{
  auto game = komodo::core::Game();
  auto entity = komodo::core::ecs::entities::Entity(game);
  auto component = komodo::core::ecs::components::SpriteComponent(std::string("../../assets/player.png"));
  game.run();

  return 0;
}
