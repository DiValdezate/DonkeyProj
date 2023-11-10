#include "raylib.h"
#include "ScreenManager.h"
#include "GameplayManager.h"
#include <iostream>


//------------------------------------------------------------------------------------
// Variables declaration
//------------------------------------------------------------------------------------
GameManager gManager;
ScreenManager screenManager;
GameplayManager gpManager;



//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 700;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "DonkeyKong");
    InitAudioDevice();
   


    //Textures initialization
    //--------------------------------------------------------------------------------------
    gManager.InitTextures();


    //Audio initialization
    //--------------------------------------------------------------------------------------


    //Variables initialization
    //--------------------------------------------------------------------------------------
    gManager.gameTime = 0;
    gManager.screen = GAMEPLAY;//Change it later

    gManager.player.SetTexture(&gManager.playerTextureRight[0]);
    gManager.player.SetPosition({ screenWidth / 2,screenHeight / 2 });


    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // UPDATE
        //----------------------------------------------------------------------------------
        screenManager.ScreenLogic(&gManager);

        if(gManager.screen == GAMEPLAY)
            gpManager.GameplayLogic();


        // DRAW
        //----------------------------------------------------------------------------------
        BeginDrawing();

        screenManager.ScreenDrawer(&gManager);
     

        ClearBackground(LIGHTGRAY);



        EndDrawing();
        //----------------------------------------------------------------------------------

  
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------


    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}