#include "Player.h"


Player::Player()
{
	lives = 3;
	orientation = RIGHT;
	alive = true;
	speed = 0;
	position = { 0 };
	texture = { 0 };	
	rotation = 0.0f;
	moving = false;
	hitBox.width = 10;
	hitBox.height = 15;
	canJump = true;
	onLadder = false;
	ladder = NULL;
	
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
	this->position.x = position.x;
	this->position.y = position.y;
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

void Player::SetSpeed(float speed)
{
	this->speed = speed;
}

float Player::GetSpeed()
{
	return speed;
}

void Player::CanJump(bool value)
{
	this->canJump = value;
}

bool Player::GetCanJump()
{
	return canJump;
}

void Player::SetOnLadder(bool value, Ladder* ladder)
{
	onLadder = value;
	this->ladder = ladder;
}

bool Player::GetOnLadder()
{
	return onLadder;
}

Orientation Player::GetOrientation()
{
	return orientation;
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
		orientation = RIGHT;
		break;
	case KEY_LEFT:		
		position.x -= PLAYER_MAX_SPEED;
		orientation = LEFT;
		break;
	case KEY_SPACE:
		if (canJump)
		{
			speed = -PLAYER_JUMP_FORCE;
			canJump = false;
		}
		break;
	case KEY_UP:
		if (onLadder)
			position.y -= PLAYER_MAX_SPEED;
		break;
	case KEY_DOWN:
		if (onLadder && position.y <= ladder->hitBox.y + ladder->hitBox.height - 20)
			position.y += PLAYER_MAX_SPEED;
		break;
	}
	
	
}