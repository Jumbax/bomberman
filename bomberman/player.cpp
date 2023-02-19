#include "player.h"

Player::Player::Player()
{
	position = Vec2::Vec2(0, 0);
	number_of_lifes = 1;
	speed = 1;
	number_of_bombs =1;
	score = 0;
}

void Player::Player::Update()
{
	texture->position = position;
}