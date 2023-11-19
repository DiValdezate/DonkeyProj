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
	
		for (int i = 0; i < gm->enemies.size(); i++)
		{
			DrawTextureEx(gm->enemies[i].GetTexture(), gm->enemies[i].GetPosition(), 1, 2, WHITE);
		}
		


		

		break;

	case ENDING:
		break;

	}
}


