#pragma once
#include "SDL.h"
#include "vec2.h"

namespace Texture
{
	class Texture
	{
	public:
		Vec2::Vec2 position;
		int width;
		int height;
		SDL_Texture* sdl_texture;
		Texture(const char* path, int width, int height, SDL_Window* window, SDL_Renderer* renderer);
		Texture(const Texture& other) = default;
		Texture& operator=(const Texture& other) = default;
		~Texture() = default;
	};
}