#include "ScreenManager.h"
#include <iostream>
#include <string>

ScreenManager::ScreenManager()
{
	

}

void ScreenManager::ScreenLogic(GameManager* gm)
{
	switch (gm->screen)
	{
	case LOGO:		
		if (gm->gameTime > 120)
			gm->screen = TITLE;

		break;

	case TITLE:
		if (IsKeyPressed(KEY_ENTER))
			gm->screen = GAMEPLAY;

		if (IsKeyPressed(KEY_O))
			gm->screen = OPTIONS;

		break;

	case OPTIONS:
		if (IsKeyPressed(KEY_ENTER))
			gm->screen = TITLE;
		break;


	case GAMEPLAY:
		break;

	case ENDING:
		if (IsKeyPressed(KEY_ENTER))
		{
			gm->screen = TITLE;
			gm->InitData();
		}

		if (IsKeyPressed(KEY_O))
		{
			gm->screen = OPTIONS;
			gm->InitData();
		}
		break;

	}
}


void ScreenManager::ScreenDrawer(GameManager* gm)
{
	switch (gm->screen)
	{
	case LOGO:
		DrawTextureEx(gm->logoScreen, {-190,70}, 0, 0.7f, WHITE);
		break;

	case TITLE:
		ClearBackground(BLACK);
		DrawTextureEx(gm->titleScreen, { 130,70 }, 0, 1, WHITE);
		DrawText("by Diego V.", 300, 410, 18, WHITE);
		if(gm->gameTime % 60 == 0 || gm->gameTime % 61 == 0 || gm->gameTime % 62 == 0)
			DrawText("Press [START] to start playing", 180, 500, 20, WHITE);

		DrawText("Press [O] to show instructions", 185, 570, 20, WHITE);

		break;
	case OPTIONS:
		ClearBackground(BLACK);
		DrawText("SAVE THE PRINCESS!", 180, 200, 30, WHITE);
		DrawText("Collect ITEMS to get extra points", 100, 250, 30, WHITE);
		DrawText("Use ARROWS to move", 180, 400, 30, DARKGREEN);
		DrawText("Press SPACE to jump", 180, 450, 30, DARKGREEN);
		

		DrawText("[START] to go to menu ", 220, 600, 20, DARKGREEN);


		break;
	case GAMEPLAY:

		DrawTextureEx(gm->mapTexture, {0,0},0,1, WHITE);
		DrawTextureEx(gm->player.GetTexture(), { gm->player.GetPosition().x, gm->player.GetPosition().y - gm->player.GetTexture().height }, 1, 1, WHITE);
				

		for (int i = 0; i < gm->enemyPtr.size(); i++)
		{
			if (gm->enemyPtr[i] != nullptr)
			{
				DrawTextureEx(gm->enemyPtr[i]->GetTexture(), gm->enemyPtr[i]->GetPosition(), 1, 2, WHITE);
				
			}
		}
		
		for (int i = 0; i < gm->pickups.size(); i++)
		{
			DrawTextureEx(gm->pickups[i].texture, gm->pickups[i].position, 1, 1.5f, WHITE);
		}
		
		//DRAW HUD
		//Lives
		switch (gm->lives)
		{
		case 3:
			DrawTextureEx(gm->playerTextLeft[0], { 20,40 }, 1, 1, WHITE);
			DrawTextureEx(gm->playerTextLeft[0], { 45,40 }, 1, 1, WHITE);
			DrawTextureEx(gm->playerTextLeft[0], { 70,40 }, 1, 1, WHITE);
			break;
		case 2:
			DrawTextureEx(gm->playerTextLeft[0], { 70,40 }, 1, 1, WHITE);
			DrawTextureEx(gm->playerTextLeft[0], { 45,40 }, 1, 1, WHITE);
			break;
		case 1:
			DrawTextureEx(gm->playerTextLeft[0], { 70,40 }, 1, 1, WHITE);
			break;
		default:
			break;
		}

		//Score
		char scoreTxt[20];
		sprintf(scoreTxt, "%d", gm->score);
		DrawText("SCORE: ", 560, 40, 20, WHITE);
		DrawText(scoreTxt, 650, 40, 20, WHITE);
		

		break;

	case ENDING:

		char finalscoreTxt[20];
		sprintf(finalscoreTxt, "%d", gm->score);

		switch (gm->result)
		{
		case WIN:
			DrawTextureEx(gm->winScreen, { -180,-50 }, 0, 10, WHITE);
			DrawText("FINAL SCORE: ", 250, 400, 20, WHITE);
			DrawText(finalscoreTxt, 420, 400, 20, WHITE);
			DrawText("PRESS [ENTER] TO GO TO THE MENU", 150, 550, 20, WHITE);
			DrawText("PRESS [O] TO SEE INSTRUCTIONS", 180, 600, 20, WHITE);
			break;
		case LOSE:
			DrawTextureEx(gm->loseScreen, { -180,-50 }, 0, 10, WHITE);
			DrawText("FINAL SCORE: ", 250, 400, 20, WHITE);
			DrawText(finalscoreTxt, 420, 400, 20, WHITE);
			DrawText("PRESS [ENTER] TO TRY AGAIN", 200, 550, 20, WHITE);
			DrawText("PRESS [O] TO SEE INSTRUCTIONS", 180, 600, 20, WHITE);
			break;
		}


		
		break;

	}
}


