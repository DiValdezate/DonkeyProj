#pragma once
#include "Enemy.h"


#define BARREL_SPEED 5

class Barrel : public Enemy
{
public:
	static int barrelCount;

public:
	Barrel(float x, float y);
	Barrel();

	void Move() override;



};