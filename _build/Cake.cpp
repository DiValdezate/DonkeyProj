#include "Cake.h"

Cake::Cake()
{
	position = { 700, 750 };
	cakeTime = 0;
	radius = 15.0f;
	speed = CAKE_SPEED;
	cakeCount++;

}

void Cake::Move()
{
	position.x -= speed;
	cakeTime++;
}

int Cake::cakeCount = 0;