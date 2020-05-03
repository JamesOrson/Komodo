#include <komodo/core/game.h>
#include <komodo/core/ecs/entities/entity.h>
#include <komodo/core/ecs/components/sprite_component.h>

#include <memory>
#include <filesystem>
#include <iostream>

int main()
{
  std::cout << std::filesystem::current_path() << '\n';
  auto game = komodo::core::Game();
  auto entity = komodo::core::ecs::entities::Entity::create(game);
  auto system = game.createRender2DSystem();
  entity->setRender2DSystem(system);
  auto component = std::make_shared<komodo::core::ecs::components::SpriteComponent>(std::string("build/assets/player.png"));
  entity->addComponent(std::dynamic_pointer_cast<komodo::core::ecs::components::Drawable2DComponent>(component));
  game.run();

  return 0;
}
