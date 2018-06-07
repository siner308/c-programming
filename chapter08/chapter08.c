#include <stdio.h>

void q1_1(void);
void q1_2(void);
void q1_3(void);
void q1_4(void);

void q2_1(void);
void q2_2(void);

void q3(void);


int main(void)
{
	//declaration
	int nQuest = 0;

	//enter question number
	printf("Enter Question Number\n");
	scanf_s("%d", &nQuest);

	//questions
	switch (nQuest)
	{
	case 1:
		q1_1();
		q1_2();
		q1_3();
		q1_4();
		main();

	case 2:
		q2_1();
		q2_2();
		main();

	case 3:
		q3();
		main();

	default:
		break;
	}

	return 0;
}

void q1_1(void)
{
	//declaration, init
	int i = 0;

	//question number
	printf("Question 1-1\n\n");

	//filter
	for ( i = 1; i < 100; i++)
	{
		if (((i % 7) == 0) || ((i % 9) == 0))
		{ 
			printf("%d ", i);
		}
	}

	printf("\n\n\n");
}

void q1_2(void)
{
	//declaration, init
	int nNum1 = 0, nNum2 = 0, nResult = 0;

	//question number
	printf("Question 1-2\n\n");

	printf("enter 1st number\n");
	scanf_s("%d", &nNum1);

	printf("enter 2nd number\n");
	scanf_s("%d", &nNum2);

	//calculate
	nResult = nNum1 - nNum2;

	//negative check
	if (nResult < 0)
	{
		nResult *= -1;
	}

	printf("Result : %d\n\n\n", nResult);
}
void q1_3(void)
{
	//declaration, init
	int nKorean = 0, nEnglish = 0, nMath = 0, nAvg = 0;
	
	//question number
	printf("Question 1-3\n\n");

	//enter subject score
	printf("Korean Score : ");
	scanf_s("%d", &nKorean);
	while ((nKorean > 100) || (nKorean < 0))
	{
		printf("enter right score\n");
		printf("Korean Score : ");
		scanf_s("%d", &nKorean);
	}


	printf("English Score : ");
	scanf_s("%d", &nEnglish);
	while ((nEnglish > 100) || (nEnglish < 0))
	{
		printf("enter right score\n");
		printf("English Score : ");
		scanf_s("%d", &nEnglish);
	}

	printf("Math Score : ");
	scanf_s("%d", &nMath);
	while ((nMath > 100) || (nMath < 0))
	{
		printf("enter right score\n");
		printf("Math Score : ");
		scanf_s("%d", &nMath);
	}

	nAvg = (nKorean + nEnglish + nMath) / 3;

	if (nAvg >= 90)
	{
		printf("Congratulation!! Your Score is A!!\n\n\n");
	}
	else if (nAvg >= 80)
	{
		printf("Great!! Your Score is B!!\n\n\n");
	}
	else if (nAvg >= 70)
	{
		printf("Not Bad. Your Score is C.\n\n\n");
	}
	else if (nAvg >= 50)
	{
		printf("hmm... Your Score is D.\n\n\n");
	}
	else
	{
		printf("See you again. Your Score is F.\n\n\n");
	}
}
void q1_4(void)
{
	//declaration, init
	int nNum1 = 0, nNum2 = 0, nResult = 0;

	//question number
	printf("Question 1-4\n\n");

	//enter number
	printf("enter 1st number\n");
	scanf_s("%d", &nNum1);

	printf("enter 2nd number\n");
	scanf_s("%d", &nNum2);

	//calculate
	nResult = nNum1 - nNum2;
	nResult = (nResult > 0) ? (nResult) : ((-1) * nResult);

	printf("Result : %d\n\n\n", nResult);
}

void q2_1(void)
{
	//declaration, init
	int i = 0, nDan = 0;

	//question number
	printf("Question 2-1\n\n");

	//calculate, print
	for (nDan = 2; 9 > nDan; nDan++)
	{
		printf("\n");

		for (i = 1; i <= nDan; i++)
		{
			if (nDan % 2 != 0)
				continue;
			printf("%d * %d = %d\n", nDan, i, nDan * i);
		}
	}

	printf("\n\n\n");
}
void q2_2(void)
{
	//declaration, init
	int nA = 0, nZ = 0;

	//question number
	printf("Question 2-2\n\n");

	//calculate, print
	for (nA = 0; nA <= 9; nA++)
	{
		for (nZ = 0; nZ <= 9; nZ++)
		{
			if ((11 * nA + 11 * nZ) == 99)
			{
				printf("A : %d, Z : %d\n", nA, nZ);
			}
		}
	}

	//end
	printf("\n\n\n");
}

void q3(void)
{
	//declaration, init
	int nNum = 0;

	//enter number
	printf("enter number\n");
	scanf_s("%d", &nNum);

	//error
	while (nNum < 0)
	{
		printf("negative cannot be entered!!\n");
		scanf_s("%d", &nNum);
	}

	//switch..??
	switch (nNum / 10)
	{
	case 0:
	{
		printf("0이상 10미만");
		break;
	}
	case 1:
	{
		printf("10이상 20미만");
		break;
	}
	case 2:
	{
		printf("20이상 30미만");
		break;
	}
	default:
	{
		printf("30이상");
		break;
	}
	}

	//end
	printf("\n\n\n");
}