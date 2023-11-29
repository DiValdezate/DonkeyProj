#pragma once
#include "Enemy.h"


#define BARREL_SPEED 10

class Barrel : public Enemy
{
public:
	static int barrelCount;
	int barrelTime;

public:
	Barrel(float x, float y);
	Barrel();

	void Move() override;



};
