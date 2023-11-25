#include "Boss.h"

Boss::Boss() : Enemy()
{
	speed = BOSS_SPEED;
	radius = 35.0f;
	bossCount++;

}


Boss::Boss(float x, float y) : Enemy(x, y)
{
	speed = BOSS_SPEED;
	radius = 35.0f;
	bossCount++;
}


void Boss::Move()
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

	if (position.x == GetScreenWidth() - 150)
		lookingRight = false;

	if (position.x == 50)
		lookingRight = true;


}

int Boss::bossCount = 0;