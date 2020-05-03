#include <komodo/core/ecs/systems/system.h>

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
  std::unordered_set<unsigned int> System::getEntities() const
  {
    return this->entities;
  }
#pragma endregion

#pragma region Member Methods
  void System::clearEntities()
  {
    while (!this->entities.empty())
    {
      auto id = this->entities.begin();
      this->removeEntity(*id);
    }
    this->entities.clear();
  }
#pragma endregion
} // namespace komodo::core::ecs::systems