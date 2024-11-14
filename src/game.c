#include <SDL.h>
#include <SDL_image.h>
#include "game.h"

void player_input(Player* player);

void start_game()
{
    int running = 1;
    SDL_Event event;
    Player player;
    //创建窗口
    SDL_Window* window = SDL_CreateWindow("BOUTCACHOT", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    //加载背景和角色
    SDL_Texture* backgroundTexture = IMG_LoadTexture(renderer, Tileset_IMAGE_PATH);
    SDL_Texture* texture = IMG_LoadTexture(renderer, skeleton_IMAGE_PATH);
    //初始化角色位置
    player.x = (WINDOW_WIDTH - PLAYER_SIZE)/2;
    player.y = (WINDOW_HEIGHT - PLAYER_SIZE)/2;
/*
    player.srcRect.x = 0;
    player.srcRect.y = 0;
    player.srcRect.w = PLAYER_SIZE;
    player.srcRect.h = PLAYER_SIZE;
*/
    //渲染参数并设置角色大小
    SDL_Rect destRect;
    destRect.w = PLAYER_SIZE;
    destRect.h = PLAYER_SIZE;

    SDL_Rect backgroundSrcRect;
    backgroundSrcRect.x = 0;
    backgroundSrcRect.y = 0;
    backgroundSrcRect.w = 95;
    backgroundSrcRect.h = 80;
    //帧率控制
    Uint32 frameStart;
    float frameTime;
    const float frameDelay = 1000.0f / TARGET_FPS;

    while (running) 
    {
        //获取时间
        frameStart = SDL_GetTicks();
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT) 
            {
                running = 0;
            }
        }
        //处理输入
        player_input(&player);
        //更新角色位置
        destRect.x = player.x;
        destRect.y = player.y;
        //渲染
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        //渲染背景
        SDL_Rect backgroundRect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
        SDL_RenderCopy(renderer, backgroundTexture, &backgroundSrcRect, &backgroundRect);
        //渲染角色
        SDL_RenderCopy(renderer,texture,NULL,&destRect);
        SDL_RenderPresent(renderer);
        //控制帧率
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < frameDelay) 
        {
            //限制帧率
            SDL_Delay(frameDelay - frameTime);
        }
    }
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);  
}