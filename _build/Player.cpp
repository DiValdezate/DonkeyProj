#include "Player.h"


Player::Player()
{
	lives = 3;
	alive = true;
	speed = { 0 };
	position = { 0 };
	texture = { 0 };
	radius = 15.0f;
	rotation = 0.0f;
	moving = false;
};

void Player::SetLives(int lives)
{
	this->lives = lives;
}


int Player::GetLives()
{
	return lives;
}

void Player::SetPosition(Vector2 position)
{
	this->position = position;
}


Vector2 Player::GetPosition()
{
	return position;
}


void Player::SetTexture(Texture2D* texture)
{
	this->texture = *texture;
}

Texture2D Player::GetTexture()
{
	return texture;
}


void Player::Move()
{

}