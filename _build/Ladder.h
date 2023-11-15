#pragma once
#include "MapElements.h"

#define LADDER_WIDTH 20
#define LADDER_HEIGHT 120

class Ladder : public MapElements
{
public:
	Ladder(int posX, int posY);
	Ladder(int posX, int posY, float width, float height);

public:
	void SetHitBox(float width, float height);
};