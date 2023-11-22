#include "Fire.h"
#include <iostream>

Fire::Fire() : Enemy()
{
	speed = FIRE_SPD;
	radius = 15.0f;
	fireCount++;

	if (fireCount % 2 == 0)
		lookingRight = false;
	else
	{
		lookingRight = true;
	}
	
}


Fire::Fire(float x, float y) : Enemy(x, y)
{
	speed = FIRE_SPD;
	radius = 15.0f;
	fireCount++;

	if (fireCount % 2 == 0)
		lookingRight = false;
	else
	{
		lookingRight = true;
	}
}


void Fire::Move()
{
	switch (lookingRight)
	{
	case 0:
		position.x -= speed * 0.25f;
		break;
	case 1:
		position.x += speed * 0.25f;
		break;
	}

	if (position.x == GetScreenWidth())
		lookingRight = false;

	if (position.x == 0)
		lookingRight = true;




}

int Fire::fireCount = 0;