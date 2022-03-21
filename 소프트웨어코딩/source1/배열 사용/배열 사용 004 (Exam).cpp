#include <stdio.h>

int main()
{
	int student = 0;
	int subject = 0;
	int score[21][10] = {0};
	
	printf("과목 수 입력 : ");
	scanf("%d", &subject);
	
	printf("학생 수 입력 : ");
	scanf("%d", &student);
	
	for(int index = 1; index <= student; index ++){
		for(int index2 = 0){
		printf("koposw%d 학생의 점수 %d개를 차례대로 입력하세요 : ", index, index2);
		scanf("%d", score[index][index2]);
	    }
	}
	
	

	return 0;
	
 } 
