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


}

int Boss::bossCount = 0;