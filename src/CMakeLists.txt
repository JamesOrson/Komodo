file(GLOB SRC_COMPONENT_FILES "komodo/core/ecs/components/*.cpp")
file(GLOB SRC_ENTITY_FILES "komodo/core/ecs/entities/*.cpp")

add_executable(
    example
    main.cpp
    "komodo/core/game.cpp"
    ${SRC_ENTITY_FILES}
    ${SRC_COMPONENT_FILES}
)
target_include_directories(
  example
  PUBLIC
  include
)

target_link_libraries(
  example
  PRIVATE
  project_options
  project_warnings
  spdlog
  sfml-audio
  sfml-network
  sfml-graphics
  sfml-window
  sfml-system
)
