file(GLOB SRC_ENTITY_FILES "src/komodo/core/ecs/entities/*.cpp")
file(GLOB SRC_COMPONENT_FILES "src/komodo/core/ecs/components/*.cpp")
file(GLOB SRC_SYSTEM_FILES "src/komodo/core/ecs/systems/*.cpp")

add_library(
    komodo
    "src/komodo/core/game.cpp"
    ${SRC_ENTITY_FILES}
    ${SRC_COMPONENT_FILES}
    ${SRC_SYSTEM_FILES}
)
target_include_directories(
  komodo
  PUBLIC
  include
)

target_link_libraries(
  komodo
  PUBLIC
  project_options
  project_warnings
  spdlog
  sfml-audio
  sfml-network
  sfml-graphics
  sfml-window
  sfml-system
)
