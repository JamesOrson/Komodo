#pragma once

#include <chrono>
#include <string>

typedef std::chrono::duration<float> delta;

namespace komodo::core
{
    class Game
    {
        public:
            #pragma region Constructors
            Game();
            #pragma endregion
            
            ~Game();

            #pragma region Static Members
            //static ContentManager contentManager;
            #pragma endregion

            #pragma region Accessors
            //weak_ptr<BehaviorSystem> getBehaviorSystem() const;
            //weak_ptr<CameraSystem> getCameraSystem() const;
            //weak_ptr<Shader> getDefaultSpriteShader() const;
            float getFramesPerSecond() const;
            //weak_ptr<GraphicsManager> getGraphicsManager() const;
            bool getIsActive() const;
            //vector<PhysicsSystem> getPhysicsSystem() const;
            //vector<Render2DSystem> getRender2DSystem() const;
            //vector<Render3DSystem> getRender3DSystem() const;
            std::string getScreenDeviceName() const;
            //weak_ptr<SoundSystem> getSoundSystem() const;
            std::string getTitle() const;
            #pragma endregion

            #pragma region Mutators
            //void setDefaultSpriteShader(Shader value);
            void setIsActive(bool value);
            void setTitle(std::string value);
            #pragma endregion

            #pragma region Member Methods
            
            //std::shared_ptr<PhysicsSystem> createPhysicsSystem();
            //std::shared_ptr<Render2DSystem> createRender2DSystem();
            //std::shared_ptr<Render3DSystem> createRender3DSystem();

            void draw(delta dt/*, Color clearColor = Color::white*/);
            void exit();
            void initialize();
            void run();
            void update(delta dt);

            #pragma region Event handlers
            //int addExitingEvent(const std::shared_ptr<function<bool(ExitEventArgs args)>> handler);
            //int addFocusGainedEvent(const std::shared_ptr<function<bool(FoxusGainedArgs args)>> handler);
            //int addFocusLostEvent(const std::shared_ptr<function<bool(FocusLostArgs args)>> handler);
            //int addKeyDownEvent(const std::shared_ptr<function<bool(KeyDownEventArgs args)>> handler);
            //int addScreenDeviceNameChangedEvent(const std::shared_ptr<function<bool(KeyUpArgs args)>> handler);
            //int addTextInputEvent(const std::shared_ptr<function<bool(TextInputEventArgs args)>> handler);
            //int addWindowSizeChangedEvent(const std::shared_ptr<function<bool(WindowSizeChangedEventArgs args)>> handler);
            //bool removeExitingEvent(const int handlerId);
            //bool removeFocusGainedEvent(const int handlerId);
            //bool removeFocusLostEvent(const int handlerId);
            //bool removeKeyDownEvent(const int handlerId);
            //bool removeScreenDeviceNameChangedEvent(const int handlerId);
            //bool removeTextInputEvent(const int handlerId);
            //bool removeWindowSizeChangedEvent(const int handlerId);
            #pragma endregion

            #pragma endregion Member Methods
        private:
            #pragma region Members
            //BehaviorSystem behaviorSystem;
            //CameraSystem cameraSystem;
            //Shader defaultSpriteShader;
            float framesPerSecond;
            //GraphicsManager graphicsManager;
            bool isActive;
            //vector<PhysicsSystem> physicsSystems;
            //vector<Render2DSystem> render2DSystems;
            //vector<Render2DSystem> render2DSystems;
            std::string screenDeviceName;
            //SoundSystem soundSystem;
            std::string title;

            #pragma endregion
    };
}