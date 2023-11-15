#include "GameplayManager.h"
#include <iostream>

GameplayManager::GameplayManager()
{

}

void GameplayManager::GameplayLogic(GameManager* gm)
{	
	UpdatePlayerAnim(gm, KEY_ZERO);
	UpdatePlayer(gm);
	std::cout << gm->player.GetOnLadder();




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
	Player* player = &gm->player;
	Texture2D* playerText= &gm->player.GetTexture();
	//Check if grounded
	for (int i = 0; i < gm->bricks.size(); i++)
	{
		Brick* brick = &gm->bricks.at(i);
		
		if (brick->hitBox.x <= player->GetPosition().x &&
			brick->hitBox.x + brick->hitBox.width >= player->GetPosition().x &&
			brick->hitBox.y >= player->GetPosition().y  &&
			brick->hitBox.y <= player->GetPosition().y + player->GetSpeed())
		{
			hitObstacle = true;
			player->SetSpeed(0.0f);
			player->SetPosition({ player->GetPosition().x , brick->hitBox.y});
		}	
	}

	if (hitObstacle == false)
	{
		player->SetPosition({ player->GetPosition().x , player->GetPosition().y + player->GetSpeed() * 0.25f });
		player->SetSpeed(player->GetSpeed() + GFORCE);
		player->CanJump(false);		
	}
	else
	{
		player->CanJump(true);
	}	

	//Check if on ladder
	player->SetOnLadder(false);
	for (int i = 0; i < gm->ladders.size(); i++)
	{
		Ladder* ld = &gm->ladders.at(i);

		if (ld->hitBox.x <= player->GetPosition().x &&
			ld->hitBox.x + ld->hitBox.width >= player->GetPosition().x &&
			ld->hitBox.y <= player->GetPosition().y &&
			ld->hitBox.y + ld->hitBox.height >= player->GetPosition().y)
		{
			player->SetOnLadder(true);
		}
		
	}


}