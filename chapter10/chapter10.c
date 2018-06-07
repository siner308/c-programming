#include <stdio.h>
#include <math.h>

void q1(void);
void q2(void);
void gugudan(int, int);

void q3(void);
int GCD(int, int);

void q4(void);
void nochange(int, int, int, int);

void q5(void);
void q6(void);
void q7(void);
void q8(void);

int main(void)
{
	int nQuest = 0;

	printf("enter question number\n");
	scanf_s("%d", &nQuest);

	switch (nQuest)
	{
	case 1:
		q1();
		main();

	case 2:
		q2();
		main();

	case 3:
		q3();
		main();

	case 4:
		q4();
		main();

	case 5:
		q5();
		main();

	case 6:
		q6();
		main();

	case 7:
		q7();
		main();

	case 8:
		q8();
		main();

	default:
		break;
	}

	return 0;
}

void q1(void)
{
	// init
	int nNum = 0;

	// print question number
	printf("question 1\n");

	// enter number
	printf("enter number\n");
	scanf_s("%d", &nNum);

	// transform
	printf("Decimal = %d\nHexadecimal = %x\n\n", nNum, nNum);
}

void q2(void)
{
	// init
	int nNum1 = 0, nNum2 = 0;

	// print question number
	printf("qustion 2\n");

	// enter numbers
	printf("enter 1st number : ");
	scanf_s("%d", &nNum1);

	printf("\nenter 2nd number : ");
	scanf_s("%d", &nNum2);

	printf("\n");

	// sorting
	if (nNum1 > nNum2)
	{
		gugudan(nNum2, nNum1);
	}
	else
	{
		gugudan(nNum1, nNum2);
	}

	// end
	printf("\n\n");
}

void gugudan(int nNum1, int nNum2)
{
	// init
	int i = 0, j = 0;

	// calc, print
	for (i = nNum1; i < nNum2 + 1; i++)
	{
		for (j = 1; j < 10; j++)
		{
			printf("%d * %d = %d\n", i, j, i * j);
		}

		printf("\n");
	}

	// end
	printf("\n");
}

void q3(void)
{
	// init
	int nNum1 = 0, nNum2 = 0;

	// enter number
	printf("enter 1st number\n");
	scanf_s("%d", &nNum1);

	printf("enter 2nd number\n");
	scanf_s("%d", &nNum2);

	// calc, print
	printf("\nGCD : %d\n", GCD(nNum1, nNum2));
	
	// end
	printf("\n\n");
}

int GCD(int nNum1, int nNum2)
{
	// init
	int i = 0, j = 0, nGCD = 0;

	// order
	if (nNum1 > nNum2)
	{
		j = nNum2;
	}
	else
	{
		j = nNum1;
	}

	// filter, print
	for (i = 2; i < j + 1; i++)
	{
		if (((nNum1 % i) == 0) && ((nNum2 % i) == 0))
		{
			nGCD = i;
		}
	}

	return nGCD;

	// end
	printf("\n");
}

void q4(void)
{
	// init
	int nCostTotal = 3500;
	int nCostCream = 500, nCostSaewoo = 700, nCostCoke = 400;
	int nAfterCream = 0, nAfterSaewoo = 0, nAfterCoke = 0;
	int i = 1, j = 1, k = 1;

	// print your money
	printf("You have : %d won\n", nCostTotal);

	// calc
	while (nCostTotal >= (i * nCostCream))
	{
		// init
		nAfterCream  = nCostTotal;
		nAfterSaewoo = nAfterCream;
		nAfterCoke   = nAfterSaewoo;

		while (nAfterCream >= nCostCream)
		{
			// init
			j = 1, k = 1;
			nAfterSaewoo = nAfterCream;
			nAfterCoke = nAfterSaewoo;

			// calc
			nAfterCream = (nCostTotal - ((i * nCostCream) + (j * nCostSaewoo) + (k * nCostCoke)));
			nochange(nAfterCream, i, j, k);

			while (nAfterSaewoo >= nCostSaewoo)
			{
				// init
				k = 1;
				nAfterCoke = nAfterSaewoo;

				// calc
				nAfterSaewoo = (nCostTotal - ((i * nCostCream) + (j * nCostSaewoo) + (k * nCostCoke)));
				nochange(nAfterSaewoo, i, j, k);

				while (nAfterCoke >= nCostCoke)
				{
					// init

					// calc
					nAfterCoke = (nCostTotal - ((i * nCostCream) + (j * nCostSaewoo) + (k * nCostCoke)));
					nochange(nAfterCoke, i, j, k);
					
					k++;
				}
				j++;
			}
			i++;
		}
	}

	// end
	printf("\n\n");
}

void nochange(int nTotal, int nCream, int nSaewoo, int nCoke)
{
	if (nTotal == 0)
	{
		printf("Cream : %d, Saewoo : %d, Coke : %d\n", nCream, nSaewoo, nCoke);
	}
}

void q5(void)
{
	// init
	int nCnt = 0, nNum = 2, nCheck = 0;
	int i = 1;
	int temp = 0;

	while (nCnt < 10) // until print 10 numbers
	{
		i = 1;
		nCheck = 0;	// init
		temp = (int)sqrt(nNum);

		// calc
		while (1)
		{
			if ((nNum % i) == 0)
			{
				nCheck++;
			}

			if (i >= temp)
			{
				break;
			}

			i++;
		}	

		// check
		if (nCheck == 1) // ??????????
		{
			printf("%d ", nNum); // print
			nCnt++;	// count up
		}

		nNum++;	// number up
	}
	
	printf("\n\n");	// end
}

void q6(void)
{
	// init
	int nTotalSecond = 0;
	int nHour = 0, nMinute = 0;

	// enter number
	printf("enter number (second) : ");
	scanf_s("%d", &nTotalSecond);

	// calc
	while (nTotalSecond > 3600)
	{
		nHour++;
		nTotalSecond -= 3600;
	}

	while (nTotalSecond > 60)
	{
		nMinute++;
		nTotalSecond -= 60;
	}

	printf("h : %d, m : %d, s : %d\n", nHour, nMinute, nTotalSecond); // print

	printf("\n\n");	// end
}

void q7(void)
{
	// init
	int nUserNum = 0, nBinary = 1;
	int nCnt = 0;

	// enter number
	printf("enter number\n");
	scanf_s("%d", &nUserNum);

	// calc
	while (1)
	{
		if (nBinary > nUserNum)
		{
			printf("2^%d <= %d\n", (nCnt - 1), nUserNum);
			break;
		}
		else
		{
			nBinary *= 2;
			nCnt++;
		}
	}

	printf("\n\n");	// end
}

void q8(void)
{
	// init
	int nNum = 1;
	int nPower = 0, i = 0;

	// enter number
	printf("enter power number\n");
	scanf_s("%d", &nPower);

	// calc
	for (i = 1; i <= nPower; i++)
	{
		nNum *= 2;
	}
	
	printf("Result : %d\n", nNum);	// print result
	printf("\n\n");				// end
}