#include <komodo/core/game.h>
#include <komodo/core/ecs/entities/entity.h>
#include <komodo/core/ecs/components/text_component.h>
#include <memory>

int main(/*int argc, const char **argv*/)
{
  auto game = std::make_shared<komodo::core::Game>();
  auto entity = std::make_shared<komodo::core::ecs::entities::Entity>(game);
  auto textComponent = komodo::core::ecs::components::TextComponent(entity);
  game->run();

  return 0;
}
