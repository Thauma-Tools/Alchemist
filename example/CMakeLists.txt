cmake_minimum_required(VERSION 4.0)
project(
  Alchemist-Example
)

add_executable(Example WIN32)
set_target_properties(
  Example
  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY
      $<TARGET_FILE_DIR:Alchemist>
)
target_sources(
  Example
  PRIVATE
    Main.cpp
)
target_link_libraries(
  Example
  PRIVATE
    Alchemist
)

add_custom_target(
  run
  COMMAND
    Example
  WORKING_DIRECTORY
    ${CMAKE_SOURCE_DIR}
)

