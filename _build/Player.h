#pragma once
#include <raylib.h>

#define PLAYER_MAX_SPEED 4

enum Orientation { RIGHT, LEFT, UP }; //Where is the player facing at.

class Player
{
	Orientation orientation;
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

	Orientation GetOrientation();

	bool isAlive();
	void Kill();
	void Hit();
	void Move(KeyboardKey key);
	void TurnLeft();
	void TurnRight();
	void Moving(bool value);
	bool IsMoving();

};

