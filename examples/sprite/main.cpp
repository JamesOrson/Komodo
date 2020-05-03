#include <komodo/core/game.h>
#include <komodo/core/ecs/entities/entity.h>
#include <komodo/core/ecs/components/sprite_component.h>

#include <memory>
#include <filesystem>
#include <iostream>

void addSprite(std::shared_ptr<komodo::core::ecs::entities::Entity> entity)
{
  auto spriteComponent =
    std::make_shared<komodo::core::ecs::components::SpriteComponent>(
      std::string("../../assets/player.png"));
  entity->addComponent(
    std::dynamic_pointer_cast<
      komodo::core::ecs::components::Drawable2DComponent>(spriteComponent));
}

int main()
{
  std::cout << std::filesystem::current_path() << '\n';
  auto game = komodo::core::Game();
  auto entity = komodo::core::ecs::entities::Entity::create();
  auto system = game.createRender2DSystem();
  entity->setRender2DSystem(system);
  addSprite(entity);
  game.run();

  return 0;
}
