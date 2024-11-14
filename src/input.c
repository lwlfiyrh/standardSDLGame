#include "game.h"
#include "SDL.h"
void player_input(Player* player)
{
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    if (keystate[SDL_SCANCODE_LEFT]) 
    {
        player->x -= 1;
    }
    if (keystate[SDL_SCANCODE_RIGHT]) 
    {
        player->x += 1;
    }
    if (keystate[SDL_SCANCODE_UP]) 
    {
        player->y -= 1;
    }
    if (keystate[SDL_SCANCODE_DOWN]) 
    {
        player->y += 1;
    }
    if (player->x < 0) player->x = 0;
    if (player->x > WINDOW_WIDTH - PLAYER_SIZE) player->x = WINDOW_WIDTH - PLAYER_SIZE;
    if (player->y < 0) player->y = 0;
    if (player->y > WINDOW_HEIGHT - PLAYER_SIZE) player->y = WINDOW_HEIGHT - PLAYER_SIZE;
}