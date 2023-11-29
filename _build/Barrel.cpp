#include "Barrel.h"

Barrel::Barrel() : Enemy()
{
	speed = BARREL_SPEED;
	radius = 15.0f;
	barrelCount++;
	barrelTime = 0;

}


Barrel::Barrel(float x, float y) : Enemy(x, y)
{
	speed = BARREL_SPEED;
	radius = 15.0f;
	barrelCount++;
	barrelTime = 0;
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
	barrelTime++;
}

int Barrel::barrelCount = 0;