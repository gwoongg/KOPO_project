#include <stdio.h>

int main()
{
	int i = 1;
	int end;
	int sum = 0;
	
	printf("2���� ���� �Է� : ");
	scanf("%d %d", &i, &end);
	
	 
	while(i <= end){
		if(i != end){
			printf("%d + ", i); // ù��° ������ �� ������ ���� ���� �� %d + ���  
		}
		else{
			printf("%d = ", i); // ù��° ������ �� ������ ������ �� ���� %d = ��� 
		}
		sum = sum + i;
		i++;
	}
	
	printf("%d\n", sum);
	
	return 0;
}
