cmake_minimum_required(VERSION 3.20)
project(tempgame)
set(CMAKE_C_STANDARD 23)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../)

set(CMAKE_PATH "D:/JOBS/C/SDL2-2.30.8")
set(CMAKE_LIBRARY_PATH ${CMAKE_PATH})
include_directories(${CMAKE_PATH}/include)
link_directories(${CMAKE_PATH}/lib/x64)

find_package(SDL2 REQUIRED)

add_executable(game h1.c)
target_link_libraries(game SDL2main SDL2)