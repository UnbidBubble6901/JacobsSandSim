cmake_minimum_required(VERSION 3.15)
project(jacob_sand_sim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(BUILD_SHARED_LIBS OFF)

find_package(raylib REQUIRED)

file(GLOB SRC_FILES src/*.cpp)

add_executable(jacob_sand_sim ${SRC_FILES})

target_link_libraries(jacob_sand_sim PRIVATE raylib)

target_link_options(jacob_sand_sim PRIVATE -static -static-libgcc -static-libstdc++)

# Copy raylib DLL after build
add_custom_command(TARGET jacob_sand_sim POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "C:/msys64/mingw64/bin/libraylib.dll"
    $<TARGET_FILE_DIR:jacob_sand_sim>
)