#pragma once
#include <raylib.h>
#include "Player.h"
#include "Enemy.h"
#include "Brick.h"
#include "Ladder.h"
#include "Fire.h"
#include "Boss.h"
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
	std::vector<Enemy> enemies;
	std::vector<Enemy*> enemyPtr;

	//Map
	std::vector<Brick> bricks;
	std::vector<Ladder> ladders;

	//Textures
	Image mapImg;
	Texture mapTexture;
	Image playerImg;
	Texture2D playerTextRight[4];
	Texture2D playerTextLeft[4];
	Texture2D playerClimb[4];
	Texture2D fireRight[4];
	Texture2D fireLeft[4];
	Texture2D boss[4];
	Texture2D playerDeath[4];
	Texture2D playerDeathIdle;

	Texture2D oil;


public:

	GameManager();

	void InitTextures();
	void LoadMap();
	void LoadEnemies();

};

