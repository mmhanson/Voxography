cmake_minimum_required(VERSION 3.0)
project(cubes)

FILE(GLOB SOURCE_FILES src/*.c)
set(CMAKE_CXX_FLAGS "-g -Wall")
add_definitions(--std=c99 -g -DGLEW_NO_GLU)

add_subdirectory(deps/glew/build/cmake)
include_directories(deps/glew/include)
add_subdirectory(deps/glfw)
include_directories(deps/glfw/include)
include_directories(deps/lodepng)

add_executable(cubes ${SOURCE_FILES} deps/lodepng/lodepng.c)
target_link_libraries(cubes glfw glew m)
