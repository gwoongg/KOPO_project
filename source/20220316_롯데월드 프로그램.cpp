#include <stdio.h>

int main()
{
	int ticketSelect, num, wooDae;
	long long int juminnum;
	char gender;
	const int ADULT_DAY_PRICE = 56000, ADULT_NIGHT_PRICE = 45000,
		    TEEN_DAY_PRICE = 50000, TEEN_NIGHT_PRICE = 40000,
		    CHILD_DAY_PRICE = 46000, CHILD_NIGHT_PRICE = 35000,
		    BABY_DAY_PRICE = 15000, BABY_NIGHT_PRICE = 15000;
	const int MAX_NUM = 10, MIN_NUM = 1;	

	printf("������ �����ϼ���.\n");
	printf("1. 1day\n");
	printf("2. After4\n");
	scanf("%d", &ticketSelect);
		if (ticketSelect == 1 || ticketSelect == 2){
			;;		
	    }
		else
		{
			printf("�߸��� �Է��Դϴ�.(error)\n");
			return 0;
		}
	
	const long long int FULL_DIGIT = 10000000000000,
				    FULL_DIGIT_MIN = 10000000000, 
				    SEVEN_DIGIT = 1000000;
	
	const int TWO_DIGIT = 100, ONE_DIGIT = 10,
		    OLD_GENERATION = 1900, NEW_GENERATION = 2000,
		    MALE_OLD = 1, FEMALE_OLD = 2, MALE_NEW = 3, FEMALE_NEW = 4,
		    BEFORE_BIRTH = 2, AFTER_BIRTH = 1;

	printf("�ֹι�ȣ�� �Է��ϼ���.(�� : - ���� �Է�)\n");
	scanf("%lld", &juminnum);
		if((juminnum >= FULL_DIGIT_MIN) && (juminnum < FULL_DIGIT)){
            ;;
	    }
		else
		{
			printf("�߸��� �Է��Դϴ�.(error)\n");
			return 0;
		}
    
	printf("�� ���� �ֹ��Ͻðڽ��ϱ�?\n");
	scanf("%d", &num);
	    if((num <= MAX_NUM) && (num >= MIN_NUM)){
			;;
		}
		else
		{
			printf("�߸��� �Է��Դϴ�.(error)\n");
			return 0;
		}
	
	printf("�������� �����ϼ���.\n");
	printf("1. ���� (���̿��� �ڵ�ó��)\n");
	printf("2. ����� ���\n");
	printf("3. �ް��庴 ���\n");
	printf("4. �ӻ�� ���\n");
	printf("5. �ٵ��� �ູī�� ���\n");
	scanf("%d", &wooDae);
	    if(wooDae >= 1 && wooDae <= 5)
		{
			;;
		}
		else
		{
			printf("�߸��� �Է��Դϴ�.(error)\n");
			return 0;
		}
	int priceResult;
	printf("\n\n������ %d �� �Դϴ�.\n");
	printf("�����մϴ�.\n\n");

	return 0; 
}
