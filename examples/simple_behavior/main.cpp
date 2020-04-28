#include <komodo/core/game.h>
#include <komodo/core/ecs/entities/entity.h>
#include <memory>
#include "simple_behavior.h"

using namespace komodo::core::ecs::components;

int main(/*int argc, const char **argv*/)
{
  auto game = std::make_shared<komodo::core::Game>();
  auto entity = std::make_shared<komodo::core::ecs::entities::Entity>(game);
  auto component = new SimpleBehavior(entity);
  entity->addComponent(
    std::shared_ptr<komodo::core::ecs::components::BehaviorComponent>(component)
  );
  game->run();

  return 0;
}
