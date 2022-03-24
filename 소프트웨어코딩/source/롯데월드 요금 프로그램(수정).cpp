#include <stdio.h>
#include <time.h>

int ticketCase, ticketCount, disCount, manAge,
	ticketPrice, totalTicketPrice,
	todayDate, yyyymmdd, ageCase, 
	idFront, idFrontMonth, idFrontDay, idBack, idBackFirst,
	nextCustomer, again;
	
int counter = 0;
	
const int DAY_ADULT = 56000, DAY_TEEN = 50000, DAY_KID = 46000, DAY_BABY = 15000,
    	  AFTER4_ADULT = 45000, AFTER4_TEEN = 40000, AFTER4_KID = 35000, AFTER4_BABY = 15000,
    	  OLDMAN_AGE = 65, TEEN_AGE_MAX = 18, TEEN_KID_AGE = 13, KID_BABY_AGE = 3, BABY_AGE_MIN = 1;

// 권종 선택 
void selectTicket(){
	do {
			printf("\n권종을 선택하세요.\n");
			printf("1. 1day\n2. After4(오후 4시부터 입장)\n");
			scanf("%d", &ticketCase);
			
			if (ticketCase >2) {
				printf("잘못된 입력입니다.\n\n");
			}
		} while(ticketCase >2) ;
		
}
//주민번호 입력
void juminNum(){
	do {
		printf("\n주민등록번호를 입력해주세요.(ex. 910902 1011000)\n");
		scanf("%6d %7d", &idFront, &idBack);
		
		idBackFirst = idBack / 1000000;
		idFrontMonth = (idFront / 100) %100;
		idFrontDay = idFront%100;
		if(idBackFirst > 4 || idBackFirst < 1 || idFrontDay > 31 || idFrontDay < 1 || idFrontMonth > 12 ||
				idFrontDay < 1 || idBack > 9999999 || idFront > 999999 ||(idFrontMonth = 2 && idFrontDay>29)) {
			printf("잘못된 입력입니다.\n\n");
		}
	} 
		while(idBackFirst > 4 || idBackFirst < 1 || idFrontDay > 31 || idFrontDay < 1 || idFrontMonth > 12 ||
				idFrontDay < 1 || idBack > 9999999 || idFront > 999999 ||(idFrontMonth = 2 && idFrontDay > 29)) ;
	}
//우대사항 선택
void ticketSu(){
	do {
		printf("\n몇 장을 주문하시겠습니까? (최대 10장)\n");
		scanf("%d", &ticketCount);
		
		if ( ticketCount > 10 ){
			printf("잘못된 입력입니다.\n\n");
		} 
	}
		while(ticketCount>10) ;
}
void selectDiscount(){
	do {	
		printf("\n우대사항은 선택해주세요.\n");
		printf("1.없음(나이우대는 자동처리)\n2.장애인 우대\n");
		printf("3.휴가장병 우대\n4.임산부 우대\n5.다둥이 행복카드 우대\n");
		scanf("%d",&disCount);
		
		if ( disCount > 5 ){
			printf("잘못된 입력입니다.\n\n");
		} 
	} 
		while(disCount > 5) ;
}
void ageCasePrice(){
	if(ageCase == 1){ 
		if (ticketCase == 1){
			ticketPrice= DAY_ADULT;}
		else if(ticketCase ==2){
			ticketPrice= AFTER4_ADULT;}
		} 
	else if( ageCase == 2){ 
		if (ticketCase == 1){
			ticketPrice=DAY_TEEN;}
		else if (ticketCase==2){
			ticketPrice=AFTER4_TEEN;}
	}
	else if( ageCase == 3){
		if (ticketCase == 1){
			ticketPrice=DAY_KID;
		} else if (ticketCase==2){
			ticketPrice=AFTER4_KID;}
	}
	else if(ageCase == 5){
		if (ticketCase == 1){
			ticketPrice=DAY_KID;
		} else if (ticketCase==2){
			ticketPrice=AFTER4_KID;}
	}
	else{
		if (ticketCase == 1) {
			ticketPrice=DAY_BABY;
		} else if (ticketCase ==2){
			ticketPrice=AFTER4_BABY;}
	}
	
	if ( manAge == 0) {
		ticketPrice = 0;
		ageCase = 6;
	} 
}	
void disCountPer(){
	if (disCount == 1) {
			ticketPrice = ticketPrice;
		} else if (disCount == 2) {
			ticketPrice = ticketPrice * 0.5; 
		} else if (disCount == 3) {
			ticketPrice = ticketPrice * 0.51;
		} else if (disCount == 4) {
			ticketPrice = ticketPrice * 0.5;
		} else if (disCount == 5) {
			ticketPrice = ticketPrice * 0.7;
		}
}
void ageCaseselect(){
	if ( manAge <KID_BABY_AGE && manAge >=BABY_AGE_MIN) { 
		ageCase=4; // 베이비 
	} else if ((manAge >= KID_BABY_AGE && manAge <TEEN_KID_AGE)) {
		ageCase = 3; // 어린이 
	} else if (manAge >= TEEN_KID_AGE && manAge <= TEEN_AGE_MAX) {
		ageCase = 2; //청소년 
	} else if ( manAge >= OLDMAN_AGE ) {
		ageCase = 5; //노 인  
	} else {
		ageCase = 1; //어른 
	}				
}
FILE *filePointer = fopen("report.csv","a");

	int ticketCaseArr[20] = {0};
	int disCountArr[20] = {0};
	int ageCaseArr[20] = {0};
	int ticketPriceArr[20] = {0};
	int ticketCountArr[20] = {0};
	
