cmake_minimum_required(VERSION 3.4...3.20 FATAL_ERROR)

set(PROJECT_NAME my_game_engine)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} src/main.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(deps/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(deps/glad)
target_link_libraries(${PROJECT_NAME} glad) 