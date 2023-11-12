#include "Brick.h"

Brick::Brick(int x, int y)
{
	position.x = x;
	position.y = y;

	hitBox.width = 10.0f;
	hitBox.height = 5.0f;

	hitBox.x = x - (hitBox.width / 2);
	hitBox.y = y - (hitBox.height / 2);	
}