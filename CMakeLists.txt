cmake_minimum_required(VERSION 3.4...3.20 FATAL_ERROR)

set(PROJECT_NAME Engine)
project(${PROJECT_NAME})

add_subdirectory(EngineCore)
add_subdirectory(EngineEditor)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT EngineEditor)