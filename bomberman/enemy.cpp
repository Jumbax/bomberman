#include "enemy.h"

Enemy::Enemy::Enemy(Vec2::Vec2 in_position, const Enemy_Type in_type) : type(in_type)
{
	position = in_position;
}