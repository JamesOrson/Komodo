#include <komodo/core/game.h>
#include <komodo/core/ecs/entities/entity.h>
#include <memory>
#include "simple_behavior.h"

using namespace komodo::core::ecs::components;

int main(/*int argc, const char **argv*/)
{
  auto game = komodo::core::Game();
  auto entity = komodo::core::ecs::entities::Entity(game);
  auto component = std::make_shared<SimpleBehavior>();
  entity.addComponent(component);
  game.run();

  return 0;
}
