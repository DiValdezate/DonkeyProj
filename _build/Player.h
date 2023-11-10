#pragma once
#include <raylib.h>

class Player
{
	int lives;
	bool alive;
	Vector2 speed;
	Vector2 position;
	Texture2D texture;
	float radius;
	float rotation;
	bool moving;
	

public:
	
	Player();

	int GetLives();
	void SetLives(int lives);

	Vector2 GetPosition();
	void SetPosition(Vector2 position);

	Texture2D GetTexture();
	void SetTexture(Texture2D* texture);

	float GetRotation();
	void SetRotation(float rotation);

	float GetRadius();

	bool isAlive();
	void Kill();
	void Hit();
	void Move();
	void TurnLeft();
	void TurnRight();
	void Moving(bool value);
	bool IsMoving();

};

