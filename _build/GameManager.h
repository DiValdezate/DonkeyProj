#pragma once
#include <raylib.h>
#include "Player.h"
#include "Enemy.h"

enum CurrentScreen { LOGO, TITLE, GAMEPLAY, ENDING };

class GameManager
{
public:

	CurrentScreen screen;

	//CHARACTERS
	Player player;
	Enemy enemy;

	//TEXTURES
	Image mapImg;
	Texture mapTexture;
	Image playerImg;
	Texture playerTexture;
	Image blockImg;
	Texture blockTexture;






public:

	GameManager();

	void InitTextures();

};

