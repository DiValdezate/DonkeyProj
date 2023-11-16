#include "GameManager.h"

GameManager::GameManager():player()
{

	screen = LOGO;

	gameTime = 0;
	framesCounter = 0;
	framesSpeed = 0;
	currentFrame = 0;
	frameRec = { 0 };


	mapImg = { 0 };
	mapTexture = { 0 };
	playerImg = { 0 };
}

void GameManager::InitTextures()
{
	mapImg = LoadImage("resources/Maps/Custom_L2.png");
	mapTexture = LoadTextureFromImage(mapImg);
	
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


