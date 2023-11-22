#pragma once
#include "Enemy.h"

#define BOSS_SPEED 5

class Boss : public Enemy
{
public:
	static int bossCount;

public:
	Boss(float x, float y);
	Boss();

	void Move() override;



};
