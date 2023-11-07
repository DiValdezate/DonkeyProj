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




public:

	GameManager();

	void InitTextures();

};

