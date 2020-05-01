#pragma once

#include <komodo/core/ecs/components/behavior_component.h>
#include <komodo/core/ecs/components/drawable_2d_component.h>

#include <memory>
#include <unordered_map>
#include <vector>

namespace komodo::core
{
  class Game;

  namespace ecs::systems
  {
    class Render2DSystem;
  } // namespace ecs::systems
} // namespace komodo::core

namespace komodo::core::ecs::entities
{
  class Entity
  {
    friend komodo::core::ecs::systems::BehaviorSystem;
    friend komodo::core::ecs::systems::Render2DSystem;

public:
#pragma region Constructors
    Entity(komodo::core::Game &game);
#pragma endregion

    ~Entity();

#pragma region Static Members
    static unsigned int nextId;
    static unsigned int emptyId;
#pragma endregion

#pragma region Accessors
    std::vector<std::shared_ptr<komodo::core::ecs::components::Component>>
    getComponents() const;
    komodo::core::Game &getGame() const;
    unsigned int getId() const;
    bool getIsEnabled() const;
    std::shared_ptr<komodo::core::ecs::systems::Render2DSystem>
    getRender2DSystem() const;
    /*TODO: Waiting on Vector3 implementation
    Vector3 getPosition() const;
    Vector3 getRotation() const;
    Vector3 getScale() const;*/
#pragma endregion

#pragma region Mutators
    void setIsEnabled(bool value);
    void setRender2DSystem(
      std::shared_ptr<komodo::core::ecs::systems::Render2DSystem> value);
    /*TODO: Waiting on Vector3 implementation
    void setPosition(Vector3 value);
    void setRotation(Vector3 value);
    void setScale(Vector3 value);*/
#pragma endregion

#pragma region Member Methods
    bool addComponent(
      std::shared_ptr<komodo::core::ecs::components::BehaviorComponent>
        component);
    bool addComponent(
      std::shared_ptr<komodo::core::ecs::components::Drawable2DComponent>
        component);
    bool clearComponents();
    /*TODO: Waiting on Matrix implementation
    Matrix getRotationMatrix() const;*/
    /*TODO: Waiting on Quaternion implementation
    Matrix getRotationQuaternion() const;*/
    bool removeComponent(unsigned int componentId);
#pragma endregion

private:
#pragma region Members
    std::vector<std::shared_ptr<komodo::core::ecs::components::Component>>
      components;
    komodo::core::Game &game;
    unsigned int id;
    bool isEnabled;
    std::shared_ptr<komodo::core::ecs::systems::Render2DSystem> render2DSystem;
    /*TODO: Waiting on System implementation
    std::weak_ptr<PhysicsSystem> physicsSystem;
    std::weak_ptr<Render3DSystem> render3DSystem;
    */
    /*TODO: Waiting on Vector3 implementation
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;*/

#pragma endregion Members

#pragma region Static Members
    static std::unordered_map<unsigned int, Entity *> entityStore;
#pragma endregion

#pragma region Static Member Methods
    static Entity *getEntity(unsigned int entityId);
#pragma endregion
  };
} // namespace komodo::core::ecs::entities