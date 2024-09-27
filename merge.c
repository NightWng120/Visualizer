#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "/home/nightwng120/documents/programming/githubrepos/c-libraries/libraries.h"

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

int * mergeSort(int * array, int n){
	int * temp = array;
	int * A;
	int * B;
	int * startA;
	int * startB;
	int lenB = 0;
	int lenA = 0;
	int i = 0;
	int j = 0;
	//printf("\n\n-----------------------\nFirst element of current array: %d\nLength: %d\n-----------------------\n\n", *array, n);

	if(n < 2){
		//printf("\nReturned array\n");
		return array;
	}

	else if(n%2 == 1){
		//printf("\n\n-----------------------\nFirst element of current array: %d\nLength: %d\n-----------------------\n\n", *array, n);
		lenA = (n - 1)/2;
		lenB = (n - 1)/2 + 1;
		A = mergeSort(copy(array, lenA), lenA);
		startA = A;
		B = mergeSort(copy(array + lenA, lenB), lenB);
		startB = B;
	}

	else{
		//printf("\n\n-----------------------\nFirst element of current array: %d\nLength: %d\n-----------------------\n\n", *array, n);
		lenA = n/2;
		lenB = n/2;
		A = mergeSort(copy(array, lenA), lenA);
		startA = A;
		B = mergeSort(copy(array + lenB, lenB), lenB);
		startB = B;
	}

	for(int k = 0; k < n; k++){
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
	return array;
}
int main(){
	int i = 0;
	int * ptr = malloc(sizeof(int) * 100);
	srand(time(NULL));
	int length = 100;
	int r = rand()%100;
	for(int i = 0; i < 100; i++){
		if(r > 0)
			ptr[i] = r;
		else
			ptr[i] = 1;
		r = rand()%100;

	}
	clock_t start, end;
	double cpu_time_used;

	printArray(ptr, length);
	start = clock();
	int * result = mergeSort(ptr, length);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Merge Sort completed in %f seconds\n", cpu_time_used);
	printArray(ptr, length);
	//printf("Merge Sort completed in %f seconds with %.f inversions\n", cpu_time_used, *inversions);

	//printf("\n");
	//for(i = 0; i < length; i++){
	//	printf("%d, ", result[i]);
	//}
	//printf("\n");

}
