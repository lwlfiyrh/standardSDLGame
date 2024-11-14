#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

void start_game();

int SDL_main(int argc, char* argv[]) 
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);

    start_game();
    
    IMG_Quit();
    SDL_Quit();
    printf("SDL normal exit\n");
    return 0;
}