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
		//DrawRectangle(gm->player.GetHitbox().x, gm->player.GetHitbox().y , gm->player.GetHitbox().width, gm->player.GetHitbox().height, WHITE);
		

		for (int i = 0; i < gm->enemyPtr.size(); i++)
		{
			if (gm->enemyPtr[i] != nullptr)
			{
				DrawTextureEx(gm->enemyPtr[i]->GetTexture(), gm->enemyPtr[i]->GetPosition(), 1, 2, WHITE);
				//DrawCircle(gm->enemyPtr[i]->GetPosition().x + 15, gm->enemyPtr[i]->GetPosition().y + 15, gm->enemyPtr[i]->GetRadius(), WHITE);
			}
		}
		
		for (int i = 0; i < gm->pickups.size(); i++)
		{
			DrawTextureEx(gm->pickups[i].texture, gm->pickups[i].position, 1, 1.5f, WHITE);
		}
		


		

		break;

	case ENDING:
		break;

	}
}


