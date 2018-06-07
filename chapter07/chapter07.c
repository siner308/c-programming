#include <stdio.h>

int q1_1(void);
int q1_2(void);
int q1_3(void);
int q1_4(void);
int q1_5(void);

int q2_1(void);
int q2_2(void);

int q3_11(void);
int q3_12(void);
int q3_2(void);
int q3_3(void);

int q4_1(void);
int q4_2(void);


int main(void)
{
	//declaration, initialize
	int nQuest = 0;

	printf("Enter Question Number\n");
	scanf_s("%d", &nQuest);

	switch (nQuest)
	{
	case 1:
		q1_1();
		q1_2();
		q1_3();
		q1_4();
		q1_5();
		main();
		break;

	case 2:
		q2_1();
		q2_2();
		main();
		break;

	case 3:
		q3_11();
		q3_12();
		q3_2();
		q3_3();
		main();
		break;

	case 4:
		q4_1();
		q4_2();
		main();
		break;

	default:
		break;
	}


	return 0;
}

int q1_1(void)
{
	//declaration, initialize
	int nCnt = 0, nNum = 0;

	//Enter number
	printf("how many lines do you want to print?\n");
	scanf_s("%d", &nNum);

	//print
	while (nCnt < nNum)
	{
		printf("Hello World!\n");
		nCnt++;
	}
	printf("\n");

	return 0;
}

int q1_2(void)
{
	//declaration, initialize
	int nCnt = 0, nNum = 0;

	//enter number
	printf("how many time multiple '3'?\n");
	scanf_s("%d", &nNum);
	printf("\n");

	//print
	while (nCnt < nNum)
	{
		nCnt++;
		printf("%d¹øÂ° : %2d\n", nCnt, 3 * nCnt);
	}
	printf("\n");

	return 0;
}

int q1_3(void)
{
	//declaration, initialize
	int nTotalNum = 0, nNewNum = 0;

	//enter number
	printf("enter number what you want to add (enter 0 will escape sequence)\n");
	scanf_s("%d", &nNewNum);

	//add
	while (nNewNum != 0)
	{
		nTotalNum += nNewNum;
		printf("Total : %d, Next : ", nTotalNum);
		scanf_s("%d", &nNewNum);
	}
	printf("\n");

	return 0;
}

int q1_4(void)
{
	//declaration, init
	int nNum = 0, nCnt = 9;

	//enter number
	printf("enter number of multiplication table you want to print ( 1 ~ 9 )\n");
	scanf_s("%d", &nNum);


	//check number
	while (0 > nNum)
	{
		printf("please enter bigger than this!");
		scanf_s("%d", &nNum);
	}
	while (nNum > 10)
	{
		printf("please enter smaller than this!");
		scanf_s("%d", &nNum);
	}

	//print multiplication table
	while (0 < nCnt)
	{
		printf("%d * %d = %d\n", nNum, nCnt, nNum * nCnt);
		nCnt--;
	}

	printf("\n\n\n");
	return 0;
}

int q1_5(void)
{
	//declaration, init
	int nNum = 0, nCnt = 0;									//for count
	int nAdd = 0, nTotal = 0, nAvg = 0;						//for calculate

	//enter number (count)
	while (nNum < 1)
	{
		printf("enter number how many you want to add ( it cannot be 0 )\n");
		scanf_s("%d", &nNum);
		continue;
	}

	//calculate part
	nCnt = nNum;
	while (0 < nCnt)
	{
		//enter number (number)
		printf("\nenter number what you want to add\n");
		scanf_s("%d", &nAdd);

		//calculate
		nTotal += nAdd;									//Total	number
		nAvg = nTotal / (1 + nNum - nCnt);					//Avg	number

		//print
		printf("Total : %5d, Average : %5d (%d times left)\n", nTotal, nAvg, nCnt - 1);

		//counting
		nCnt--;
	}

	printf("\naddition is over!!\n\n\n");

	return 0;
}

int q2_1(void)
{
	//declaration, init
	int nCnt = 0, nTotal = 0, nAdd = 0;

	//calculate
	while (nCnt < 5)
	{
		printf("Enter Number what you want to add ( bigger than 0 )\n");
		scanf_s("%d", &nAdd);
		while (nAdd > 0)
		{
			nTotal += nAdd;
			printf("Total : %d (%d times left)\n", nTotal, 4 - nCnt);
			break;
		}
		nCnt++;
	}

	printf("\naddition is over!\n\n\n");
	return 0;
}

int q2_2(void)
{
	//declaration, init
	int nCnt = 0, nNum = 0;

	//print
	while (nCnt < 5)
	{
		while (nCnt > nNum)
		{
			printf("o");
			nNum++;
		}
		printf("*\n");
		nCnt++;
		nNum = 0;
	}

	printf("\n\n\n");

	return 0;
}

int q3_11(void)		//way1
{
	//declaration, init
	int nTotal = 0, nNum = 1;

	//calculate
	while (nNum != 0)
	{
		printf("Enter int (0 to quit) : \n");
		scanf_s("%d", &nNum);
		nTotal += nNum;
		printf("Total : %d\n", nTotal);
	}
	
	//end
	printf("\n0 is entered!!\n\n\n");

	return 0;
}

int q3_12(void)		//way2
{
	//declaration, init
	int nTotal = 0, nNum = 0;

	//calculate
	do
	{
		printf("Enter int (0 to quit) : \n");
		scanf_s("%d", &nNum);
		nTotal += nNum;
		printf("Total : %d\n", nTotal);
	} while (nNum != 0);

	//end
	printf("\n0 is entered!!\n\n\n", nTotal);
	
	return 0;
}

int q3_2(void)
{
	//declaration, init
	int nTotal = 0, nNum = 0;

	//target
	printf("addition 0 to 100 (except even numbers)\n");
	
	//calculate
	do
	{
		do
		{
			nNum++;
		} while (nNum % 2 == 1);

		nTotal += nNum;

	}while (nNum < 100);

	//end
	printf("Total : %d\n\n\n", nTotal);

	return 0;
}

int q3_3(void)
{
	//declaration 
	int table = 2, dan = 1;

	//calculate
	do
	{
		dan = 1;

		//table*(1~9)
		do
		{
			printf("%d * %d = %d \n", table, dan, table * dan);
			dan++;
		} while (dan <= 9);

		//(1~9)*dan
		table++;
		printf("\n");
	} while (table <= 9);

	//end
	printf("\n\n\n");

	return 0;
}

int q4_1(void)
{
	//declaration, init
	int nNum1 = 0, nNum2 = 0, nTotal = 0;

	//enter forward number
	printf("enter forward number\n");
	scanf_s("%d", &nNum1);

	//enter backward number
	printf("enter backward number\n(forward number < backward number)\n");
	do
	{
		scanf_s("%d", &nNum2);
	} while (nNum1 > nNum2);
	
	//calculate
	for (int i = nNum1; i < nNum2; i++)
	{
		nTotal += i;
	}

	//end
	printf("nTotal : %d\n\n", nTotal);
	
	return 0;
}

int q4_2(void)
{
	//declaration, init
	int nNum = 0, nTotal = 1;

	//enter number
	printf("enter number to calculate factorial\n");
	scanf_s("%d", &nNum);

	//error
	if (nNum <= 0)
	{
		printf("please enter larger number than 0\n");
		q4_2();
	}

	//calculate
	for (int i = 1; i < nNum + 1; i++)
	{
		nTotal *= i;
	}
	printf("%d! = %d\n\n\n",nNum, nTotal);

	return 0;
}