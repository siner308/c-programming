rmfja// include
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define
#define ARR_MAX 100
#define ZERO 0
#define CNT_Q1 4
#define CNT_Q3 5
#define CNT_Q6 3

// function
void q1(void);
void rotateArr(int(*)[ARR_MAX]);

void q2(void);
void snailByJH(int(*)[ARR_MAX], int);
void snailByBook(int(*)[ARR_MAX], int);

void q3(void);
void garbage(int);

void q4(void);

void q5(void);

void q6(void);

int main(void){
	// init
	int nQuest = 1;

	while (nQuest != ZERO){
		// enter question number
		printf("enter question number (0 to quit)\n");
		scanf("%d", &nQuest);

		switch (nQuest){
		case 1:
			q1();
			break;

		case 2:
			q2();
			break;

		case 3:
			q3();
			break;

		case 4:
			q4();
			break;

		case 5:
			q5();
			break;

		case 6:
			q6();
			break;

		default:
			break;
		}
	}
	return 0;

	// end of main
}

void q1(void){	
	// init
	int Arr[ARR_MAX][ARR_MAX];
	int i = 0, j = 0;
	int nNum = 1;

	// init array
	for (i = 0; i < CNT_Q1; i++){	// 0 to 3
		for (j = 0; j < CNT_Q1; j++){	// 0 to 3
			Arr[i][j] = nNum;	// init
			nNum++;	// numbering ( 1 to 16 )
		}
	}

	// rotate & print
	for (i = 0; i < CNT_Q1; i++){	// rotate 4 times
		rotateArr(Arr);	// rotate & print
		printf("\n");
	}

	printf("\n");
	
	// end of q1
}

void rotateArr(int(*Arr)[ARR_MAX]){
	// init
	int i = 0, j = 0;
	int tempArr[4][4];

	// flip by "y = -x"
	// let's think this array is on the center of 'coordinate system'. (Zero Point is Arr[1.5][1.5]) 
	for (i = 0; i < CNT_Q1; i++){	// 0 to 3
		for (j = 0; j < CNT_Q1; j++){	// 0 to 3
			tempArr[i][j] = Arr[j][i];	// flip
		}
	}

	// flip by "x = 0"
	for (i = 0; i < CNT_Q1; i++){	// 0 to 3
		for (j = 0; j < CNT_Q1; j++){	// 0 to 3
			Arr[i][j] = tempArr[i][3 - j];	// flip
			printf("%2d ", Arr[i][j]);	// print Arr
		}
		printf("\n");
	}	
	
	// end of rotateArr
}	

void q2(void){
	// init size of array
	int i = 0, j = 0;
	int szNum = 0;
	int Arr2[ARR_MAX][ARR_MAX];

	// enter number
	printf("enter number\n");
	scanf("%d", &szNum);	// width of array
	
	// calc
	snailByBook(Arr2, szNum);

	// print
	for (i = 0; i < szNum; i++){
		for (j = 0; j < szNum; j++){
			printf("%10d", Arr2[i][j]);	// print
		}

		printf("\n");
	}

	printf("\n");

	// end of q2
}

void snailByJH(int(*Arr2)[ARR_MAX], int szNum){
	// init
	int i = 0, j = 0;
	int szTemp = szNum;
	int nCnt = szNum, nNum = 1;

	// calc
	while (nCnt > ZERO){	//	j++
		Arr2[i][j] = nNum;	// init
		nCnt--;	// count check
		nNum++;	// numbering
		j++;	// array move
	}

	j--;	// We escaped array, so re-enter.
	szTemp -= 1;	// decrease size
	nCnt = szTemp;	// reset count


	while (nCnt > ZERO){
		while (nCnt > ZERO){	//	i++
			i++;	// array move
			Arr2[i][j] = nNum;	// init
			nCnt--;	// count check
			nNum++;	// numbering
		}

		nCnt = szTemp;	// reset count

		while (nCnt > ZERO){	//	j-- 
			j--;	// array move
			Arr2[i][j] = nNum;	// init
			nCnt--;	// count check
			nNum++;	// numbering
		}

		szTemp -= 1;	// decrease size
		nCnt = szTemp;	// reset count

		while (nCnt > ZERO){	//	i--
			i--;	// array move
			Arr2[i][j] = nNum;	// init
			nCnt--;	// count check
			nNum++;	// numbering
		}

		nCnt = szTemp;	// reset count

		while (nCnt > ZERO){	//	j++
			j++;	// array move
			Arr2[i][j] = nNum;	// init
			nCnt--;	// count check
			nNum++;	// numbering
		}

		szTemp -= 1;	// decrease size
		nCnt = szTemp;	// reset count
	}
}

