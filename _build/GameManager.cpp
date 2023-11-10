#include "GameManager.h"

GameManager::GameManager()
{
	mapImg = { 0 };
	mapTexture = { 0 };
	playerImgRight[2] = {0};
	playerTextureRight[2] = { 0 };
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

}

