#include "GameManager.h"
#include <iostream>

GameManager::GameManager():player()
{

	screen = LOGO;
	result = NONE;

	isDataCleared = false;
	gameTime = 0;
	framesCounter = 0;
	framesSpeed = 0;
	currentFrame = 0;
	score = 0;
	lives = player.GetLives();
	frameRec = { 0 };

	enemyPtr = { 0 };

	mapImg = { 0 };
	mapTexture = { 0 };
	playerImg = { 0 };
}

void GameManager::InitData()
{	

	gameTime = 0;
	result = NONE;
	score = 0;
	player.ResetPlayer();


	for (size_t i = 0; i < enemyPtr.size(); i++)
	{
		Enemy* ptr = enemyPtr[i];

		if (Fire* fEnemy = dynamic_cast<Fire*>(ptr))
		{
			enemyPtr.erase(enemyPtr.begin() + i);
		}
	}

	for (size_t i = 0; i < pickups.size(); i++)
	{
		pickups.erase(pickups.begin() + i);
	}

	LoadPickUps();
}

void GameManager::InitTextures()
{
	mapImg = LoadImage("resources/Maps/Custom_L2.png");
	mapTexture = LoadTextureFromImage(mapImg);

	winScreen = LoadTexture("resources/Maps/WIN.png");
	loseScreen = LoadTexture("resources/Maps/LOSE.png");
	titleScreen = LoadTexture("resources/Menu/TITLE.png");
	logoScreen = LoadTexture("resources/Menu/splash.png");
	
	playerTextRight[0] = LoadTexture("resources/Characters/Right.png");
	playerTextRight[1] = LoadTexture("resources/Characters/Right1.png");
	playerTextRight[2] = LoadTexture("resources/Characters/Right2.png");
	playerTextRight[3] = LoadTexture("resources/Characters/Right1.png");
	playerTextLeft[0] = LoadTexture("resources/Characters/Left.png");
	playerTextLeft[1] = LoadTexture("resources/Characters/Left1.png");
	playerTextLeft[2] = LoadTexture("resources/Characters/Left2.png");
	playerTextLeft[3] = LoadTexture("resources/Characters/Left1.png");

	playerClimb[0] = LoadTexture("resources/Characters/Climb1.png");
	playerClimb[1] = LoadTexture("resources/Characters/Climb2.png");
	playerClimb[2] = LoadTexture("resources/Characters/Climb1.png");
	playerClimb[3] = LoadTexture("resources/Characters/Climb2.png");

	playerDeath[0] = LoadTexture("resources/Characters/Death1.png");
	playerDeath[1] = LoadTexture("resources/Characters/Death2.png");
	playerDeath[2] = LoadTexture("resources/Characters/Death3.png");
	playerDeath[3] = LoadTexture("resources/Characters/Death4.png");

	playerDeathIdle = LoadTexture("resources/Characters/MArio_Death_Idle.png");

	boss[0] = LoadTexture("resources/Characters/Dk1.png");
	boss[1] = LoadTexture("resources/Characters/Dk2.png");
	boss[2] = LoadTexture("resources/Characters/Dk1.png");
	boss[3] = LoadTexture("resources/Characters/Dk3.png");

	barrel[0] = LoadTexture("resources/Characters/Barrel1.png");
	barrel[1] = LoadTexture("resources/Characters/Barrel2.png");
	barrel[2] = LoadTexture("resources/Characters/Barrel2.png");
	barrel[3] = LoadTexture("resources/Characters/Barrel1.png");

	ghostRight[0] = LoadTexture("resources/Characters/GhostRight1.png");
	ghostRight[1] = LoadTexture("resources/Characters/GhostRight2.png");
	ghostRight[2] = LoadTexture("resources/Characters/GhostRight1.png");
	ghostRight[3] = LoadTexture("resources/Characters/GhostRight2.png");
	ghostLeft[0] = LoadTexture("resources/Characters/GhostLeft1.png");
	ghostLeft[1] = LoadTexture("resources/Characters/GhostLeft2.png");
	ghostLeft[2] = LoadTexture("resources/Characters/GhostLeft1.png");
	ghostLeft[3] = LoadTexture("resources/Characters/GhostLeft2.png");

	fireRight[0] = LoadTexture("resources/Characters/FireRight1.png");
	fireRight[1] = LoadTexture("resources/Characters/FireRight2.png");
	fireRight[2] = LoadTexture("resources/Characters/FireRight1.png");
	fireRight[3] = LoadTexture("resources/Characters/FireRight2.png");
	fireLeft[0] = LoadTexture("resources/Characters/FireLeft1.png");
	fireLeft[1] = LoadTexture("resources/Characters/FireLeft2.png");
	fireLeft[2] = LoadTexture("resources/Characters/FireLeft1.png");
	fireLeft[3] = LoadTexture("resources/Characters/FireLeft2.png");


	oil = LoadTexture("resources/Characters/Oil.png");

	bag = LoadTexture("resources/Characters/bag.png");
	umbrella = LoadTexture("resources/Characters/umbrella.png");
	peach = LoadTexture("resources/Characters/Peach.png");
}


