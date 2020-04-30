add_executable(
  circle
  main.cpp
)

target_link_libraries(
  circle
  komodo
)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})