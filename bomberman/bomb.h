#pragma once
#include "vec2.h"

namespace Bomb
{
	class Bomb
	{
	public:
		Vec2::Vec2 position;
		unsigned int range;
		unsigned int cooldown;

		Bomb(Vec2::Vec2 position, unsigned int range, unsigned int cooldown);
		Bomb(const Bomb& other) = default;
		Bomb& operator=(const Bomb& other) = default;
		~Bomb() = default;
	};
}