void GameManager::LoadMap()
{
	Brick aux(0, 0);
	Ladder auxL(0, 0);

	//First floor, bricks
	for (int i = 0; i < (GetScreenWidth() / aux.hitBox.width); i++)
	{
		Brick brick(i*aux.hitBox.width + aux.hitBox.width/2, (float)GetScreenHeight() - aux.hitBox.height / 2);
		bricks.push_back(brick);
	}

	//First floor, ladders
	Ladder ld1(87, 720), ld2(260, 720), ld3(440, 720), ld4(615, 720);
	ladders.push_back(ld1);
	ladders.push_back(ld2);
	ladders.push_back(ld3);
	ladders.push_back(ld4);


	//Second floor
	for (int i = 0; i < (GetScreenWidth() / aux.hitBox.width); i++)
	{
		if (i == 0)
		{
			Brick brick((aux.hitBox.width + aux.hitBox.width / 2)/2 + 13, (float)GetScreenHeight() - 10.9f * (aux.hitBox.height / 2));
			bricks.push_back(brick);
		}
		else if (i == (GetScreenWidth() / aux.hitBox.width) - 1)
		{
			Brick brick(i * aux.hitBox.width, (float)GetScreenHeight() - 10.9f * (aux.hitBox.height / 2));
			bricks.push_back(brick);
		}
		else
		{
			Brick brick(i * aux.hitBox.width + aux.hitBox.width / 2, (float)GetScreenHeight() - 10.9f * (aux.hitBox.height / 2));
			bricks.push_back(brick);

		}
	}

	//Second floor, ladders
	Ladder ld5(210, 590), ld6(460, 590);
	ladders.push_back(ld5);
	ladders.push_back(ld6);



	//Third floor
	for (int i = 0; i < (GetScreenWidth() / aux.hitBox.width); i++)
	{
		if (i == 0)
		{
			Brick brick((aux.hitBox.width + aux.hitBox.width / 2) / 2 + 13, (float)GetScreenHeight() - 21.0f * (aux.hitBox.height / 2));
			bricks.push_back(brick);
		}
		else if (i == (GetScreenWidth() / aux.hitBox.width) - 1)
		{
			Brick brick(i * aux.hitBox.width, (float)GetScreenHeight() - 21.0f * (aux.hitBox.height / 2));
			bricks.push_back(brick);
		}
		else if (i == 3 || i == 10 || i == 9)
		{
			if (i == 9)
			{
				Brick brick(i * aux.hitBox.width, (float)GetScreenHeight() - 21.0f * (aux.hitBox.height / 2));
				bricks.push_back(brick);
			}
			if (i == 10)
			{
				Brick brick((i + 1)* aux.hitBox.width, (float)GetScreenHeight() - 21.0f * (aux.hitBox.height / 2));
				bricks.push_back(brick);
	
			}
		}
		else
		{
			Brick brick(i * aux.hitBox.width + aux.hitBox.width / 2, (float)GetScreenHeight() - 21.0f * (aux.hitBox.height / 2));
			bricks.push_back(brick);

		}
	}
	//Third floor, ladders
	Ladder ld7(87, 470), ld8(260, 470), ld9(440, 470), ld10(615, 470);
	ladders.push_back(ld7);
	ladders.push_back(ld8);
	ladders.push_back(ld9);
	ladders.push_back(ld10);


	//Fourth floor
	for (int i = 0; i < (GetScreenWidth() / aux.hitBox.width); i++)
	{
		if (i != 6 && i != 7)
		{
			Brick brick(i * aux.hitBox.width + aux.hitBox.width / 2, (float)GetScreenHeight() - 30.9f * aux.hitBox.height / 2);
			bricks.push_back(brick);
		}
	}

	//Fifth floor
	for (int i = 0; i < (GetScreenWidth() / aux.hitBox.width); i++)
	{
		if (i == 0)
		{
			Brick brick((aux.hitBox.width + aux.hitBox.width / 2) / 2 + 13, (float)GetScreenHeight() - 40.9f * (aux.hitBox.height / 2));
			bricks.push_back(brick);
		}
		else if (i == (GetScreenWidth() / aux.hitBox.width) - 1)
		{
			Brick brick(i * aux.hitBox.width, (float)GetScreenHeight() - 40.9f * (aux.hitBox.height / 2));
			bricks.push_back(brick);
		}
		else
		{
			Brick brick(i * aux.hitBox.width + aux.hitBox.width / 2, (float)GetScreenHeight() - 40.9f * (aux.hitBox.height / 2));
			bricks.push_back(brick);

		}
	}
	//Fifth floor, ladders
	Ladder ld11(67, 340), ld12(640, 340);
	ladders.push_back(ld11);
	ladders.push_back(ld12);


	//Sixth floor
	for (int i = 6; i < 9; i++)
	{
		Brick brick(i * aux.hitBox.width, (float)GetScreenHeight() - 49.0f * (aux.hitBox.height / 2));
		bricks.push_back(brick);
	}
	//Sixth floor, ladders
	Ladder ld13(210, 190, LADDER_WIDTH, LADDER_HEIGHT * 2 - 60), ld14(260, 190, LADDER_WIDTH, LADDER_HEIGHT * 2 - 60), ld15(415, 230, LADDER_WIDTH, LADDER_HEIGHT/2 + 40);
	ladders.push_back(ld13);
	ladders.push_back(ld14);
	ladders.push_back(ld15);

}

