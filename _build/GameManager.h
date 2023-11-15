#pragma once
#include <raylib.h>
#include "Player.h"
#include "Enemy.h"
#include "Brick.h"
#include "Ladder.h"
#include <vector>

enum CurrentScreen { LOGO, TITLE, GAMEPLAY, ENDING };

class GameManager
{
public:

	CurrentScreen screen;

	int gameTime;
	int framesCounter;
	int framesSpeed;
	int currentFrame;
	Rectangle frameRec;

	//Characters
	Player player;
	Enemy enemy;


	//Map
	std::vector<Brick> bricks;
	std::vector<Ladder> ladders;

	//Textures
	Image mapImg;
	Texture mapTexture;
	Image playerImg;
	Texture2D playerTextRight[4];
	Texture2D playerTextLeft[4];







public:

	GameManager();

	void InitTextures();
	void LoadMap();

};

