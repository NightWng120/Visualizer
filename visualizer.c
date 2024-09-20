#include "raylib.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1500;
    const int screenHeight = 800;
	int * ptr = malloc(sizeof(int) * 200);
	srand(time(NULL));
	int r = rand()%200;
	for(int i = 0; i < 200; i++){
		ptr[i] = r;
		r = rand()%200;
	}

    InitWindow(screenWidth, screenHeight, "Test");


    SetTargetFPS(30);               // Set our game to run at 60 frames-per-second
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

			int start = 745;
			for(int k = 0; k < 200; k++){
				DrawRectangle(screenWidth/4*2 - start, screenHeight - ptr[k], 5, ptr[k], WHITE);
				start -= 7;
			}
			for(int i = 0; i < 200; i++){
				for(int j = 0; j < 200; j++){
					if(ptr[i] > ptr[i + 1]){
						int temp = ptr[i + 1];
						ptr[i + 1] = ptr[i];
						ptr[i] = temp;

					}


				}
			}

			//The difference between columns is 7
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
