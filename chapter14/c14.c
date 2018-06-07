#include <stdio.h>

void q1(void);
void q1_1(void);
int SquareByValue(int);
void SquareByReference(int*);

void q1_2(void);
void Swap3(int*, int*, int*);

int main(void)
{
	// init	
	int nMainQuest = 1;

	// main
	while (nMainQuest != 0)
	{
		printf("enter main question number\n");
		scanf("%d", &nMainQuest);

		switch (nMainQuest)
		{
		case 1:
			q1();
			break;

		default:
			break;
		}
	}
	return 0;
}

void q1(void)
{
	// init
	int nSubQuest = 1;

	// sub question
	while (nSubQuest != 0)
	{
		printf("enter sub question number\n");
		scanf("%d", &nSubQuest);

		switch (nSubQuest)
		{
		case 1:
			q1_1();
			break;

		case 2:
			q1_2();
			break;

		default:
			break;
		}
	}
}
void q1_1(void)
{
	// init
	int nNum = 0;
	int *pNum = &nNum;

	printf("enter number\n");
	scanf("%d", &nNum);

	printf("Call-by-value : %d\n", SquareByValue(nNum));

	SquareByReference(&nNum);
	printf("Call-by-reference : %d\n", nNum);

}

int SquareByValue(int Num)
{
	// init
	int nSquare = 0;

	nSquare = (Num * Num);	// calc

	return nSquare;	// end SquareByValue
}

void SquareByReference(int*pNum)
{
	int temp = *pNum;
	
	*pNum = (temp * temp);
}

void q1_2(void)
{
	// init
	int nNum1 = 0, nNum2 = 0, nNum3 = 0;
	int *pNum1 = &nNum1;
	int *pNum2 = &nNum2;
	int *pNum3 = &nNum3;

	// enter number
	printf("enter nNum1 : ");
	scanf("%d", &nNum1);
	printf("enter nNum2 : ");
	scanf("%d", &nNum2);
	printf("enter nNum3 : ");
	scanf("%d", &nNum3);
	
	// calc
	Swap3(pNum1, pNum2, pNum3);	// swap
	printf("nNum1 : %d\nnNum2 : %d\nnNum3 : %d\n", nNum1, nNum2, nNum3);	// print
	printf("\n\n");	// end q1_2
}

void Swap3(int*pNum1, int*pNum2, int*pNum3)
{
	// init
	int temp = 0;

	// swap
	temp = *pNum3;
	*pNum3 = *pNum2;
	*pNum2 = *pNum1;
	*pNum1 = temp;

	// end Swap3
}