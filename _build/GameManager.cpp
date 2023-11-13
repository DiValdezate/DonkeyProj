#include "GameManager.h"

GameManager::GameManager():player()
{

	screen = LOGO;

	gameTime = 0;
	framesCounter = 0;
	framesSpeed = 0;
	currentFrame = 0;
	frameRec = { 0 };


	mapImg = { 0 };
	mapTexture = { 0 };
	playerImg = { 0 };
	playerTextRight = { 0 };
	playerTextLeft = { 0 };



}

void GameManager::InitTextures()
{
	mapImg = LoadImage("resources/Maps/Custom_L2.png");
	mapTexture = LoadTextureFromImage(mapImg);
	
	playerTextRight = LoadTexture("resources/Characters/Mario_walk_right.png");
	playerTextLeft = LoadTexture("resources/Characters/Mario_walk_left.png");

}


void GameManager::LoadMap()
{
	Brick aux(0, 0);
	//First floor, height = screenHeight - brick height
	for (int i = 0; i < (GetScreenWidth() / aux.hitBox.width); i++)
	{
		Brick brick(i*aux.hitBox.width + aux.hitBox.width/2, (float)GetScreenHeight() - aux.hitBox.height / 2);
		bricks.push_back(brick);
	}

	//Second floor
	for (int i = 0; i < (GetScreenWidth() / aux.hitBox.width); i++)
	{
		if (i == 0)
		{
			Brick brick((aux.hitBox.width + aux.hitBox.width / 2)/2 + 13, (float)GetScreenHeight() - 10.9f * (aux.hitBox.height / 2));
			bricks.push_back(brick);
		}
		else if (i == (GetScreenWidth() / aux.hitBox.width) - 1)
		{
			Brick brick(i * aux.hitBox.width, (float)GetScreenHeight() - 10.9f * (aux.hitBox.height / 2));
			bricks.push_back(brick);
		}
		else
		{
			Brick brick(i * aux.hitBox.width + aux.hitBox.width / 2, (float)GetScreenHeight() - 10.9f * (aux.hitBox.height / 2));
			bricks.push_back(brick);

		}
	}

	//Third floor
	for (int i = 0; i < (GetScreenWidth() / aux.hitBox.width); i++)
	{
		if (i == 0)
		{
			Brick brick((aux.hitBox.width + aux.hitBox.width / 2) / 2 + 13, (float)GetScreenHeight() - 21.0f * (aux.hitBox.height / 2));
			bricks.push_back(brick);
		}
		else if (i == (GetScreenWidth() / aux.hitBox.width) - 1)
		{
			Brick brick(i * aux.hitBox.width, (float)GetScreenHeight() - 21.0f * (aux.hitBox.height / 2));
			bricks.push_back(brick);
		}
		else if (i == 3 || i == 10 || i == 9)
		{
			if (i == 9)
			{
				Brick brick(i * aux.hitBox.width, (float)GetScreenHeight() - 21.0f * (aux.hitBox.height / 2));
				bricks.push_back(brick);
			}
			if (i == 10)
			{
				Brick brick((i + 1)* aux.hitBox.width, (float)GetScreenHeight() - 21.0f * (aux.hitBox.height / 2));
				bricks.push_back(brick);
	
			}
		}
		else
		{
			Brick brick(i * aux.hitBox.width + aux.hitBox.width / 2, (float)GetScreenHeight() - 21.0f * (aux.hitBox.height / 2));
			bricks.push_back(brick);

		}
	}

	//Fourth floor
	for (int i = 0; i < (GetScreenWidth() / aux.hitBox.width); i++)
	{
		if (i != 6 && i != 7)
		{
			Brick brick(i * aux.hitBox.width + aux.hitBox.width / 2, (float)GetScreenHeight() - 30.9f * aux.hitBox.height / 2);
			bricks.push_back(brick);
		}
	}

	//Fifth floor
	for (int i = 0; i < (GetScreenWidth() / aux.hitBox.width); i++)
	{
		if (i == 0)
		{
			Brick brick((aux.hitBox.width + aux.hitBox.width / 2) / 2 + 13, (float)GetScreenHeight() - 40.9f * (aux.hitBox.height / 2));
			bricks.push_back(brick);
		}
		else if (i == (GetScreenWidth() / aux.hitBox.width) - 1)
		{
			Brick brick(i * aux.hitBox.width, (float)GetScreenHeight() - 40.9f * (aux.hitBox.height / 2));
			bricks.push_back(brick);
		}
		else
		{
			Brick brick(i * aux.hitBox.width + aux.hitBox.width / 2, (float)GetScreenHeight() - 40.9f * (aux.hitBox.height / 2));
			bricks.push_back(brick);

		}
	}

	//Sixth floor
	for (int i = 6; i < 9; i++)
	{
		Brick brick(i * aux.hitBox.width, (float)GetScreenHeight() - 49.0f * (aux.hitBox.height / 2));
		bricks.push_back(brick);
	}
}


