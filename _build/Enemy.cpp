#include "Enemy.h"

Enemy::Enemy()
{
	position = { 0 };
	alive = true;
	texture = { 0 };
	speed = 0;
	enemyCount++;
	radius = 20.0f;

	if (enemyCount % 2 == 0)
		lookingRight = false;
	else
	{
		lookingRight = true;
	}

}

Enemy::Enemy(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
	alive = true;
	texture = { 0 };
	speed = 0;
	enemyCount++;
	radius = 20.0f;


	if (enemyCount % 2 == 0)
		lookingRight = false;
	else
	{
		lookingRight = true;
	}
	
}

Enemy::~Enemy(){}

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

int Enemy::GetOrientation()
{
	return lookingRight;
}

float Enemy::GetRadius()
{
	return radius;
}

bool Enemy::IsAlive()
{
	return alive;
}

void Enemy::Move() {}

void Enemy::Turn()
{
	if (lookingRight)
		lookingRight = false;
	else
		lookingRight = true;
}


int Enemy::enemyCount = 0;