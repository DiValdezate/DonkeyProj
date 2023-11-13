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
		UpdatePlayerAnim(gm);
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
	float recWidth = (float)gm->playerTextRight.width;
	float recHeight = (float)gm->playerTextRight.height;
	gm->frameRec = { 0.0f,0.0f,recWidth / 2,recHeight };


}