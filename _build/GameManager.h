#pragma once
#include <raylib.h>
#include "Player.h"
#include "Enemy.h"

enum CurrentScreen { LOGO, TITLE, GAMEPLAY, ENDING };

class GameManager
{
public:

	CurrentScreen screen;
	int gameTime;

	//CHARACTERS
	Player player;
	Enemy enemy;

	//TEXTURES
	Image mapImg;
	Texture mapTexture;
	Image playerImgRight[3];
	Texture playerTextureRight[3];
	Image blockImg;
	Texture blockTexture;






public:

	GameManager();

	void InitTextures();

};

