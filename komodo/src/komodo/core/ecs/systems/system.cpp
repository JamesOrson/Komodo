#include <komodo/core/ecs/entities/entity.h>
#include <komodo/core/ecs/systems/system.h>
#include <komodo/core/game.h>
#include <memory>
#include <vector>

using namespace komodo::core::ecs::entities;

namespace komodo::core::ecs::systems
{
#pragma region Constructors
  System::System()
  {
    this->isInitialized = false;
  }
#pragma endregion

  System::~System() {}

#pragma region Accessors
  std::unordered_set<unsigned int>
  System::getEntities() const
  {
    return this->entities;
  }
#pragma endregion

#pragma region Member Methods
  void System::clearEntities()
  {
    for (auto id : this->entities)
    {
      this->removeEntity(id);
    }
    this->entities.clear();
  }
#pragma endregion
} // namespace komodo::core::ecs::systems