cmake_minimum_required(VERSION 3.15)
project(raylib_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(raylib REQUIRED)

file(GLOB SRC_FILES src/*.cpp)

add_executable(raylib_game ${SRC_FILES})

target_link_libraries(raylib_game raylib)