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
	bool invincible;

	Ladder* ladder;
	
public:

	int hitTime;
	int invTime;

public:
	
	Player();

	int GetLives();
	void SetLives(int lives);

	Vector2 GetPosition();
	void SetPosition(Vector2 position);

	Texture2D GetTexture();
	void SetTexture(Texture2D* texture);

	void SetHitBox(float x, float y, float width, float height);
	Rectangle GetHitbox();
	void UpdateHitBox();

	void SetSpeed(float speed);
	float GetSpeed();

	void CanJump(bool value);
	bool GetCanJump();

	void SetOnLadder(bool value, Ladder* ladder);
	bool GetOnLadder();

	void SetInvincible(bool value);

	Orientation GetOrientation();

	void Hit();
	void Move(KeyboardKey key);
	void SetMoving(bool value);
	bool CanMove();
	bool HitTime();
	bool IsInvincible();
	void ResetPlayer();
};

