#include "GameManager.h"

GameManager::GameManager():player()
{

	screen = LOGO;

	gameTime = 0;
	Brick test;

	mapImg = { 0 };
	mapTexture = { 0 };
	playerImgRight[3] = {0};
	playerTextureRight[3] = { 0 };
	playerImgLeft[3] = { 0 };
	playerTextureLeft[3] = { 0 };
	blockImg = { 0 };
	blockTexture = { 0 };




}

void GameManager::InitTextures()
{
	mapImg = LoadImage("resources/Maps/Custom_L2.png");
	mapTexture = LoadTextureFromImage(mapImg);

	playerImgRight[0] = LoadImage("resources/Characters/Right.png");
	playerImgRight[1] = LoadImage("resources/Characters/Right1.png");
	playerImgRight[2] = LoadImage("resources/Characters/Right2.png");
	playerTextureRight[0] = LoadTextureFromImage(playerImgRight[0]);
	playerTextureRight[1] = LoadTextureFromImage(playerImgRight[1]);
	playerTextureRight[2] = LoadTextureFromImage(playerImgRight[2]);

	playerImgLeft[0] = LoadImage("resources/Characters/Left.png");
	playerImgLeft[1] = LoadImage("resources/Characters/Left1.png");
	playerImgLeft[2] = LoadImage("resources/Characters/Left2.png");
	playerTextureLeft[0] = LoadTextureFromImage(playerImgLeft[0]);
	playerTextureLeft[1] = LoadTextureFromImage(playerImgLeft[1]);
	playerTextureLeft[2] = LoadTextureFromImage(playerImgLeft[2]);



}


void GameManager::LoadMap()
{
	Brick aux(0, 0);
	//First floor, height = screenHeight - brick height
	for (int i = 0; i < (GetScreenWidth() / aux.hitBox.width); i++)
	{
		Brick brick(i*aux.hitBox.width + aux.hitBox.width/2, GetScreenHeight() - aux.hitBox.height / 2);
		bricks.push_back(brick);
	}

	//Second floor, gap is half the width of a block
	for (int i = 0; i < (GetScreenWidth() / aux.hitBox.width); i++)
	{
		if (i == 0)
		{
			Brick brick((aux.hitBox.width + aux.hitBox.width / 2)/2 + 13, GetScreenHeight() - 10.9f * (aux.hitBox.height / 2));
			bricks.push_back(brick);
		}
		else if (i == (GetScreenWidth() / aux.hitBox.width) - 1)
		{
			Brick brick(i * aux.hitBox.width, GetScreenHeight() - 10.9f * (aux.hitBox.height / 2));
			bricks.push_back(brick);
		}
		else
		{
			Brick brick(i * aux.hitBox.width + aux.hitBox.width / 2, GetScreenHeight() - 10.9f * (aux.hitBox.height / 2));
			bricks.push_back(brick);

		}
	}

	//Third floor
	for (int i = 0; i < (GetScreenWidth() / aux.hitBox.width); i++)
	{
		if (i == 0)
		{
			Brick brick((aux.hitBox.width + aux.hitBox.width / 2) / 2 + 13, GetScreenHeight() - 21.0f * (aux.hitBox.height / 2));
			bricks.push_back(brick);
		}
		else if (i == (GetScreenWidth() / aux.hitBox.width) - 1)
		{
			Brick brick(i * aux.hitBox.width, GetScreenHeight() - 21.0f * (aux.hitBox.height / 2));
			bricks.push_back(brick);
		}
		else if (i == 3 || i == 10)
		{
			if (i == 10)
			{
				//DIBUJAR EL HUECO

			}
		}
		else
		{
			Brick brick(i * aux.hitBox.width + aux.hitBox.width / 2, GetScreenHeight() - 21.0f * (aux.hitBox.height / 2));
			bricks.push_back(brick);

		}
	}

	



}
