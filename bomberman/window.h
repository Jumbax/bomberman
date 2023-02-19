#pragma once
#include "texture.h"
#include <vector>
#include "SDL.h"

namespace Window
{
	class Window
	{
	public:
		SDL_Window* sdl_window;
		SDL_Renderer* sdl_renderer;
		std::vector<Texture::Texture*> textures;
		Window();
		Window(const Window& other) = default;
		Window& operator=(const Window& other) = default;
		~Window() = default;
		void Update();
	};
}