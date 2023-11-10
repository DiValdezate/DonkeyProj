#include "GameManager.h"

GameManager::GameManager():player(),enemy()
{

	screen = LOGO;
	gameTime = 0;


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

