add_executable(
  sprite
  main.cpp
)

target_link_libraries(
  sprite
  komodo
)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})