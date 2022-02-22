cmake_minimum_required(VERSION 3.3)
project(cube-game)

file(GLOB_RECURSE app_src CONFIGURE_DEPENDS "./src/*.cpp")

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_definitions(PLATFORM_LINUX)

add_executable(App ${app_src})

add_custom_command(TARGET App
									 POST_BUILD
									 COMMAND ${CMAKE_COMMAND} -E copy_directory
									 ${CMAKE_SOURCE_DIR}/Assets
									 ${CMAKE_CURRENT_BINARY_DIR}/Assets)

add_custom_command(TARGET App
									 POST_BUILD
									 COMMAND ${CMAKE_COMMAND} -E copy
									 ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
									 ${CMAKE_SOURCE_DIR}/compile_commands.json)

# --------- GLFW AND OPENGL ----------

add_subdirectory(./lib/glfw/)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

find_package(OpenGL REQUIRED)
target_link_libraries(App PUBLIC OpenGL::GL)

target_include_directories(App PUBLIC ./lib/glfw/include/)
target_link_libraries(App PUBLIC glfw)


# ---------- GLAD ----------

add_subdirectory(./lib/glad/)
target_include_directories(App PUBLIC ./lib/glad/include/)
target_link_libraries(App PUBLIC glad)

# ---------- SPDLOG ----------

add_subdirectory(./lib/spdlog/)
target_include_directories(App PUBLIC ./lib/spdlog/include/)
target_link_libraries(App PUBLIC spdlog)

# ---------- GLM ----------

target_include_directories(App PUBLIC ./lib/glm/)

# ---------- STB ----------

target_include_directories(App PUBLIC ./lib/stb/)
