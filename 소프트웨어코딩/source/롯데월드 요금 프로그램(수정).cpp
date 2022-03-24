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

// ���� ���� 
void selectTicket(){
	do {
			printf("\n������ �����ϼ���.\n");
			printf("1. 1day\n2. After4(���� 4�ú��� ����)\n");
			scanf("%d", &ticketCase);
			
			if (ticketCase >2) {
				printf("�߸��� �Է��Դϴ�.\n\n");
			}
		} while(ticketCase >2) ;
		
}
//�ֹι�ȣ �Է�
void juminNum(){
	do {
		printf("\n�ֹε�Ϲ�ȣ�� �Է����ּ���.(ex. 910902 1011000)\n");
		scanf("%6d %7d", &idFront, &idBack);
		
		idBackFirst = idBack / 1000000;
		idFrontMonth = (idFront / 100) %100;
		idFrontDay = idFront%100;
		if(idBackFirst > 4 || idBackFirst < 1 || idFrontDay > 31 || idFrontDay < 1 || idFrontMonth > 12 ||
				idFrontDay < 1 || idBack > 9999999 || idFront > 999999 ||(idFrontMonth = 2 && idFrontDay>29)) {
			printf("�߸��� �Է��Դϴ�.\n\n");
		}
	} 
		while(idBackFirst > 4 || idBackFirst < 1 || idFrontDay > 31 || idFrontDay < 1 || idFrontMonth > 12 ||
				idFrontDay < 1 || idBack > 9999999 || idFront > 999999 ||(idFrontMonth = 2 && idFrontDay > 29)) ;
	}
//������ ����
void ticketSu(){
	do {
		printf("\n�� ���� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��)\n");
		scanf("%d", &ticketCount);
		
		if ( ticketCount > 10 ){
			printf("�߸��� �Է��Դϴ�.\n\n");
		} 
	}
		while(ticketCount>10) ;
}
void selectDiscount(){
	do {	
		printf("\n�������� �������ּ���.\n");
		printf("1.����(���̿��� �ڵ�ó��)\n2.����� ���\n");
		printf("3.�ް��庴 ���\n4.�ӻ�� ���\n5.�ٵ��� �ູī�� ���\n");
		scanf("%d",&disCount);
		
		if ( disCount > 5 ){
			printf("�߸��� �Է��Դϴ�.\n\n");
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
		ageCase=4; // ���̺� 
	} else if ((manAge >= KID_BABY_AGE && manAge <TEEN_KID_AGE)) {
		ageCase = 3; // ��� 
	} else if (manAge >= TEEN_KID_AGE && manAge <= TEEN_AGE_MAX) {
		ageCase = 2; //û�ҳ� 
	} else if ( manAge >= OLDMAN_AGE ) {
		ageCase = 5; //�� ��  
	} else {
		ageCase = 1; //� 
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
	//���Ϸ� ��� 
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
			printf("%s","��  ��");
			break;
		case 2:
			printf("%s","û�ҳ�");
			break;
		case 3:
			printf("%s","���");
			break;
		case 4:
			printf("%s","��  ��");
			break;
		case 5:
			printf("%s","��  ��");
			break;
		case 6:
			printf("%s","��  ��");
			break;
		default:
			break;
	}
	
	printf("%10d%14d��\t",ticketCountArr[i], ticketPriceArr[i]) ;
	
	switch (disCountArr[i]) {
		case 1:
			printf("%s\n","����");
			break;
		case 2:
			printf("%s\n","����� ���");
			break;
		case 3:
			printf("%s\n","�ް��庴 ���");
			break;
		case 4:
			printf("%s\n","�ӻ�� ���");
			break;
		case 5:
			printf("%s\n","�ٵ��� �ູī�� ���");
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

	//�ð� �ҷ����� 

	do {

		do {
			printf("======================= �Ե����� �̿�� ���� =======================\n") ;
			
			// ���� ���� 
			selectTicket();
			
			//�ֹι�ȣ �Է�
			juminNum();
			
			//���ű� �ż�
			ticketSu();
			
			//������ ����
			selectDiscount();

			toDay();
			
			ageCaseselect();
	
			ageCasePrice();
		
			disCountPer();

			ticketPrice *= ticketCount;
			
			if (ticketPrice == 0){
				printf("\n���� ���� �Դϴ�.\n");
			}
			else {
				printf ("\n%d���� �� �ݾ��� %d�� �Դϴ�.\n", ticketCount, ticketPrice);
			}
			

			ticketCaseArr[counter] = ticketCase;
			disCountArr[counter] = disCount;
			ageCaseArr[counter] = ageCase;
			ticketPriceArr[counter] = ticketPrice;
			ticketCountArr[counter] = ticketCount;
			totalTicketPrice += ticketPrice; 
			
			counter ++;
			
			printf("\n��� ����\n1.��\n2.�ƴϿ�\n");
			scanf("%d", &again); 
			
			//���� �ʱ�ȭ
			ticketCase = 0, disCount = 0, ticketCase = 0,
				idFront = 0, idBack = 0, ageCase = 0, ticketPrice = 0;  

		} while(again == 1);
		
		printf("\n�̿����ּż� �����մϴ�.\n");

		printf("\n\n============================ �Ե����� ============================\n") ;
		printf("%s\t%s\t     %s\t  %s\t\t%s\n\n","���ñ���","��  ��","�ż�","����","������");
		
		printResult();
		
		printf("\n����� �Ѿ��� %d �� �Դϴ�.", totalTicketPrice);
		printf("\n==================================================================\n");
    	printf("\n���ο� �ֹ��� �ްڽ��ϱ�?\n1.��\n2.����\n");
		scanf("%d",&nextCustomer);

	counter = 0;
	totalTicketPrice=0;
		
	} while(nextCustomer == 1);
	
	return 0; 
}
