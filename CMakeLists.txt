cmake_minimum_required(VERSION 3.3)
project(cube-game)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_definitions(PLATFORM_LINUX)

add_executable(App ./src/main.cpp)


# --------- GLFW AND OPENGL ----------

add_subdirectory(./lib/glfw/)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

find_package(OpenGL REQUIRED)
target_link_libraries(App PUBLIC OpenGL::GL)

target_include_directories(App PUBLIC ./lib/glfw/include/)
target_link_libraries(App PUBLIC glfw)
