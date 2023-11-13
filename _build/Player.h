#pragma once
#include <raylib.h>

#define PLAYER_MAX_SPEED 4


class Player
{
	int lives;
	bool alive;
	Vector2 speed;
	Vector2 position;
	Texture2D texture;
	Rectangle hitBox;
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

	void SetHitBox(float x, float y, float width, float height);
	void UpdateHitBox();

	bool isAlive();
	void Kill();
	void Hit();
	void Move(KeyboardKey key);
	void TurnLeft();
	void TurnRight();
	void Moving(bool value);
	bool IsMoving();

};

