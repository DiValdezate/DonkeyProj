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
	canMove = true;
	invincible = false;
	hitBox.width = 20;
	hitBox.height = 30;
	canJump = true;
	onLadder = false;
	ladder = NULL;
	hitTime = 0;
	invTime = 0;	
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

Rectangle Player::GetHitbox()
{
	return hitBox;
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
	this->hitBox.x = position.x - hitBox.width/2 + 10;
	this->hitBox.y = position.y - hitBox.height/2 - 10;
}

void Player::Move(KeyboardKey key)
{
	if (canMove)
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
	
	
}

void Player::SetMoving(bool value)
{
	this->canMove = value;
}

bool Player::CanMove()
{
	return canMove;
}

void Player::Hit()
{
	if(invincible == false)
		canMove = false;
}

void Player::SetInvincible(bool value)
{
	invincible = value;
	if (!value)
		invTime = 0;
}

bool Player::HitTime()
{
	hitTime++;
	if (hitTime > 180)
	{
		canMove = true;
		hitTime = 0;
		SetPosition({ 200 , 700 });
		lives--;
		return false;
	}

	return true;
}

bool Player::IsInvincible()
{
	return invincible;
}

void Player::ResetPlayer()
{
	lives = 3;
	orientation = RIGHT;
	alive = true;
	position = { 200,700 };
}