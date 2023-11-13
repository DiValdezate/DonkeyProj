#include "Brick.h"

Brick::Brick(float x, float y)
{
	position.x = x;
	position.y = y;

	hitBox.width = 50.0f;
	hitBox.height = 25.0f;

	hitBox.x = x - (hitBox.width / 2);
	hitBox.y = y - (hitBox.height / 2);	
}

Brick::Brick()
{
	position.x = 400;
	position.y = 300;

	hitBox.width = 50.0f;
	hitBox.height = 25.0f;

	hitBox.x = 400 - (hitBox.width / 2);
	hitBox.y = 300 - (hitBox.height / 2);

}