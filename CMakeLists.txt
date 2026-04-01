cmake_minimum_required(VERSION 4.0)
project(
  Alchemist
  LANGUAGES C CXX
  VERSION 1.0.0
)

configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/src/Alchemist/Config.h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/include/Alchemist/Config.h"
)

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/FetchDependencies.cmake")

add_library(Alchemist SHARED)
target_sources(
  Alchemist
  PRIVATE
    "src/Alchemist.cpp"

    "src/Alchemist/Core/Log.cpp"
)
target_include_directories(
  Alchemist
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_BINARY_DIR}/include"
)
target_link_libraries(
  Alchemist
  PRIVATE
    SDL3::SDL3
    spdlog::spdlog
)

add_subdirectory(example)

