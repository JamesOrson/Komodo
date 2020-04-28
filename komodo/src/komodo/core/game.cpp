#include <komodo/core/game.h>

#include <iostream>
#include <spdlog/spdlog.h>

namespace komodo::core
{
#pragma region Constructors
  Game::Game()
  {
    // this->graphicsManager =
    // std::make_shared<GraphicsManager>(...params...);
    // this->graphicsManager->isMouseVisible = true;

    // this->content = std::make_shared<ContentManager>(...params...);

    this->behaviorSystem = std::make_shared<komodo::core::ecs::systems::BehaviorSystem>();
    // this->cameraSystem = std::make_shared<CameraSystem>(...params...);
    // this->physicsSystems =
    // std::make_shared<PhysicsSystem>(...params...); this->soundSystem =
    // std::make_shared<SoundSystem>(...params...);

    // this->render2DSystems =
    // std::make_shared<std::vector<Render2DSystem>>(); this->render3DSystems
    // = std::make_shared<std::vector<Render3DSystem>>();
  }
#pragma endregion

  Game::~Game()
  {
    spdlog::info("Clock: {}", this->clock.use_count());
  }

#pragma region Static Members
  // Game::ContentManager contentManager = ???
#pragma endregion

#pragma region Member Methods
  void Game::draw([[maybe_unused]] float dt, sf::Color clearColor)
  {
    // Clears the screen for next set of draws
    this->window->clear(clearColor);
    {
      // Draw components
      sf::CircleShape shape(50.0f);
      auto windowSize = this->window->getSize();
      shape.setPosition(
        windowSize.x / 2.0f - 50.0f, windowSize.y / 2.0f - 50.0f);
      shape.setFillColor(sf::Color(150u, 50u, 250u));

      // set a 10-pixel wide orange outline
      shape.setOutlineThickness(10.0f);
      shape.setOutlineColor(sf::Color(250u, 150u, 100u));

      this->window->draw(shape);
    }

    // Blits the frame to the window
    this->window->display();
  };

  void Game::exit(){};

  void Game::initialize()
  {
    this->clock = std::make_shared<sf::Clock>();
    this->window = std::make_shared<sf::RenderWindow>(
      sf::VideoMode(800u, 600u), "Komodo", sf::Style::Default);
  };

  void Game::run()
  {
    this->initialize();

    auto drawStart = this->clock->getElapsedTime();
    auto updateStart = this->clock->getElapsedTime();
    while (!this->shouldClose)
    {
      auto updateDelta = this->clock->getElapsedTime() - updateStart;
      float dt = updateDelta.asSeconds();
      this->update(dt);
      updateStart = this->clock->getElapsedTime();
      auto drawDelta = this->clock->getElapsedTime() - drawStart;

      dt = drawDelta.asSeconds();
      this->framesPerSecond = 1.0f / dt;
      this->draw(dt);
      drawStart = this->clock->getElapsedTime();
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

    this->behaviorSystem->update(dt);
  }
#pragma endregion

#pragma region Accessors
  std::weak_ptr<komodo::core::ecs::systems::BehaviorSystem> Game::getBehaviorSystem() const
  {
    return this->behaviorSystem;
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
} // namespace komodo::core