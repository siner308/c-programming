#include <stdio.h>

void q1_1(void);
int selectbig(int, int, int);
int selectsmall(int, int, int);

void q1_2(void);
int CelToFah(int);
int FahToCel(int);

void q1_3(void);
void fibonacci(int);


void q2(void);
int AddToTotal(int);

int main(void)
{
	//declaration, init
	int nQuest = 0;

	//enter question number
	printf("enter question number\n");
	scanf_s("%d", &nQuest);

	//select
	switch (nQuest)
	{
	case 1:
		printf("\nQuestion Number : 1\n\n");
		q1_1();
		q1_2();
		q1_3();
		main();

	case 2:
		printf("\nQuestion Number : 2\n\n");
		q2();
		main();

	default:
		break;
	}

	return 0;
}

//question number 1
void q1_1(void)
{
	//declaration
	int nNum1 = 0, nNum2 = 0, nNum3 = 0;
	
	//print question number
	printf("q1_1\n\n");

	//enter integers
	printf("enter three integers\n");

	printf("\nnumber 1 : ");
	scanf_s("%d", &nNum1);
	printf("\nnumber 2 : ");
	scanf_s("%d", &nNum2);
	printf("\nnumber 3 : ");
	scanf_s("%d", &nNum3);

	//print
	printf("%d is largest!!\n", selectbig(nNum1, nNum2, nNum3));
	printf("%d is smallest!!\n", selectsmall(nNum1, nNum2, nNum3));

	printf("\n\n\n");
}

void q1_2(void)
{
	//declaration
	int nNum = 0, nType = 0;

	//print question number
	printf("q1_2\n\n");

	//temperature type
	printf("enter type of temperature ( 1 : Celsius, 2 : Fahrenheit )\n");
	scanf_s("%d", &nType);

	//enter temperature
	printf("\nenter temperature\n");
	scanf_s("%d", &nNum);

	//calculate, print
	if (nType == 1)
	{
		printf("Celsius -> Fahrenheit\n");
		printf("Fahrenheit : %d", CelToFah(nNum));
	}
	else if (nType == 2)
	{
		printf("Fahrenheit -> Celsius\n");
		printf("Celsius : %d", FahToCel(nNum));
	}
	else
	{
		printf("What is This?! Try Again!!");
		q1_2();
	}

	//end
	printf("\n\n\n");
}

void q1_3(void)
{
	//declaration
	int nNum = 0;

	//print question number
	printf("q1_3\n\n");

	//enter count number
	printf("enter count of fibonacci\n");
	scanf_s("%d", &nNum);


	//error
	while ((nNum < 48) && (nNum > 57))
	{
		printf("You must enter correct number");
		scanf_s("%c", &nNum, 2);
	}

	//print fibonacci
	fibonacci(nNum);

	//end
	printf("\n\n");
}

//question number 2
void q2(void)
{
	//declaration
	int num = 0, i = 0;

	//print question number
	printf("q2\n\n");

	//print
	for (i = 0; i < 3; i++)
	{
		printf("enter %d :", i + 1);
		scanf_s("%d", &num);
		printf("accumulation : %d\n", AddToTotal(num));
	}
	return 0;
}

//function q1_1
int selectbig(int nNum1, int nNum2, int nNum3)
{
	int retVal = nNum1;

	if (retVal < nNum2)
	{
		retVal = nNum2;
	}
	if (retVal < nNum3)
	{
		retVal = nNum3;
	}
	
	return retVal;
}

int selectsmall(int nNum1, int nNum2, int nNum3)
{
	int retVal = nNum1;

	if (retVal > nNum2)
	{
		retVal = nNum2;
	}
	if (retVal > nNum3)
	{
		retVal = nNum3;
	}

	return retVal;
}

//function q1_2
int CelToFah(int nNum)
{
	int retVal = ((1.8 * nNum) + 32);

	return retVal;
}

int FahToCel(int nNum)
{
	int retVal = ((nNum - 32) / 1.8);

	return retVal;
}

//function q1_3
void fibonacci(int nNum)
{
	//declaration
	int nNum1 = 0, nNum2 = 1;
	int nNumNext = 0;
	int i = 0;

	//fibonacci
	
	//default
	printf("%d ", nNum1);
	printf("%d ", nNum2);

	//calculate
	for (i = 2; i < nNum; i++)
	{
		nNumNext = nNum1 + nNum2;
		nNum1 = nNum2;
		nNum2 = nNumNext;

		printf("%d ", nNumNext);
	}

	//end
	printf("\n");
}

//function q2
int AddToTotal(int num)
{
	static int total = 0;

	total += num;
	return total;
}