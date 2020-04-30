#pragma once

#include <memory>
#include <unordered_set>
#include <vector>

namespace komodo::core
{
  class Game;
}

namespace komodo::core::ecs::systems
{
  class System
  {
public:
#pragma region Constructors
    System(komodo::core::Game &game);
#pragma endregion

    virtual ~System();

#pragma region Accessors
    std::unordered_set<unsigned int> getEntities() const;
#pragma endregion

#pragma region Member Methods
    virtual bool addEntity(const unsigned int entityId) = 0;
    virtual void clearEntities();
    virtual void initialize() = 0;
    virtual bool removeEntity(const unsigned int entityId) = 0;
#pragma endregion

protected:
#pragma region Members
    std::unordered_set<unsigned int> entities;
    komodo::core::Game &game;
    bool isInitialized;
#pragma endregion
  };
} // namespace komodo::core::ecs::systems