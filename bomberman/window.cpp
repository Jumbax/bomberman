#pragma once
#include "window.h"

Window::Window::Window()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    }
    
    sdl_window = SDL_CreateWindow("SDL is active!", 100, 100, 512, 512, 0);
    if (!sdl_window)
    {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        SDL_Quit();
    }

    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!sdl_renderer)
    {
        SDL_Log("Unable to create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(sdl_window);
        SDL_Quit();
    }
}

void Window::Window::Update()
{
    SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);
    SDL_RenderClear(sdl_renderer);


    for (Texture::Texture* texture : textures)
    {
        if (texture)
        {
            SDL_Rect target_rect = { static_cast<int>(texture->position.x), static_cast<int>(texture->position.y), texture->width, texture->height };
            SDL_RenderCopy(sdl_renderer, texture->sdl_texture, NULL, &target_rect);
        }
    }

    SDL_RenderPresent(sdl_renderer);
}