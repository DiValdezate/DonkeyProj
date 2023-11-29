#include "PickUp.h"

PickUp::PickUp(PickUpType type)
{
	this->type = type;
	position = { 0 };
	radius = 0;
	texture = { 0 };
	points = 0;
}

void PickUp::SetUpItem()
{
	switch (type)
	{
	case UMBRELLA:
		radius = 15.0f;
		points = 100;
		break;
	case BAG:
		radius = 15.0f;
		points = 150;
		break;
	case PEACH:
		radius = 25.0f;
		points = 1000;
		break;
	default:
		break;
	}

}
