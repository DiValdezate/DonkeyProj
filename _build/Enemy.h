#pragma once
#include <raylib.h>


class Enemy
{
protected:
	Vector2 position;
	bool alive;
	Texture2D texture;
	float speed;
	float radius;
	static int enemyCount;
	bool lookingRight;
	 

public: 
	Enemy();
	Enemy(float x, float y);
	virtual ~Enemy();

	void SetPosition(float x, float y);
	Vector2 GetPosition();

	void SetTexture(Texture2D texture);
	Texture2D GetTexture();

	int GetOrientation();

	float GetRadius();

	void Turn();
	bool IsAlive();
	virtual void Move();
	bool PlayerCollision();
};


