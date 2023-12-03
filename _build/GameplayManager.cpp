#include "GameplayManager.h"
#include <iostream>

GameplayManager::GameplayManager()
{

}

void GameplayManager::GameplayLogic(GameManager* gm)
{	
	UpdatePlayerAnim(gm, KEY_ZERO);
	UpdatePlayer(gm);
	RandomEnemySpawner(gm);
	MoveEnemies(gm);
	UpdateEnemyAnim(gm);
	CheckCollisions(gm);

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
	case KEY_UP:	
		if(gm->player.GetOnLadder())
			gm->player.SetTexture(&gm->playerClimb[gm->currentFrame]);
		break;
	case KEY_DOWN:
		if (gm->player.GetOnLadder())
			gm->player.SetTexture(&gm->playerClimb[gm->currentFrame]);
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

	if (gm->player.CanMove() == false)
		gm->player.SetTexture(&gm->playerDeath[gm->currentFrame]);
	if (gm->player.hitTime > 60 && gm->player.hitTime < 180)
		gm->player.SetTexture(&gm->playerDeathIdle);


	gm->framesCounter++;

}

void GameplayManager::UpdatePlayer(GameManager* gm)
{	
	gm->lives = gm->player.GetLives();
	if (gm->lives <= 0 || gm->player.GetPosition().y > (float)GetScreenHeight())
	{
		gm->screen = ENDING;
		gm->result = LOSE;
	}

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
	if (IsKeyDown(KEY_UP))
	{
		gm->player.Move(KEY_UP);
		UpdatePlayerAnim(gm, KEY_UP);
	}	
	if (IsKeyDown(KEY_DOWN))
	{
		gm->player.Move(KEY_DOWN);
		UpdatePlayerAnim(gm, KEY_DOWN);
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
			player->UpdateHitBox();
		}	
	}

	if (hitObstacle == false && player->GetOnLadder() == false)
	{
		player->SetPosition({ player->GetPosition().x , player->GetPosition().y + player->GetSpeed() * 0.25f });
		player->SetSpeed(player->GetSpeed() + GFORCE);
		player->CanJump(false);		
		player->UpdateHitBox();

		if(player->GetOrientation() == LEFT)
			player->SetTexture(&gm->playerTextLeft[1]);
		if (player->GetOrientation() == RIGHT)
			player->SetTexture(&gm->playerTextRight[1]);
	}
	else
	{
		player->CanJump(true);
	}	

	//Check if on ladder
	player->SetOnLadder(false, NULL);
	for (int i = 0; i < gm->ladders.size(); i++)
	{
		Ladder* ld = &gm->ladders.at(i);

		if (ld->hitBox.x <= player->GetPosition().x + 15 &&
			ld->hitBox.x + ld->hitBox.width >= player->GetPosition().x &&
			ld->hitBox.y <= player->GetPosition().y &&
			ld->hitBox.y + ld->hitBox.height >= player->GetPosition().y)
		{
			player->SetOnLadder(true, ld);
			player->UpdateHitBox();
		}		
	}

	if (player->CanMove() == false)
		player->HitTime();
}

void GameplayManager::RandomEnemySpawner(GameManager* gm)
{
		if (gm->gameTime % 240 == 0) //spawns a random fire every three seconds and stops when there are 5 of them
		{
			Fire* fire = new Fire(335.0f, 370.0f);
			if (fire->fireCount <= 5)
			{
				if (fire->GetOrientation() == 1)
					fire->SetTexture(gm->fireRight[0]);
				else
					fire->SetTexture(gm->fireLeft[0]);
				gm->enemies.push_back(*fire);
				gm->enemyPtr.push_back(fire);
			}
		}

		if (gm->gameTime % 120 == 0) //spawns a random barrel every two seconds
		{
			Enemy* barrel = new Barrel();
			if (barrel->GetOrientation() == 1)
			{
				barrel->SetTexture(gm->barrel[0]);
				barrel->SetPosition(10, 625);
			}
			else
			{
				barrel->SetTexture(gm->barrel[0]);
				barrel->SetPosition((float)GetScreenWidth() - 10, 625);
			}

			gm->enemies.push_back(*barrel);
			gm->enemyPtr.push_back(barrel);
		}

		if (gm->gameTime % 180 == 0) //spawns a random cake every three seconds
		{
			Enemy* cake = new Cake();
			cake->SetTexture(gm->cake);
			gm->enemyPtr.push_back(cake);
		}
	
}

