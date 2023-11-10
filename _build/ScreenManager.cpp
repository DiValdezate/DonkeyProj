#include "ScreenManager.h"


ScreenManager::ScreenManager()
{
	

}

void ScreenManager::ScreenLogic(GameManager* gm)
{
	switch (gm->screen)
	{
	case LOGO://LOGO

		break;

	case TITLE://TITLE
		break;

	case GAMEPLAY://GAMEPLAY
		break;

	case ENDING://ENDING
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
		
		

		break;

	case ENDING:
		break;

	}
}


