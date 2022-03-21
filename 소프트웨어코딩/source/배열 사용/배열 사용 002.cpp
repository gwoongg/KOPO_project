#include <stdio.h>

int main()
{
	int numArr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110};
	int sum = 0;
	
	for(int index = 0; index <= 9 ; index++)
	{
		sum += numArr[index];
	}
	
	printf("ÃÑ ÇÕ : %d\n", sum);
	
	return 0;
	
 } 
