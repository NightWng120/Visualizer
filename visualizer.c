#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1500;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Test");

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);

            DrawText("Dem some rectangles", 10, 10, 20, DARKGRAY);
            DrawRectangle(screenWidth/4*2 - 745, 545, 5, 255, WHITE);
            DrawRectangle(screenWidth/4*2 - 735, 565, 5, 235, WHITE);
            DrawRectangle(screenWidth/4*2 - 725, 585, 5, 215, GREEN);
            DrawRectangle(screenWidth/4*2 - 715, 605, 5, 195, WHITE);
            DrawRectangle(screenWidth/4*2 - 705, 625, 5, 175, RED);
			//DrawRectangle(int posX, int posY, int width, int height, Color color)
			/*                             ^                     ^
			 * Increase with negative height change              |
			 *                                     Decrease with negative height change
			 */


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
