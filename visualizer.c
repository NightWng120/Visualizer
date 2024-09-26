#include "raylib.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
bool sorted_array(int * ptr, int size){
	for(int i = 0; i < size; i++){
		if(i < 199 && ptr[i] > ptr[i + 1]){
			return false;
		}
	}
	return true;
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1500;
    const int screenHeight = 800;
	bool sorted = false;
	int * ptr = malloc(sizeof(int) * 100);
	srand(time(NULL));
	int r = rand()%100;
	int length = 0;
	for(int i = 0; i < 100; i++){
		ptr[i] = r;
		r = rand()%100;
	}

    InitWindow(screenWidth, screenHeight, "Test");


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

			int start = 745;
			int loop = true;
			//for(int i = 0; i < 100; i++){
			//	for(int j = 0; j < 100; j++){
			//		if(ptr[i] > ptr[i + 1]){
			//			int temp = ptr[i + 1];
			//			ptr[i + 1] = ptr[i];
			//			ptr[i] = temp;

			//		}


			//	}
			//}
			for(int k = 0; k < 100; k++){
				if(loop){
					//I could just add a function call here that chooses the desired sorting algorithm
					if(ptr[length] > ptr[length + 1]){
						int temp = ptr[length + 1];
						ptr[length + 1] = ptr[length];
						ptr[length] = temp;
					}
					if(length+1 < 100)
						length++;
					else if(sorted_array(ptr, 100) == false){
						length = 0;
					}
					loop = false;
				}

				if(sorted_array(ptr,100))
					DrawRectangle(screenWidth/4*2 - start, screenHeight - ptr[k], 5, ptr[k], GREEN);
				else if(k == length)
					DrawRectangle(screenWidth/4*2 - start, screenHeight - ptr[k], 5, ptr[k], RED);
				else
					DrawRectangle(screenWidth/4*2 - start, screenHeight - ptr[k], 5, ptr[k], WHITE);
				start -= 7;
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
