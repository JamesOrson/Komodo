#pragma once

#include <komodo/core/game.h>
#include <memory>

namespace komodo::core::ecs::entities
{
    class Entity
    {
    public:
#pragma region Constructors
        Entity(std::weak_ptr<Game> game);
#pragma endregion

        ~Entity();

#pragma region Static Members
        static unsigned int nextId;
#pragma endregion

#pragma region Accessors
        /*TODO: Waiting on Component implementation
        std::vector<Components> getComponents() const;*/
        std::weak_ptr<Game> getGame() const;
        unsigned int getId() const;
        bool getIsEnabled() const;
        /*TODO: Waiting on Vector3 implementation
        Vector3 getPosition() const;
        Vector3 getRotation() const;
        Vector3 getScale() const;*/
#pragma endregion

#pragma region Mutators
        void setIsEnabled(bool value);
        /*TODO: Waiting on Vector3 implementation
        void setPosition(Vector3 value);
        void setRotation(Vector3 value);
        void setScale(Vector3 value);*/
#pragma endregion

#pragma region Member Methods
        /*TODO: Waiting on Component implementation
        bool addComponent(std::weak_ptr<Component> component);*/
        bool clearComponents();
        /*TODO: Waiting on Matrix implementation
        Matrix getRotationMatrix() const;*/
        /*TODO: Waiting on Quaternion implementation
        Matrix getRotationQuaternion() const;*/
        /*TODO: Waiting on Component implementation
        bool removeComponent(std::weak_ptr<Component> component);
        bool removeComponent(unsigned int componentId);*/
#pragma endregion
    private:
#pragma region Members
        /*TODO: Waiting on Component implementation
        std::vector<std::shared_ptr<Component>> components;*/
        std::weak_ptr<Game> game;
        unsigned int id;
        bool isEnabled;
        /*TODO: Waiting on System implementation
        std::weak_ptr<PhysicsSystem> physicsSystem;
        std::weak_ptr<Render2DSystem> render2DSystem;
        std::weak_ptr<Render3DSystem> render3DSystem;
        */
        /*TODO: Waiting on Vector3 implementation
        Vector3 position;
        Vector3 rotation;
        Vector3 scale;*/
#pragma endregion
    };
} // namespace komodo::core