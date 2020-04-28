#include <komodo/core/ecs/entities/entity.h>
#include <komodo/core/ecs/systems/system.h>
#include <komodo/core/game.h>
#include <memory>
#include <unordered_map>
#include <vector>

using namespace komodo::core::ecs::entities;

namespace komodo::core::ecs::systems
{
#pragma region Constructors
  System::System()
  {
    this->entities = std::unordered_map<unsigned int, std::shared_ptr<Entity>>();
  }
#pragma endregion

  System::~System()
  {
  }

#pragma region Accessors
  std::unordered_map<unsigned int, std::shared_ptr<Entity>> System::getEntities() const
  {
    return this->entities;
  }
#pragma endregion

#pragma region Member Methods
  void System::clearEntities()
  {
    this->entities.clear();
  }

  bool System::removeEntity(const std::weak_ptr<Entity> entityToRemove)
  {
    if (auto entity = entityToRemove.lock())
    {
      return this->removeEntity(entity->getId());
    }
    else
    {
      return false;
    }
  }

  bool System::removeEntity(const unsigned int entityId)
  {
    if (this->entities.count(entityId) == 1)
    {
      this->entities.erase(entityId);
      return true;
    }
    else
    {
      return false;
    }
  }
#pragma endregion
} // namespace komodo::core::ecs::systems