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
    gManager.screen = LOGO;//Change it later

    gManager.player.SetTexture(&gManager.playerTextRight[0]);
    gManager.player.SetPosition({ 200 , 700 });    
    gManager.LoadMap();
    gManager.LoadEnemies();
    gManager.LoadPickUps();
    

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // UPDATE
        //----------------------------------------------------------------------------------
        screenManager.ScreenLogic(&gManager);

        if (gManager.screen == GAMEPLAY)
            gpManager.GameplayLogic(&gManager);   
    


        // DRAW
        //----------------------------------------------------------------------------------
        BeginDrawing();
        screenManager.ScreenDrawer(&gManager);



     

        



        EndDrawing();
        //----------------------------------------------------------------------------------
        gManager.gameTime++;
  
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    gManager.UnloadData();

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}