#include <stdio.h>

int main()
{
	int student = 0;
	int subject = 0;
	int score[21][10] = {0};
	int sum[21] = {0};
	int ave[21] = {0};
	int subjectSum[10] = {0};
	float subjectAve[10]; 
	
	printf("���� �� �Է� : ");
	scanf("%d", &subject);
	printf("�л� �� �Է� : ");
	scanf("%d", &student);
	
	for(int index = 1; index <= student; index ++){
	    printf("koposw%d �л��� ���� %d���� ���ʴ�� �Է��ϼ��� : ", index, subject);
		for(int index2 = 0; index2 < subject; index2 ++){
		scanf("%d", &score[index][index2]);
	    }
	}
	
	for(int index = 1; index <=student; index++) {
		int sum = 0;
		float ave = 0;
		for(int index2 = 0; index2 < subject; index2++) {
			sum += score[index][index2];
			subjectSum[index2] += score[index][index2];
		}
		ave = sum / (float)subject;
		printf("Koposw%d �л��� ���� %d, ��� %5.2f\n", index, sum, ave);
	}
	for(int index = 1; index <= subject; index++) {
		subjectAve[index] = subjectSum[index] / (float)student;
		printf("����%d ��� %5.2f\n", index, subjectAve[index]);
	}
	
	return 0;
	
 } 
