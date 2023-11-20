#include "Fire.h"
#include <iostream>

Fire::Fire() : Enemy()
{
	speed = FIRE_SPD;

	
}


Fire::Fire(float x, float y) : Enemy(x, y)
{
	speed = FIRE_SPD;
	
}


void Fire::Move()
{
	switch (lookingRight)
	{
	case 0:
		position.x -= speed;
		break;
	case 1:
		position.x += speed;
		break;
	}

	if (position.x == GetScreenWidth())
		lookingRight = false;

	if (position.x == 0)
		lookingRight = true;




}