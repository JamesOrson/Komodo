# spdlog
add_subdirectory("packages/spdlog")

# sfml
set(SFML_STATIC_LIBRARIES TRUE)
SET(CMAKE_FIND_FRAMEWORK LAST)
set(BUILD_SHARED_LIBS FALSE)
add_subdirectory("packages/SFML")

# set(SFML_DIR "packages/SFML/build")
# set(CMAKE_MODULE_PATH "../packages/SFML/build")
# set(SFML_STATIC_LIBRARIES TRUE)
# find_package(SFML 2 COMPONENTS audio network graphics window system)