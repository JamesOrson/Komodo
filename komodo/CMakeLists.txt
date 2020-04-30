file(GLOB SRC_SYSTEM_FILES "src/komodo/core/ecs/systems/*.cpp")
file(GLOB SRC_ENTITY_FILES "src/komodo/core/ecs/entities/*.cpp")
file(GLOB SRC_COMPONENT_FILES "src/komodo/core/ecs/components/*.cpp")

#message(WARNING ${SRC_SYSTEM_FILES})

add_library(
    komodo
    "src/komodo/core/game.cpp"
    ${SRC_SYSTEM_FILES}
    ${SRC_ENTITY_FILES}
    ${SRC_COMPONENT_FILES}
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