void snailByBook(int(*Arr2)[ARR_MAX], int szNum){
	// init
	int i = 0;
	int x = 0, y = 0;
	int szTemp = szNum;
	int nNum = 1, dir = 1;
	
	// calc
	Arr2[0][0] = nNum;	// start point
	i++;	// increase count

	while (1){
		for (i; i < szTemp; i++){	// x direction movement
			nNum++;	// numbering
			x += dir;	// move array
			Arr2[y][x] = nNum;	// init
		}

		szTemp -= 1;	// decrease size
		i = 0; // reset count
		
		if (szTemp == ZERO){	// escape condition
			break;
		}

		for (i; i < szTemp; i++){	// y direction movement
			nNum++;	// numbering
			y += dir;	// move array
			Arr2[y][x] = nNum;	// init
		}

		dir *= (-1);	// change direction
		i = 0;	// reset count
	}
	
	// end snailByBook
}

void q3(void){
	// init
	int i = 0;
	int nLimit = 0;

	// enter range
	printf("range : 0 to ");
	scanf("%d", &nLimit);

	// rand()
	for (i = 0; i < CNT_Q3; i++){	// 0 to 5
		printf("%d\n", rand() % (nLimit + 1));	// print random numbers ( 0 to nLimit )
	}
	
	printf("\n");
	
	// end of q3
}

void garbage(int nRand)
{
	// init
	int i = 0;
	int nLimit = 0;
	nRand = 0;

	// rand()
	while (i < CNT_Q3)
	{
		nRand = rand();	// copy random number
		if (nRand > nLimit){	// If random number is bigger than nLimit,
			continue;	// retry.
		}

		printf("print : %d\n", nRand);	// print random number
		i++;	// count check
	}

	// end of garbage
}

void q4(void)
{
	// init
	int nDice1 = 0, nDice2 = 0;

	// srand & rand
	srand((unsigned)time(NULL));	// enter seed
	
	nDice1 = ((rand() % 6) + 1);	// roll Dice1
	nDice2 = ((rand() % 6) + 1);	// roll Dice2

	// print
	printf("Dice 1 : %d\n", nDice1);
	printf("Dice 2 : %d\n", nDice2);
	printf("Total  : %d\n", (nDice1 + nDice2));

	printf("\n");

	// end of q4
}

void q5(void)
{
	// init
	int nRock = 1, nScissors = 2, nPaper = 3;
	int nDraw = 0, nWin = 0, nLose = 0;
	int nCom = 0;
	int nPlayer = 0;

	printf("Rock : 1, Scissors : 2, Paper : 3\n");

	// RSP
	while (1){	
		// enter number
		scanf("%d", &nPlayer);
	
		if (nPlayer < 1 || nPlayer > 3){
			continue;
		}

		// srand & rand
		//srand((unsigned)time(NULL));
		nCom = (rand() % 3) + 1;

		// print statement
		if (nPlayer == 1){		// print you
			printf("you : Rock,     ");
		}else if (nPlayer == 2){
			printf("you : Scissors, ");
		}else if (nPlayer == 3){
			printf("you : Paper,    ");
		}

		if (nCom == 1){		// print com
			printf("com : Rock     -> ");
		}else if (nCom == 2){
			printf("com : Scissors -> ");
		}else if (nCom == 3){
			printf("com : Paper	   -> ");
		}

		if ((nPlayer - nCom) == 1){	// if you lose
			printf("Lose\n\n");	// print
			nLose++;	// count
			break;	// end of RSP
		}		
		if ((nPlayer - nCom) == (-2)){
			printf("Lose\n\n");	// print
			nLose++;	// count
			break;	// end of RSP
		}

		if (nPlayer == nCom){	// if you draw
			printf("Draw\n");	// print
			nDraw++;	// count
		}

		if ((nCom - nPlayer) == (-2)){	// if you win
			printf("Win\n");	// print
			nWin++;	// count
		}
		if ((nCom - nPlayer) == 1){	// if you win
			printf("Win\n");	// print
			nWin++;	// count
		}
	}

	printf("Result : %d Win, %d Draw, %d Lose\n\n\n\n", nWin, nDraw, nLose);	// print result

	// end of q5
}

