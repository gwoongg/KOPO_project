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
	    printf("권종을 선택하세요.\n");
	    printf("1. 1day\n");
	    printf("2. After4(오후 4시부터 입장)\n");
		scanf("%d", &ticketSelect);
		if (ticketSelect == 1 || ticketSelect == 2){
			break;		
	    }
		else
		{
			printf("잘못된 입력입니다.\n\n");
		}
    }
    
    while(true){
	    printf("주민번호를 입력하세요.(- 제외 입력)\n");
	    scanf("%lld", &juminnum);
		    if((juminnum >= FULL_DIGIT_MIN) && (juminnum < FULL_DIGIT)){
                break;
	        }
		    else
		    {
			printf("잘못된 입력입니다.\n\n");
		    }
    }
    while(true){
	    printf("몇 장을 주문하시겠습니까? (최대 10장)\n");
	    scanf("%d", &num);
	        if((num <= MAX_NUM) && (num >= MIN_NUM)){
			    break;
		    }
		    else
		    {
			printf("잘못된 입력입니다.\n\n");
		    }
    }
    while(true){
	    printf("우대사항을 선택하세요.\n");
	    printf("1. 없음 (나이우대는 자동처리)\n");
	    printf("2. 장애인 우대\n");
	    printf("3. 휴가장병 우대\n");
	    printf("4. 임산부 우대\n");
	    printf("5. 다둥이 행복카드 우대\n");
	    scanf("%d", &wooDae);
	        if(wooDae >= 1 && wooDae <= 5){
			    break;
		    }
		    else
		    {
			printf("잘못된 입력입니다.\n\n");
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
	
	printf("\n\n가격은 %d 원 입니다.\n", priceResult * num);
	printf("감사합니다.\n\n");

	return 0; 
}
