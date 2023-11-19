#include "Enemy.h"

Enemy::Enemy()
{
	position = { 0 };
	alive = true;
	texture = { 0 };
}

Enemy::Enemy(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
	alive = true;
	texture = { 0 };
}

void Enemy::SetPosition(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
}
Vector2 Enemy::GetPosition()
{
	return position;
}

void Enemy::SetTexture(Texture2D texture)
{
	this->texture = texture;
}
Texture2D Enemy::GetTexture()
{
	return texture;
}

bool Enemy::IsAlive()
{
	return alive;
}

