cmake_minimum_required(VERSION 3.15)

set(CMAKE_VERBOSE_MAKEFILE ON)

project(Komodo CXX)
include(cmake/StandardProjectSettings.cmake)

# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
  target_compile_features(project_options INTERFACE cxx_std_17)
else()
  target_compile_features(project_options INTERFACE cxx_std_20)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
  option(ENABLE_BUILD_WITH_TIME_TRACE "Enable -ftime-trace to generate time tracing .json files on clang" OFF)
  if (ENABLE_BUILD_WITH_TIME_TRACE)
    add_compile_definitions(project_options INTERFACE -ftime-trace)
  endif()
endif()

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# sanitizer options if supported by compiler
include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

# enable doxygen
include(cmake/Doxygen.cmake)
enable_doxygen()

# include packages
include(cmake/Packages.cmake)

# allow for static analysis options
include(cmake/StaticAnalyzers.cmake)

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)
option(ENABLE_TESTING "Enable Test Builds" ON)

# Very basic PCH example
option(ENABLE_PCH "Enable Precompiled Headers" OFF)
if (ENABLE_PCH)
  # This sets a global PCH parameter, each project will build its own PCH, which
  # is a good idea if any #define's change
  # 
  # consider breaking this out per project as necessary 
  target_precompile_headers(project_options INTERFACE <vector> <string> <map> <utility>)
endif()

add_subdirectory(komodo)
add_subdirectory(examples)

option(ENABLE_UNITY "Enable Unity builds of projects" OFF)
if (ENABLE_UNITY)
  # Add for any project you want to apply unity builds for
  set_target_properties(main PROPERTIES UNITY_BUILD ON)
endif()

