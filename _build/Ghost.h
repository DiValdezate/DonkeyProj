#pragma once
#include "Enemy.h"

#define GHOST_SPEED 5

class Ghost : public Enemy
{
public:
	static int ghostCount;

public:
	Ghost(float x, float y);
	Ghost();

	void Move() override;
};

