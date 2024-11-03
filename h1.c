#include <stdio.h>
#include <SDL.h>
int SDL_main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Quit();
    printf("SDL_main()");
    return 0;
}