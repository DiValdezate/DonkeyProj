#include "Barrel.h"

Barrel::Barrel() : Enemy()
{
	speed = BARREL_SPEED;
	radius = 15.0f;
	barrelCount++;

}


Barrel::Barrel(float x, float y) : Enemy(x, y)
{
	speed = BARREL_SPEED;
	radius = 15.0f;
	barrelCount++;
}


void Barrel::Move()
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
}

int Barrel::barrelCount = 0;