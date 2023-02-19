#include "bomb.h"

Bomb::Bomb::Bomb(Vec2::Vec2 in_position, unsigned int in_range, unsigned int in_cooldown)
{
	position = in_position;
	range = in_range;
	cooldown = in_cooldown;
}
