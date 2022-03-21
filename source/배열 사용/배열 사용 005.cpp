#include<stdio.h>

int main()
{
	int decimal = 13;
	int binary[20] = {0,};
	
	int position = 0;
	
	while (decimal != 0){
		binary[position] = decimal % 2;
		decimal = decimal / 2;
		
		position++;
	}
	//  아래와도 같은 식
	// 	while (1){
	//	binary[position] = decimal % 2;
	//	decimal = decimal / 2;
	//	
	//	position++;	
    //  if(decimal == 0)
	//	break;
	for(int index = position -1; index >= 0; index--){
		printf("%d\n", binary[index]);
	}
	printf("\n");
	
	return 0;
}
