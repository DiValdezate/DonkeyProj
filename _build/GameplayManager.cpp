#include "GameplayManager.h"
#include <iostream>

GameplayManager::GameplayManager()
{

}

void GameplayManager::GameplayLogic(GameManager* gm)
{
	
	UpdatePlayerAnim(gm,KEY_ZERO);
	UpdatePlayer(gm);





}

void GameplayManager::UpdatePlayerAnim(GameManager* gm, KeyboardKey key)
{	
	if (gm->framesCounter++ > 30)
	{
		gm->currentFrame++;
		gm->framesCounter = 0;
	}

	if (gm->currentFrame > 3)
		gm->currentFrame = 0;

	switch (key)
	{
	case KEY_RIGHT:
		gm->player.SetTexture(&gm->playerTextRight[gm->currentFrame]);
		break;
	case KEY_LEFT:
		gm->player.SetTexture(&gm->playerTextLeft[gm->currentFrame]);
		break;
	default:
		switch (gm->player.GetOrientation())
		{
		case RIGHT:
			gm->player.SetTexture(&gm->playerTextRight[0]);
			break;
		case LEFT:
			gm->player.SetTexture(&gm->playerTextLeft[0]);
			break;
		}
	}	
	gm->framesCounter++;

}

void GameplayManager::UpdatePlayer(GameManager* gm)
{
	//PLAYER MOVEMENT
	if (IsKeyDown(KEY_RIGHT))
	{
		gm->player.Move(KEY_RIGHT);
		UpdatePlayerAnim(gm, KEY_RIGHT);
	}
	if (IsKeyDown(KEY_LEFT))
	{
		gm->player.Move(KEY_LEFT);
		UpdatePlayerAnim(gm, KEY_LEFT);
	}
	if (IsKeyDown(KEY_SPACE))
	{
		gm->player.Move(KEY_SPACE);
	}

	bool hitObstacle = 0;
	int itemsLenght = sizeof(gm->bricks) / sizeof(gm->bricks[0]);

	for (int i = 0; i < gm->bricks.size(); i++)
	{

	}
}