void GameManager::LoadEnemies() //Load all non random-spawning enemies
{
	Boss* donkey = new Boss(300, 210);
	donkey->SetTexture(boss[0]);
	enemyPtr.push_back(donkey);

	Enemy* oilBarrel = new Enemy(335.0f, 400.0f);
	oilBarrel->SetTexture(oil);
	enemies.push_back(*oilBarrel);
	enemyPtr.push_back(oilBarrel);


	Ghost* ghost1 = new Ghost(575, 495);
	Ghost* ghost2 = new Ghost(450, 495);
	Ghost* ghost3 = new Ghost(300, 495);
	Ghost* ghost4 = new Ghost(230, 495);


	ghost1->SetTexture(ghostRight[0]);
	enemyPtr.push_back(ghost1);

	ghost2->SetTexture(ghostLeft[0]);
	enemyPtr.push_back(ghost2);

	ghost3->SetTexture(ghostRight[0]);
	enemyPtr.push_back(ghost3);

	ghost4->SetTexture(ghostLeft[0]);
	enemyPtr.push_back(ghost4);
	
}

void GameManager::LoadPickUps()
{
	PickUp item(BAG);
	item.SetUpItem();
	item.position = {100,255};
	item.texture = bag;

	PickUp item2(UMBRELLA);
	item2.SetUpItem();
	item2.position = {300,625};
	item2.texture = umbrella;

	PickUp win(PEACH);
	win.SetUpItem();
	win.position = {300,115};
	win.texture = peach;

	pickups.push_back(item);
	pickups.push_back(item2);
	pickups.push_back(win);
}
