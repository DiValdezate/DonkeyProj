#include "Player.h"


Player::Player()
{
	lives = 3;
	alive = true;
	speed = { 0 };
	position = { 0 };
	texture = { 0 };	
	rotation = 0.0f;
	moving = false;
	hitBox.width = 10;
	hitBox.height = 15;
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

void Player::SetHitBox(float x, float y, float width, float height)
{
	this->hitBox.x = x;
	this->hitBox.y = y;
	this->hitBox.width = width;
	this->hitBox.height = height;
}


void Player::UpdateHitBox()
{
	this->hitBox.x = position.x - hitBox.width/2;
	this->hitBox.y = position.y - hitBox.height/2;
}

void Player::Move(KeyboardKey key)
{
	switch (key)
	{
	case KEY_RIGHT:
		position.x += PLAYER_MAX_SPEED;
			break;
	case KEY_LEFT:
		position.x -= PLAYER_MAX_SPEED;
	}
	
}