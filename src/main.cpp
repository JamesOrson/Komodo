#include <komodo/core/game.h>
#include <komodo/core/ecs/entities/entity.h>
#include <memory>

int main(/*int argc, const char **argv*/)
{
    auto game = std::make_shared<komodo::core::Game>();
    auto entity = komodo::core::ecs::entities::Entity(game);
    entity = komodo::core::ecs::entities::Entity(game);
    game->run();

    return 0;
}
