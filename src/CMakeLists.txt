file(GLOB_RECURSE KOMODO_SRC_FILES "./komodo/*.cpp")
add_executable(example main.cpp ${KOMODO_SRC_FILES})
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
