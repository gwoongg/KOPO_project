#include <stdio.h>

int main()
{
	int student = 0;
	int subject = 0;
	int score[21][10] = {0};
	
	printf("���� �� �Է� : ");
	scanf("%d", &subject);
	
	printf("�л� �� �Է� : ");
	scanf("%d", &student);
	
	for(int index = 1; index <= student; index ++){
		for(int index2 = 0){
		printf("koposw%d �л��� ���� %d���� ���ʴ�� �Է��ϼ��� : ", index, index2);
		scanf("%d", score[index][index2]);
	    }
	}
	
	

	return 0;
	
 } 
