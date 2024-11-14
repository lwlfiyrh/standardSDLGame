cmake_minimum_required(VERSION 3.15)

project(BOUTCACHOT VERSION 0.1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../)

set(SDL_DIR "${CMAKE_SOURCE_DIR}/SDL/SDL2-2.30.8")
set(SDL_IMAGE "${CMAKE_SOURCE_DIR}/SDL/SDL2_image-2.8.2")
set(SDL_TTF "${CMAKE_SOURCE_DIR}/SDL/SDL2_ttf-2.0.18")
set(SDL_MIXER "${CMAKE_SOURCE_DIR}/SDL/SDL2_mixer-2.0.4")

set(CMAKE_PREFIX_PATH ${SDL_DIR} ${SDL_IMAGE} )

include_directories(${SDL_DIR}/include)
link_directories(${SDL_DIR}/lib/x64)

include_directories(${SDL_IMAGE}/include)
link_directories(${SDL_IMAGE}/lib)

set(IMAGES_PATH "${CMAKE_SOURCE_DIR}/resources/images/2D Pixel Dungeon Asset Pack")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_subdirectory(src)