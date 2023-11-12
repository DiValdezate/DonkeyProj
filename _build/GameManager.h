#pragma once
#include <raylib.h>
#include "Player.h"
#include "Enemy.h"
#include "Brick.h"
#include <vector>

enum CurrentScreen { LOGO, TITLE, GAMEPLAY, ENDING };

class GameManager
{
public:

	CurrentScreen screen;

	int gameTime;


	//Characters
	Player player;
	Enemy enemy;
	Brick test;

	//Map
	std::vector<Brick> bricks;

	//Textures
	Image mapImg;
	Texture mapTexture;
	Image playerImgRight[3];
	Texture playerTextureRight[3];
	Image playerImgLeft[3];
	Texture playerTextureLeft[3];
	Image blockImg;
	Texture blockTexture;






public:

	GameManager();

	void InitTextures();
	void LoadMap();

};

