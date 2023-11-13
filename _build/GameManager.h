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
	int framesCounter;
	int framesSpeed;


	//Characters
	Player player;
	Enemy enemy;
	Brick test;

	//Map
	std::vector<Brick> bricks;

	//Textures
	Image mapImg;
	Texture mapTexture;
	Image playerImg;
	Texture2D playerTextRight;
	Texture2D playerTextLeft;







public:

	GameManager();

	void InitTextures();
	void LoadMap();

};

