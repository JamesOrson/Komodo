#include <komodo/core/game.h>

namespace komodo::core
{
#pragma region Constructors
  Game::Game()
  {
    // this->graphicsManager =
    // std::make_shared<GraphicsManager>(...params...);
    // this->graphicsManager->isMouseVisible = true;

    // this->content = std::make_shared<ContentManager>(...params...);

    this->behaviorSystem =
      std::make_unique<komodo::core::ecs::systems::BehaviorSystem>();
    // this->cameraSystem = std::make_shared<CameraSystem>(...params...);
    // this->physicsSystems =
    // std::make_shared<PhysicsSystem>(...params...); this->soundSystem =
    // std::make_shared<SoundSystem>(...params...);

    instance = this;
  }
#pragma endregion

  Game::~Game() {}

#pragma region Static Members
  // Game::ContentManager contentManager = ???
  Game* Game::instance;
#pragma endregion

#pragma region Member Methods
  std::shared_ptr<komodo::core::ecs::systems::Render2DSystem>
  Game::createRender2DSystem()
  {
    auto system =
      std::make_shared<komodo::core::ecs::systems::Render2DSystem>();
    this->render2DSystems.push_back(system);
    return system;
  }

  void Game::draw([[maybe_unused]] float dt, sf::Color clearColor)
  {
    spdlog::info("FPS: {}", this->framesPerSecond);
    // Clears the screen for next set of draws
    this->window->clear(clearColor);

    for (auto &system : this->render2DSystems)
    {
      system->draw(dt);
    }

    // Blits the frame to the window
    this->window->display();
  };

  void Game::exit(){};

  void Game::initialize()
  {
    this->clock = std::make_unique<sf::Clock>();
    this->window = std::make_unique<sf::RenderWindow>(
      sf::VideoMode(800u, 600u), "Komodo", sf::Style::Default);

    this->behaviorSystem->initialize();
    for (auto &renderSystem : this->render2DSystems)
    {
      renderSystem->initialize();
    }
  };

  void Game::run()
  {
    this->initialize();

    auto drawStart = this->clock->getElapsedTime();
    auto drawEnd = this->clock->getElapsedTime();
    auto updateStart = this->clock->getElapsedTime();
    auto updateEnd = this->clock->getElapsedTime();
    while (!this->shouldClose)
    {
      updateStart = this->clock->getElapsedTime();
      auto updateDelta = updateStart - updateEnd;
      float dt = updateDelta.asSeconds();
      this->update(dt);
      updateEnd = this->clock->getElapsedTime();
      
      drawStart = this->clock->getElapsedTime();
      auto drawDelta = drawStart - drawEnd;
      dt = drawDelta.asSeconds();
      this->draw(dt);
      drawEnd = this->clock->getElapsedTime();
      this->framesPerSecond = 1.0f / (drawEnd - updateStart).asSeconds();
    }
    this->window->close();
  };

  void Game::update([[maybe_unused]] float dt)
  {
    // check all the window's events that were triggered since the last
    // iteration of the loop
    sf::Event event;
    while (this->window->pollEvent(event))
    {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
      {
        this->shouldClose = true;
      }
    }

    this->behaviorSystem->preUpdate(dt);

    this->behaviorSystem->update(dt);

    this->behaviorSystem->postUpdate(dt);
  }
#pragma endregion

#pragma region Accessors
  komodo::core::ecs::systems::BehaviorSystem &Game::getBehaviorSystem()
  {
    return *this->behaviorSystem;
  }

  // weak_ptr<CameraSystem> Game::getCameraSystem() const
  // {
  // }

  // weak_ptr<Shader> Game::getDefaultSpriteShader() const
  // {
  // }

  float Game::getFramesPerSecond() const
  {
    return this->framesPerSecond;
  }

  // weak_ptr<GraphicsManager> getGraphicsManager() const
  // {
  // }

  bool Game::getIsActive() const
  {
    return this->isActive;
  }
  // vector<PhysicsSystem> getPhysicsSystem() const
  // {
  // }

  // vector<Render2DSystem> getRender2DSystem() const
  // {
  // }

  // vector<Render3DSystem> getRender3DSystem() const
  // {
  // }

  std::string Game::getScreenDeviceName() const
  {
    return this->screenDeviceName;
  }

  // SoundSystem* Game::getSoundSystem() const
  // {
  // }

  std::string Game::getTitle() const
  {
    return this->title;
  }

  sf::RenderWindow &Game::getWindow() const
  {
    return *this->window;
  }
#pragma endregion

#pragma region Mutators
  // void Game::setDefaultSpriteShader(Shader value)
  // {
  // }

  void Game::setTitle(std::string value)
  {
    this->title = value;
  }
#pragma endregion

#pragma region Static Member Methods
  Game &Game::getInstance()
  {
    return *instance;
  }
#pragma endregion
} // namespace komodo::core