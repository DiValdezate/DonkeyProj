#include "ScreenManager.h"
#include <iostream>

ScreenManager::ScreenManager()
{
	

}

void ScreenManager::ScreenLogic(GameManager* gm)
{
	switch (gm->screen)
	{
	case LOGO:

		break;

	case TITLE:
		break;

	case GAMEPLAY:
		break;

	case ENDING:
		break;

	}
}

void ScreenManager::ScreenDrawer(GameManager* gm)
{
	switch (gm->screen)
	{
	case LOGO:

		break;

	case TITLE:
		break;

	case GAMEPLAY:
		DrawTextureEx(gm->mapTexture, {0,0},0,1, WHITE);
		DrawTextureEx(gm->player.GetTexture(), { gm->player.GetPosition().x, gm->player.GetPosition().y - gm->player.GetTexture().height }, 1, 1, WHITE);
		
		for (int i = 0; i < gm->ladders.size(); i++)
		{
			Ladder ladder = gm->ladders.at(i);
			DrawRectangle(ladder.hitBox.x, ladder.hitBox.y, ladder.hitBox.width, ladder.hitBox.height,WHITE);
			DrawCircle(ladder.position.x, ladder.position.y, 2, RED);
		}
		


		

		break;

	case ENDING:
		break;

	}
}


