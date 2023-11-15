#include "Ladder.h"



Ladder::Ladder(int posX, int posY)
{
	this->position.x = posX;
	this->position.y = posY;
	SetHitBox(LADDER_WIDTH, LADDER_HEIGHT);
}

Ladder::Ladder(int posX, int posY, float width, float height)
{
	this->position.x = (float)posX;
	this->position.y = (float)posY;
	SetHitBox(width, height);
}

void Ladder::SetHitBox(float width, float height)
{
	hitBox.width = width;
	hitBox.height = height;
	hitBox.x = position.x - width / 2;
	hitBox.y = position.y - height / 2;
}