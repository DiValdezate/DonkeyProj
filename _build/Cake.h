#pragma once
#include "Enemy.h"

#define CAKE_SPEED 2

class Cake : public Enemy
{
public:
	static int cakeCount;


public:
	Cake();

	void Move() override;
	
};

