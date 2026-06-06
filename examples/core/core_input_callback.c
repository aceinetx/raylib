/*******************************************************************************************
*
*   raylib [core] example - input callback
*
*   Example complexity rating: [★★☆☆] 2/4
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2014-2026 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

int key = 0, action = 0;
Vector2 mousePos = {0};

void KeyCallback(int key_, int action_){
    key = key_;
    action = action_;
}

void MouseMotionCallback(Vector2 pos){
    mousePos = pos;
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - input callback");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    
    // Setup input
    SetKeyboardInputCallback(KeyCallback);
    SetMouseMoveCallback(MouseMotionCallback);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText(TextFormat("Key: %d; Action: %d; Mouse pos: %f, %f;", key, action, mousePos.x, mousePos.y), 10, 10, 20, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