void q6(void){

	// init
	int ArrCom[ARR_MAX];
	int ArrUser[ARR_MAX];
	int i = 0, j = 0;
	int nCntNum = 0, nCntGame = 0, nRetry = 1;
	int nStrike = 0, nBall = 0;
	char ArrBase[ARR_MAX];

	ArrCom[0] = (rand() % 9) + 1;	// 1 to 9
	ArrCom[1] = (rand() % 10);	// 0 to 9
	ArrCom[2] = (rand() % 10);	// 0 to 9

	while (ArrCom[1] == ArrCom[0]){	// If there is same number with ArrCom[0],
		ArrCom[1] = (rand() % 10); // re - init ArrCom[1]
	}

	while ((ArrCom[2] == ArrCom[0]) || (ArrCom[2] == ArrCom[1])){ // If there is same number with ArrCom[0 or 1],
		ArrCom[2] = (rand() % 10);	// re-init ArrCom[2]
	}

	printf("Com  : ");
	for (i = 0; i < CNT_Q6; i++){	// 0 to 2
		printf("%d ", ArrCom[i]);	// print answer (for test)
	}
	printf("\n\n");

	while (nRetry != ZERO){	// While you say correct answer.
		nCntGame++;	// Count Game
		printf("(%d) enter baseball number\n", nCntGame);
		getchar();
		fgets(ArrBase, ARR_MAX, stdin);	// enter number by string
		nCntNum = 0;	// reset count number for ArrBase
		
		// convert str -> int
		for (i = 0; i < ARR_MAX; i++){
			if (ArrBase[i] == ' '){	// if there is blank (1st, 2nd number)
				ArrUser[nCntNum] = (ArrBase[i - 1] - 48);	// init ArrUser (atoi)
				nCntNum++;	// check count
			}

			if (ArrBase[i] == '\n'){	// if there is enter (last number)
				ArrUser[nCntNum] = (ArrBase[i - 1] - 48);	// init ArrUser (atoi)
				nCntNum++;	// check count
			}

			if (nCntNum == CNT_Q6){
				break;
			}
		}

		printf("USER : ");
		for (i = 0; i < CNT_Q6; i++){	// 0 to 2
			printf("%d ", ArrUser[i]);	// print answer (for test)
		}
		printf("\n");
		
		// check strike & ball
		for (i = 0; i < CNT_Q6; i++){
			if (ArrUser[i] == ArrCom[i]){	// If it is strike,
				nStrike++;	// count strike.
				continue;	// do not check ball
			}
			for (j = 0; j < CNT_Q6; j++){
				if (ArrUser[i] == ArrCom[j]){	// If it is ball,
					nBall++;	// count ball.
				}
			}
		}
		printf("Strike : %d, Ball : %d\n", nStrike, nBall);	// print score
		if (nStrike == CNT_Q6){
			printf("you win!!\n");
			break;
		}

		printf("Retry? (0 to quit) -> ");	// 0 to quit
		scanf("%d", &nRetry);	// enter 0 or other
		nStrike = 0, nBall = 0;	// reset score
		printf("\n");
	}

	printf("\n");
	// end of q6
}