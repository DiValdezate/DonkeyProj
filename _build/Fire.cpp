#include "Fire.h"

Fire::Fire()
{
	SetPosition(200.0f, 400.0f);
	
}
void Fire::Move()
{
	float x = GetPosition().x;
	float y = GetPosition().y;

	if(x < GetScreenWidth())
		SetPosition(x + FIRE_SPD, y);

	if (x > GetScreenWidth())
		SetPosition(x - FIRE_SPD, y);
}