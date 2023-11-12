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
    gManager.player.SetPosition({ 200 , 745 });
    gManager.LoadMap();
    

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
        DrawRectangle(gManager.test.hitBox.x, gManager.test.hitBox.y, gManager.test.hitBox.width, gManager.test.hitBox.height, RED);
        DrawCircle(gManager.test.position.x, gManager.test.position.y, 10, WHITE);


     

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