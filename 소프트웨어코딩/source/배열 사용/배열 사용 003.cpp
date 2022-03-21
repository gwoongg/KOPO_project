#include <stdio.h>

int main()
{
	int numArr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110};
	int sum = 0;
	
	for(int index = 0; index <= 9 ; index++)
	{
		numArr[index] *= 2;
	}
	for(int index = 0; index <= 9 ; index++)
	{
		printf("%d\n", numArr[index]);
	}

	
	return 0;
	
 } 
