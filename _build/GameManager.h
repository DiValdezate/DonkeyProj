#pragma once
#include <raylib.h>
#include "Player.h"
#include "Enemy.h"
#include "Brick.h"
#include "Ladder.h"
#include "Fire.h"
#include "Ghost.h"
#include "Boss.h"
#include "Barrel.h"
#include "PickUp.h"
#include <vector>

enum CurrentScreen { LOGO, TITLE, GAMEPLAY, ENDING };
enum GameResult { NONE, WIN, LOSE };

class GameManager
{
public:

	CurrentScreen screen;
	GameResult result;

	int gameTime;
	int framesCounter;
	int framesSpeed;
	int currentFrame;
	int score;
	int lives;
	Rectangle frameRec;

	//Characters
	Player player;
	std::vector<Enemy> enemies;
	std::vector<Enemy*> enemyPtr;

	//Map
	std::vector<Brick> bricks;
	std::vector<Ladder> ladders;
	std::vector<PickUp> pickups;

	//Textures
	Image mapImg;
	Texture mapTexture;
	Texture2D winScreen;
	Texture2D loseScreen;

	Image playerImg;
	Texture2D playerTextRight[4];
	Texture2D playerTextLeft[4];
	Texture2D playerClimb[4];
	Texture2D fireRight[4];
	Texture2D fireLeft[4];
	Texture2D ghostRight[4];
	Texture2D ghostLeft[4];
	Texture2D boss[4];
	Texture2D barrel[4];
	Texture2D bag;
	Texture2D umbrella;
	Texture2D peach;
	Texture2D playerDeath[4];
	Texture2D playerDeathIdle;
	Texture2D oil;


public:

	GameManager();

	void InitTextures();
	void LoadMap();
	void LoadEnemies();
	void LoadPickUps();

};

