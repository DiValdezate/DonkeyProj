#include "GameplayManager.h"
#include <iostream>

GameplayManager::GameplayManager()
{

}

void GameplayManager::GameplayLogic(GameManager* gm)
{
	if (IsKeyDown(KEY_RIGHT))
	{
		gm->player.Move(KEY_RIGHT);
		gm->player.SetTexture(&gm->playerTextRight);
		

	}
	if (IsKeyDown(KEY_LEFT)) 
	{
		gm->player.Move(KEY_LEFT);
		gm->player.SetTexture(&gm->playerTextLeft);
	}

}

void GameplayManager::UpdatePlayerAnim(GameManager* gm)
{
	gm->framesCounter++;


}