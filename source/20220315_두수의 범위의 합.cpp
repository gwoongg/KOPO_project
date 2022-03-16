#include <stdio.h>

int main()
{
	int i = 1;
	int end;
	int sum = 0;
	
	printf("2개의 정수 입력 : ");
	scanf("%d %d", &i, &end);
	
	 
	while(i <= end){
		if(i != end){
			printf("%d + ", i); // 첫번째 정수가 뒤 정수랑 같지 않을 때 %d + 출력  
		}
		else{
			printf("%d = ", i); // 첫번째 정수가 뒤 정수랑 같아질 때 실행 %d = 출력 
		}
		sum = sum + i;
		i++;
	}
	
	printf("%d\n", sum);
	
	return 0;
}
