#pragma once

#include <komodo/core/ecs/entities/entity.h>
#include <komodo/core/game.h>
#include <memory>
#include <unordered_map>
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
    System();
#pragma endregion

    virtual ~System();

#pragma region Accessors
    std::unordered_map<unsigned int, std::shared_ptr<komodo::core::ecs::entities::Entity>> getEntities() const;
#pragma endregion

#pragma region Member Methods
    virtual bool addEntity(std::shared_ptr<komodo::core::ecs::entities::Entity> entityToAdd) = 0;
    virtual void clearEntities();
    virtual void initialize() = 0;
    virtual bool removeEntity(const std::weak_ptr<komodo::core::ecs::entities::Entity> entityToRemove);
    virtual bool removeEntity(const unsigned int entityId);
#pragma endregion

protected:
#pragma region Members
    std::unordered_map<unsigned int, std::shared_ptr<komodo::core::ecs::entities::Entity>> entities;
    bool isInitialized;
#pragma endregion
  };
} // namespace komodo::core::ecs::systems