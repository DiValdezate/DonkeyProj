#pragma once
#include <raylib.h>

enum PickUpType{UMBRELLA, BAG, PEACH};

class PickUp
{
public:

	PickUpType type;
	Vector2 position;
	float radius;
	Texture2D texture;
	float points;

public:

	PickUp(PickUpType type);
	
	void SetUpItem();
};

