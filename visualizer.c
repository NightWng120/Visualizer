#include "raylib.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

int * copy(int * input, int length){
	int * copy = (int*)malloc(length * sizeof(int));
	int * start = copy;


	*copy = *input;
	copy++, input++;

	while(length > 1){
		//printf("Length: %d", length);
		*copy = *input;
		copy++, input++, length--;
	}

	return start;
}

bool sorted_array(int * ptr, int size){
	for(int i = 0; i < size; i++){
		if(i < 199 && ptr[i] > ptr[i + 1]){
			return false;
		}
	}
	return true;
}

int * mergeSort(int * ptr, int size, int screenWidth, int screenHeight, int start, int length){
	int * temp = ptr;
	int * A;
	int * B;
	int * startA;
	int * startB;
	int lenB = 0;
	int lenA = 0;
	int i = 0;
	int j = 0;
	//printf("\n\n-----------------------\nFirst element of current ptr: %d\nLength: %d\n-----------------------\n\n", *ptr, n);

	if(size< 2){
		//printf("\nReturned ptr\n");
		return ptr;
	}

	else if(size%2 == 1){
		//printf("\n\n-----------------------\nFirst element of current ptr: %d\nLength: %d\n-----------------------\n\n", *ptr, n);
		lenA = (size- 1)/2;
		lenB = (size- 1)/2 + 1;
		A = mergeSort(copy(ptr, lenA), lenA, screenWidth, screenHeight, start, length);
		startA = A;
		B = mergeSort(copy(ptr + lenA, lenB), lenB, screenWidth, screenHeight, start, length);
		startB = B;
	}

	else{
		//printf("\n\n-----------------------\nFirst element of current ptr: %d\nLength: %d\n-----------------------\n\n", *ptr, n);
		lenA = size/2;
		lenB = size/2;
		A = mergeSort(copy(ptr, lenA), lenA, screenWidth, screenHeight, start, length);
		startA = A;
		B = mergeSort(copy(ptr + lenB, lenB), lenB, screenWidth, screenHeight, start, length);
		startB = B;
	}

	for(int k = 0; k < size; k++){
		if(A == NULL){

			*temp = *B;
			if(j + 1 == lenB) B = NULL;
			else j++, B++;
		}

		else if(B == NULL){

			*temp = *A;
			if(i + 1 == lenA) A = NULL;
			else i++, A++;
		}

		else if(A != NULL && *A < *B){
			*temp = *A;
			if(i + 1 == lenA) A = NULL;
			else i++, A++;

		}

		else if(B != NULL && *B < *A){
			*temp = *B;
			if(j + 1 == lenB) B = NULL;
			else j++, B++;

		}

		else if(*B == *A){
			*temp = *B;
			if(j + 1 == lenB) B = NULL;
			else j++, B++;
		}

		temp++;
	}

	free(startA);
	free(startB);
	return ptr;

}

int algoPicker(int * ptr, int size, int select, int screenWidth, int screenHeight, int start, int length){
	if(select == 1){
		Color red = {219, 19, 4, 255};
		bool loop = true;
		for(int k = 0; k < size; k++){
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
				DrawRectangle(screenWidth/4*2 - start, screenHeight - ptr[k], 5, ptr[k], red);
			else
				DrawRectangle(screenWidth/4*2 - start, screenHeight - ptr[k], 5, ptr[k], YELLOW);
			start -= 7;
		}
	}
	//else if(select == 2){
	//}
	//else if(select == 3){
	//}
	//else if(select == 4){
	//}
	return length;
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
		if(r > 0)
			ptr[i] = r;
		else
			ptr[i] = 1;
		r = rand()%100;

	}

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Test");


    SetTargetFPS(480);               // Set our game to run at 60 frames-per-second
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

			length = algoPicker(ptr, 100, 1, screenWidth, screenHeight, start, length);

			//for(int k = 0; k < 100; k++){
			//	if(loop){
			//		//I could just add a function call here that chooses the desired sorting algorithm
			//		if(ptr[length] > ptr[length + 1]){
			//			int temp = ptr[length + 1];
			//			ptr[length + 1] = ptr[length];
			//			ptr[length] = temp;
			//		}
			//		if(length+1 < 100)
			//			length++;
			//		else if(sorted_array(ptr, 100) == false){
			//			length = 0;
			//		}
			//		loop = false;
			//	}

			//	if(sorted_array(ptr,100))
			//		DrawRectangle(screenWidth/4*2 - start, screenHeight - ptr[k], 5, ptr[k], GREEN);
			//	else if(k == length)
			//		DrawRectangle(screenWidth/4*2 - start, screenHeight - ptr[k], 5, ptr[k], RED);
			//	else
			//		DrawRectangle(screenWidth/4*2 - start, screenHeight - ptr[k], 5, ptr[k], WHITE);
			//	start -= 7;
			//}

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
