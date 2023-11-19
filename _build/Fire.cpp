#include "Fire.h"
#include <iostream>

Fire::Fire()
{
	SetPosition(200.0f, 400.0f);
	
}
void Fire::Move()
{
	std::cout << "I'm fire, i'm moving";
	float x = GetPosition().x;
	float y = GetPosition().y;

	if(x < GetScreenWidth())
		SetPosition(x + FIRE_SPD, y);

	if (x > GetScreenWidth())
		SetPosition(x - FIRE_SPD, y);
}