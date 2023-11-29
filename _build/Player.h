#pragma once
#include <raylib.h>
#include "Ladder.h"

#define PLAYER_MAX_SPEED 4
#define PLAYER_JUMP_FORCE 40
#define GFORCE 3

enum Orientation { RIGHT, LEFT, UP }; //Where is the player facing at.

class Player
{
	int lives;
	bool alive;
	float speed;


	Orientation orientation;
	Vector2 position;
	Texture2D texture;
	Rectangle hitBox;

	float rotation;
	bool canMove;
	bool canJump;
	bool onLadder;

	Ladder* ladder;
	
public:

	int hitTime;

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
	Rectangle GetHitbox();
	void UpdateHitBox();

	void SetSpeed(float speed);
	float GetSpeed();

	void CanJump(bool value);
	bool GetCanJump();

	void SetOnLadder(bool value, Ladder* ladder);
	bool GetOnLadder();


	Orientation GetOrientation();


	bool isAlive();
	void Kill();
	void Hit();
	void Move(KeyboardKey key);
	void TurnLeft();
	void TurnRight();
	void SetMoving(bool value);
	bool CanMove();
	bool HitTime();
	void ResetPlayer();
};

