#include "texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture::Texture(const char* path, int in_width, int in_height, SDL_Window* window, SDL_Renderer* renderer)
{
    width = in_width;
    height = in_height;

    int tex_width;
    int tex_height;
    int tex_channels;
    unsigned char* pixels = stbi_load(path, &tex_width, &tex_height, &tex_channels, 4);
    if (!pixels)
    {
        SDL_Log("Unable to open image");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    sdl_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, tex_width, tex_height);
    if (!sdl_texture)
    {
        SDL_Log("Unable to create texture: %s", SDL_GetError());
        free(pixels);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    SDL_UpdateTexture(sdl_texture, NULL, pixels, tex_width * tex_channels);
    free(pixels);
}