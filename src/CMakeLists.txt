set(CMAKE_C_STANDARD 23)

add_executable(game main.c game.c input.c)

target_compile_definitions(game PRIVATE IMAGES_PATH="${IMAGES_PATH}")
target_link_libraries(game SDL2main SDL2 SDL2_image)