#pragma once
#include "Enemy.h"

#define FIRE_SPD 4

class Fire : public Enemy
{
public:
	static int fireCount;

public:
	Fire(float x, float y);
	Fire();

	void Move() override;
	

	
};

