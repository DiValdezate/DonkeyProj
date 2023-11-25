#pragma once
#include "GameManager.h"

class GameplayManager
{
public:





public:

	GameplayManager();

	void GameplayLogic(GameManager* gm);
	void UpdatePlayerAnim(GameManager* gm, KeyboardKey key);
	void UpdatePlayer(GameManager* gm);
	void FireSpawner(GameManager* gm);

	
	void MoveEnemies(GameManager* gm);
	void UpdateEnemyAnim(GameManager* gm);
	void CheckCollisions(GameManager* gm);
};

