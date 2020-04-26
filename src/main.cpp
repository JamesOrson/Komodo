#include <komodo/core/game.h>
#include <memory>

#include <iostream>

int main(/*int argc, const char **argv*/)
{
    auto game = komodo::core::Game();
    game.run();

    return 0;
}
