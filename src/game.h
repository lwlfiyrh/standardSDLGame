#ifndef GAME_H
#include <SDL.h>
#define GAME_H

#define skeleton_IMAGE_PATH IMAGES_PATH"/Character_animation/monsters_idle/skeleton2/v2/skeleton2_v2_1.png"
#define Tileset_IMAGE_PATH IMAGES_PATH"/character and tileset/Dungeon_Tileset.png"
#define WINDOW_WIDTH 720
#define WINDOW_HEIGHT 720

#define PLAYER_SIZE 64

#define TARGET_FPS 60

typedef struct
{
    int x,y;
    SDL_Rect srcRect;
}Player;
extern Player player;
#endif