void GameplayManager::MoveEnemies(GameManager* gm)
{

	for (int i = 0; i < gm->enemyPtr.size(); i++)
	{
		if (gm->enemyPtr[i] != nullptr)
		{			
			Enemy* ptr = gm->enemyPtr[i];			

			ptr->Move();
			if (Barrel* bEnemy = dynamic_cast<Barrel*>(ptr))
			{
				if (bEnemy->barrelTime > 280) //If the enemy is a barrel, this will erase it from the vector after 4-5 seconds, so they do not stack forever.
					gm->enemyPtr.erase(gm->enemyPtr.begin() + i);
			}
			if (Cake* cEnemy = dynamic_cast<Cake*>(ptr))
			{
				if (cEnemy->cakeTime > 340) //If the enemy is a cake, this will erase it from the vector after 4-5 seconds, so they do not stack forever.
					gm->enemyPtr.erase(gm->enemyPtr.begin() + i);
			}
			
				
		}
		
	}
}

void GameplayManager::UpdateEnemyAnim(GameManager* gm)
{
	if (gm->framesCounter++ > 30)
	{
		gm->currentFrame++;
		gm->framesCounter = 0;
	}

	if (gm->currentFrame > 3)
		gm->currentFrame = 0;

	for (int i = 0; i < gm->enemyPtr.size(); i++) //Loops through the enemies vector and checks the subclass of every enemy. 
	{
		if (gm->enemyPtr[i] != nullptr)
		{
			Enemy* ptr = gm->enemyPtr[i];

			if (Fire* fenemy = dynamic_cast<Fire*>(ptr))
			{
				if (ptr->GetOrientation())//True means right
					ptr->SetTexture(gm->fireRight[gm->currentFrame]);
				else
				{
					ptr->SetTexture(gm->fireLeft[gm->currentFrame]);
				}
			}
			if (Ghost* genemy = dynamic_cast<Ghost*>(ptr))
			{
				if (ptr->GetOrientation())//True means right
					ptr->SetTexture(gm->ghostRight[gm->currentFrame]);
				else
				{
					ptr->SetTexture(gm->ghostLeft[gm->currentFrame]);
				}
			}
			if (Boss* benemy = dynamic_cast<Boss*>(ptr))
			{
				if (ptr->GetOrientation())//True means right
					ptr->SetTexture(gm->boss[gm->currentFrame]);
				else
				{
					ptr->SetTexture(gm->boss[gm->currentFrame]);
				}
			}
			if (Barrel* barrelEnemy = dynamic_cast<Barrel*>(ptr))
			{
				if (ptr->GetOrientation())//True means right
					ptr->SetTexture(gm->barrel[gm->currentFrame]);
				else
				{
					ptr->SetTexture(gm->barrel[gm->currentFrame]);
				}
			}
		}

	}

}

void GameplayManager::CheckCollisions(GameManager* gm)
{
	for (int i = 0; i < gm->enemyPtr.size(); i++)
	{
		if (gm->enemyPtr[i] != nullptr)
		{
			Enemy* ptr = gm->enemyPtr[i];

			if (CheckCollisionCircleRec({ ptr->GetPosition().x + 15, ptr->GetPosition().y + 15 }, ptr->GetRadius(), gm->player.GetHitbox()))
			{					
				gm->player.Hit();					
			}

		}
	}

	for (int i = 0; i < gm->pickups.size(); i++)
	{
		PickUp pckp = gm->pickups[i];

		if (CheckCollisionCircleRec({ pckp.position.x + 15, pckp.position.y + 15 }, pckp.radius, gm->player.GetHitbox()))
		{
			gm->score += pckp.points;

			if (pckp.type == PEACH)
			{
				gm->screen = ENDING;
				gm->result = WIN;
			}
			else
			{				
				gm->pickups.erase(gm->pickups.begin()+i);
			}
		}

	}
}