void printResult(){
	
	for (int i =0; i < counter; i++) {
	//파일로 출력 
	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);
	
	fprintf(filePointer,"%d, %d, %d, %d, %d, %d, %d\n",
						t->tm_year + 1900,t->tm_mon + 1, t->tm_mday,
						ticketCaseArr[i], ageCaseArr[i], disCountArr[i], ticketPriceArr[i]);
	
						
	switch (ticketCaseArr[i]) {
		case 1:
			printf("%s\t\t","1Day");
			break;
		case 2:
			printf("%s\t\t","After4");
			break;
		default:
			break;
	}
	
	switch (ageCaseArr[i]) {
		case 1:
			printf("%s","어  른");
			break;
		case 2:
			printf("%s","청소년");
			break;
		case 3:
			printf("%s","어린이");
			break;
		case 4:
			printf("%s","유  아");
			break;
		case 5:
			printf("%s","노  인");
			break;
		case 6:
			printf("%s","영  아");
			break;
		default:
			break;
	}
	
	printf("%10d%14d원\t",ticketCountArr[i], ticketPriceArr[i]) ;
	
	switch (disCountArr[i]) {
		case 1:
			printf("%s\n","없음");
			break;
		case 2:
			printf("%s\n","장애인 우대");
			break;
		case 3:
			printf("%s\n","휴가장병 우대");
			break;
		case 4:
			printf("%s\n","임산부 우대");
			break;
		case 5:
			printf("%s\n","다둥이 행복카드 우대");
			break;
		default:
			break;
	}
}
}


void toDay(){
	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);
	
	todayDate= (t->tm_year + 1900)*10000 + (t->tm_mon + 1)*100 + t->tm_mday;
			

	if (idBackFirst ==3 || idBackFirst == 4) {
		yyyymmdd = idFront + 20000000;
	} else {
		yyyymmdd = idFront + 19000000;
	} 


	manAge = (todayDate - yyyymmdd)/10000;
}


int main () {
	
	const int DAY_ADULT = 56000, DAY_TEEN = 50000, DAY_KID = 46000, DAY_BABY = 15000,
	    	  AFTER4_ADULT = 45000, AFTER4_TEEN = 40000, AFTER4_KID = 35000, AFTER4_BABY = 15000,
	    	  OLDMAN_AGE = 65, TEEN_AGE_MAX = 18, TEEN_KID_AGE = 13, KID_BABY_AGE = 3, BABY_AGE_MIN = 1;

	//시간 불러오기 

	do {

		do {
			printf("======================= 롯데월드 이용권 구매 =======================\n") ;
			
			// 권종 선택 
			selectTicket();
			
			//주민번호 입력
			juminNum();
			
			//구매권 매수
			ticketSu();
			
			//우대사항 선택
			selectDiscount();

			toDay();
			
			ageCaseselect();
	
			ageCasePrice();
		
			disCountPer();

			ticketPrice *= ticketCount;
			
			if (ticketPrice == 0){
				printf("\n무료 입장 입니다.\n");
			}
			else {
				printf ("\n%d매의 총 금액은 %d원 입니다.\n", ticketCount, ticketPrice);
			}
			

			ticketCaseArr[counter] = ticketCase;
			disCountArr[counter] = disCount;
			ageCaseArr[counter] = ageCase;
			ticketPriceArr[counter] = ticketPrice;
			ticketCountArr[counter] = ticketCount;
			totalTicketPrice += ticketPrice; 
			
			counter ++;
			
			printf("\n계속 진행\n1.예\n2.아니요\n");
			scanf("%d", &again); 
			
			//변수 초기화
			ticketCase = 0, disCount = 0, ticketCase = 0,
				idFront = 0, idBack = 0, ageCase = 0, ticketPrice = 0;  

		} while(again == 1);
		
		printf("\n이용해주셔서 감사합니다.\n");

		printf("\n\n============================ 롯데월드 ============================\n") ;
		printf("%s\t%s\t     %s\t  %s\t\t%s\n\n","선택권종","연  령","매수","가격","우대사항");
		
		printResult();
		
		printf("\n입장료 총액은 %d 원 입니다.", totalTicketPrice);
		printf("\n==================================================================\n");
    	printf("\n새로운 주문을 받겠습니까?\n1.예\n2.종료\n");
		scanf("%d",&nextCustomer);

	counter = 0;
	totalTicketPrice=0;
		
	} while(nextCustomer == 1);
	
	return 0; 
}
