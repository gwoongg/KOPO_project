#include <stdio.h>

int main()
{
	int A[10][10] = {
		{ 0, 0, 0, 0, 0, 0},
		{ 0, 3, 4, 8, 2, 5},
		{ 0, 5, 5, 8, 1, 2},
		{ 0, 6, 8, 4, 2, 3},
		{ 0, 1, 5, 8, 4, 4},
		{ 0, 5, 5, 4, 2, 1}
	};
	
	int B[10][10] = {
	    { 0, 0, 0, 0, 0, 0},
	    { 0, 1, 5, 2, 1, 5},
	    { 0, 3, 2, 3, 3, 3},
	    { 0, 4, 1, 4, 3, 2},
	    { 0, 4, 5, 1, 2, 1},
	    { 0, 2, 1, 1, 5, 4}
	};
	int AB[10][10] = { 0,};	
	//AB[1][1] = A[1][1] * B[1][1] + A[1][2] * B[2][1];
	//AB[1][2] = A[1][1] * B[1][2] + A[1][2] * B[2][2];
	//AB[2][1] = A[2][1] * B[1][1] + A[2][2] * B[2][1];
	//AB[2][2] = A[2][1] * B[1][2] + A[2][2] * B[2][2];
	
	for(int i = 1; i <= 5; i ++){
		for(int j = 1; j <= 5; j ++){
			for(int k = 1; k <= 5; k ++){
			    AB[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	printf("AB = \n");
	for(int index = 1; index <= 5; index ++){
		for(int index2 = 1; index2 <= 5; index2 ++){
			printf("%d ", AB[index][index2]);
		}
		printf("\n");
	}


	return 0;
}
