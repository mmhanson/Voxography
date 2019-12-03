cmake_minimum_required(VERSION 3.0)
project(cubes)

FILE(GLOB SOURCE_FILES src/*.c)
#set(CMAKE_CXX_FLAGS "-g -Wall")
add_definitions(--std=c99 -g)

add_subdirectory(deps/glew/build/cmake)
include_directories(deps/glew/include)

add_executable(cubes ${SOURCE_FILES})
target_link_libraries(cubes glfw glew)
