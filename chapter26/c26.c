#include <stdio.h>
#include <stdlib.h>

#define BUF_MAX	1000
#define ADD(A, B, C)	(A+B+C)
#define MULTIPLE(A, B, C)	((A)*(B)*(C))
#define PI 3.141592
#define AREA(R)	((R)*(R)*(PI))
#define BIG(A,B)	((A)>(B)?(A):(B))

void q1(void);
void q1_1(void);
void q1_2(void);
void q1_3(void);

int main(int argc, char**argv){
		
	int nMainQuest = 0;

	if (argc != 2 || *argv[1] < '0' || *argv[1] > '9'){
		printf("enter main question number : ");
		scanf("%d", &nMainQuest);
		getchar();
	}
	else{
		nMainQuest = atoi(argv[1]);
	}
	
	switch (nMainQuest)
	{
	case 1:
		q1();
		break;

	default:
		break;
	}

	return 0;
}	// end of main

void q1(void){
	char chSubQuest[BUF_MAX];
	int nSubQuest = 1;

	do{
		printf("enter sub question number : ");
		scanf("%s", chSubQuest);
		getchar();
	} while (chSubQuest[0] < '0' || chSubQuest[0] > '9');

	nSubQuest = atoi((const char *)chSubQuest);

	switch (nSubQuest)
	{
	case 1:
		q1_1();
		break;

	case 2:
		q1_2();
		break;

	case 3:
		q1_3();
		break;

	default:
		break;
	}

}

void q1_1(void){
	int nNum1 = 0, nNum2 = 0, nNum3 = 0;	// init

	printf("enter three numbers\n");
	scanf("%d %d %d", &nNum1, &nNum2, &nNum3);	// enter numbers
	getchar();
	printf("%d + %d + %d = %d\n", nNum1, nNum2, nNum3, ADD(nNum1,nNum2,nNum3));	// calculate
	printf("%d * %d * %d = %d\n", nNum1, nNum2, nNum3, MULTIPLE(nNum1, nNum2, nNum3));	// calculate
}	// end of q1_1

void q1_2(void){
	double nRadius = 0;	// init
	printf("enter radius : ");
	scanf("%l", &nRadius);	// enter radius
	printf("AREA : %g\n", AREA(nRadius));	// calculate
}	// end of q1_2

void q1_3(void){
	int nNum1 = 0, nNum2 = 0;

	printf("enter numbers\n");
	scanf("%d %d", &nNum1, &nNum2);

	printf("Big : %d", BIG(nNum1, nNum2));
}	// end of q1_3