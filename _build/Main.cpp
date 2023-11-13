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

    gManager.player.SetTexture(&gManager.playerTextRight);
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
            gpManager.GameplayLogic(&gManager);






        // DRAW
        //----------------------------------------------------------------------------------
        BeginDrawing();
        screenManager.ScreenDrawer(&gManager);
        DrawRectangle((int)gManager.test.hitBox.x, (int)gManager.test.hitBox.y, (int)gManager.test.hitBox.width, (int)gManager.test.hitBox.height, RED);
        DrawCircle((int)gManager.test.position.x, (int)gManager.test.position.y, 10, WHITE);


     

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