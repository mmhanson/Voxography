cmake_minimum_required(VERSION 3.0)
project(cubes)

FILE(GLOB SOURCE_FILES src/*.c)

#find_package(glfw3)

add_executable(cubes ${SOURCE_FILES})
target_link_libraries(cubes glfw)
