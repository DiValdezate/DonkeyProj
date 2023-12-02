#include "Cake.h"

Cake::Cake()
{
	position = { 700, 750 };
	speed = CAKE_SPEED;
	cakeCount++;

}

void Cake::Move()
{
	position.x -= speed;
}

int Cake::cakeCount = 0;