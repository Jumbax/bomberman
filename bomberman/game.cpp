#include "game.h"
#include "player.h"

Game::Game::Game()
{
	Window::Window window;
	Player::Player player;
	player.position = Vec2::Vec2(128, 128);
	player.texture = new Texture::Texture("madeline.png", 128, 128, window.sdl_window, window.sdl_renderer);
	window.textures.push_back(player.texture);

	bool running = true;
	while (running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}
		SDL_PumpEvents();
		const Uint8* keys = SDL_GetKeyboardState(NULL);
		player.position.x += keys[SDL_SCANCODE_RIGHT];
		player.position.x -= keys[SDL_SCANCODE_LEFT];
		player.position.y += keys[SDL_SCANCODE_DOWN];
		player.position.y -= keys[SDL_SCANCODE_UP];
		player.Update();
		window.Update();
	}
}