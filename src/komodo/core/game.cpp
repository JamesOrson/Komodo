#include <komodo/core/game.h>

#include <iostream>
#include <spdlog/spdlog.h>

namespace komodo::core
{
    #pragma region Constructors
    Game::Game()
    {
        //this->graphicsManager = std::make_shared<GraphicsManager>(...params...);
        //this->graphicsManager->isMouseVisible = true;

        //this->content = std::make_shared<ContentManager>(...params...);

        //this->behaviorSystem = std::make_shared<BehaviorSystem>(...params...);
        //this->cameraSystem = std::make_shared<CameraSystem>(...params...);
        //this->physicsSystems = std::make_shared<PhysicsSystem>(...params...);
        //this->soundSystem = std::make_shared<SoundSystem>(...params...);

        //this->render2DSystems = std::make_shared<std::vector<Render2DSystem>>();
        //this->render3DSystems = std::make_shared<std::vector<Render3DSystem>>();
    }
    #pragma endregion

    Game::~Game()
    {
    }

    #pragma region Static Members
    //Game::ContentManager contentManager = ???
    #pragma endregion

    #pragma region Accessors
    //weak_ptr<BehaviorSystem> Game::getBehaviorSystem() const
    // {
    // }

    //weak_ptr<CameraSystem> Game::getCameraSystem() const
    // {
    // }

    //weak_ptr<Shader> Game::getDefaultSpriteShader() const
    // {
    // }
    
    float Game::getFramesPerSecond() const
    {
        return this->framesPerSecond;
    }

    //weak_ptr<GraphicsManager> getGraphicsManager() const
    // {
    // }

    bool Game::getIsActive() const
    {
        return this->isActive;
    }
    //vector<PhysicsSystem> getPhysicsSystem() const
    // {
    // }

    //vector<Render2DSystem> getRender2DSystem() const
    // {
    // }

    //vector<Render3DSystem> getRender3DSystem() const
    // {
    // }

    std::string Game::getScreenDeviceName() const
    {
        return this->screenDeviceName;
    }

    //SoundSystem* Game::getSoundSystem() const
    // {
    // }

    std::string Game::getTitle() const
    {
        return this->title;
    }
    #pragma endregion

    #pragma region Mutators
    // void Game::setDefaultSpriteShader(Shader value)
    // {
    // }

    void Game::setIsActive(bool value)
    {
        this->isActive = value;
    }

    void Game::setTitle(std::string value)
    {
        this->title = value;
    }

    #pragma endregion

    #pragma region Member Methods
    void Game::draw(delta dt/*, Color clearColor = Color::white*/)
    {
        spdlog::info("FPS: {}", this->getFramesPerSecond());
        spdlog::info("Delta (draw): {} seconds", dt.count());
    };
    
    void Game::exit()
    {
    };

    void Game::initialize()
    {
    };

    void Game::run()
    {
        this->initialize();

        auto drawStart = std::chrono::steady_clock::now();
        auto updateStart = std::chrono::steady_clock::now();
        while (true)
        {
            delta drawDelta = std::chrono::steady_clock::now() - drawStart;
            auto count = drawDelta.count();
            this->framesPerSecond = 1.0f / count;
            this->draw(drawDelta);
            drawStart = std::chrono::steady_clock::now();
            
            delta updateDelta = std::chrono::steady_clock::now() - updateStart;
            this->update(updateDelta);
            updateStart = std::chrono::steady_clock::now();
        }
    };

    void Game::update(delta dt)
    {
        spdlog::info("Delta (update) seconds: {}", dt.count());
    }
    #pragma endregion
}
