#pragma once
#include "vec2.h"

namespace Enemy
{

	enum Enemy_Type
	{
		BAT,
		BALOON
	};

	class Enemy
	{
	public:
		Vec2::Vec2 position;
		const Enemy_Type type;

		Enemy(Vec2::Vec2 position, const Enemy_Type type);
		Enemy(const Enemy& other) = default;
		Enemy&operator=(const Enemy& other) = default;
		~Enemy() = default;
	};
}