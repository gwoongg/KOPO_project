#include <stdio.h>
#include <time.h>

int main()
{
	int ticketSelect, num, wooDae, todayYMD;
    int year, month, day;
	long long int juminnum;
	char gender;
	const int ADULT_DAY_PRICE = 56000, ADULT_NIGHT_PRICE = 45000,
		    TEEN_DAY_PRICE = 50000, TEEN_NIGHT_PRICE = 40000,
		    CHILD_DAY_PRICE = 46000, CHILD_NIGHT_PRICE = 35000,
		    BABY_DAY_PRICE = 15000, BABY_NIGHT_PRICE = 15000,
		    FREE_DAY_PRICE = 0, FREE_NIGHT_PRICE = 0;
	const int MAX_NUM = 10, MIN_NUM = 1;	

    todayYMD = year + month + day;
    struct tm *today;
	time_t timer;
	time(&timer);
	
	today = localtime(&timer);
	
	timer = time(NULL);

	year = (today -> tm_year - 100) * 10000;
	month = (today -> tm_mon + 1) * 100;
	day = today -> tm_mday;
	
	const long long int FULL_DIGIT = 10000000000000,
				    FULL_DIGIT_MIN = 10000000000;
				   
	int age, generation;
	
	age = (todayYMD - (juminnum/10000000))/10000;
	
	if(((juminnum % 10000000) >= 1000000) && ((juminnum % 10000000) < 2000000 )){
		generation = 1;	
	}
	else if(((juminnum % 10000000) >= 2000000) && ((juminnum % 10000000) < 3000000 )){
		generation = 2;	
	}
	else if(((juminnum % 10000000) >= 3000000) && ((juminnum % 10000000) < 4000000 )){
		generation = 3;
	}
	else if(((juminnum % 10000000) >= 4000000) && ((juminnum % 10000000) < 5000000 )){
		generation = 4;
	}
	
	if((generation == 1) || (generation == 2)){
		age = age + 100;
	} 
	
	while(true){
	    printf("������ �����ϼ���.\n");
	    printf("1. 1day\n");
	    printf("2. After4(���� 4�ú��� ����)\n");
		scanf("%d", &ticketSelect);
		if (ticketSelect == 1 || ticketSelect == 2){
			break;		
	    }
		else
		{
			printf("�߸��� �Է��Դϴ�.\n\n");
		}
    }
    
    while(true){
	    printf("�ֹι�ȣ�� �Է��ϼ���.(- ���� �Է�)\n");
	    scanf("%lld", &juminnum);
		    if((juminnum >= FULL_DIGIT_MIN) && (juminnum < FULL_DIGIT)){
                break;
	        }
		    else
		    {
			printf("�߸��� �Է��Դϴ�.\n\n");
		    }
    }
    while(true){
	    printf("�� ���� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��)\n");
	    scanf("%d", &num);
	        if((num <= MAX_NUM) && (num >= MIN_NUM)){
			    break;
		    }
		    else
		    {
			printf("�߸��� �Է��Դϴ�.\n\n");
		    }
    }
    while(true){
	    printf("�������� �����ϼ���.\n");
	    printf("1. ���� (���̿��� �ڵ�ó��)\n");
	    printf("2. ����� ���\n");
	    printf("3. �ް��庴 ���\n");
	    printf("4. �ӻ�� ���\n");
	    printf("5. �ٵ��� �ູī�� ���\n");
	    scanf("%d", &wooDae);
	        if(wooDae >= 1 && wooDae <= 5){
			    break;
		    }
		    else
		    {
			printf("�߸��� �Է��Դϴ�.\n\n");
		    }
    }
    
    int priceResult;
    
    if(ticketSelect == 1){ 
		if(age < 1){
			priceResult = FREE_DAY_PRICE;
		} 
		else if((age >= 1) && (age < 3)){
			priceResult = BABY_DAY_PRICE; 
		}
		else if((age >= 3) && (age < 13)){
			priceResult = CHILD_DAY_PRICE;
		}
		else if((age >= 13) && (age < 18)){
			priceResult = TEEN_DAY_PRICE; 
		}
		else if(age >= 65){
			priceResult = CHILD_DAY_PRICE; 
		}
		else{
			priceResult = ADULT_DAY_PRICE;
		} 	
	}
	if(ticketSelect == 2){
		if(age < 1){
			priceResult = FREE_NIGHT_PRICE;
		} 
		else if((age >= 1) && (age < 3)){
			priceResult = BABY_NIGHT_PRICE;  
		}
		else if((age >= 3) && (age < 13)){
			priceResult = CHILD_NIGHT_PRICE;
		}
		else if((age >= 13) && (age < 18)){
			priceResult = TEEN_NIGHT_PRICE; 
		}
		else if(age >= 65){
			priceResult = CHILD_NIGHT_PRICE; 
		}
		else{
			priceResult = ADULT_NIGHT_PRICE;
		}
	}
	
	if(wooDae == 2){
		priceResult = priceResult * 0.5; 
	}
	if((wooDae == 3)){ 
		priceResult = priceResult * 0.51;
	} 
	 
	if((wooDae == 4)){
		priceResult = priceResult * 0.5;
	} 
		
	if((wooDae == 5)){
		priceResult = priceResult * 0.7;
	} 	
	
	printf("\n\n������ %d �� �Դϴ�.\n", priceResult * num);
	printf("�����մϴ�.\n\n");

	return 0; 
}
