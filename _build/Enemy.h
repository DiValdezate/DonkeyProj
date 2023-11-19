#pragma once
#include <raylib.h>

class Enemy
{
	Vector2 position;
	bool alive;
	Texture2D texture;


public: 
	Enemy();
	Enemy(float x, float y);
	virtual ~Enemy();

	void SetPosition(float x, float y);
	Vector2 GetPosition();

	void SetTexture(Texture2D texture);
	Texture2D GetTexture();

	bool IsAlive();
	virtual void Move();
};

