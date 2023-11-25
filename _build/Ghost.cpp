#include "Ghost.h"

Ghost::Ghost() : Enemy()
{
	speed = GHOST_SPEED;
	radius = 15.0f;
	ghostCount++;

}


Ghost::Ghost(float x, float y) : Enemy(x, y)
{
	speed = GHOST_SPEED;
	radius = 15.0f;
	ghostCount++;
}


void Ghost::Move()
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

int Ghost::ghostCount = 0;