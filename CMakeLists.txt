cmake_minimum_required(VERSION 3.0)
project(my_game)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(my_game main.c)
target_link_libraries(my_game ${SDL2_LIBRARIES})
