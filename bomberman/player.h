#pragma once
#include "vec2.h"
#include "texture.h"

namespace Player
{
	class Player 
	{
	public:
		Vec2::Vec2 position;
		Texture::Texture* texture;
		unsigned int number_of_lifes;
		unsigned int number_of_bombs;
		unsigned int score;
		unsigned int speed;

		Player();
		Player(const Player& other) = default;
		Player& operator=(const Player& other) = default;
		~Player() = default;
		void Update();
	};
}

