add_executable(
  move_behavior
  main.cpp
)

target_link_libraries(
  move_behavior
  komodo
)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})