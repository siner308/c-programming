#include <stdio.h>

#define BUF_MAX 50

void q1(void);
void oddnumber(int*, int);
void evennumber(int*, int);

void q2(void);
int calcBinary(int);

void q3(void);

void q4(void);

void q5(void);
void DesSort(int*, int);

int main(void)
{
	int nMainQuest = 1;

	while (nMainQuest != 0)
	{
		printf("enter main question number\n");
		scanf("%d", &nMainQuest);

		switch (nMainQuest)
		{
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

		default:
			break;
		}
	}
	return 0;
}

void q1(void)
{
	// init
	int arr[10];
	int i = 0;

	// enter number
	for (i = 0; i < 10; i++)
	{
		printf("enter : ");
		scanf("%d", &arr[i]);
	}

	// calc
	oddnumber(arr, (sizeof(arr) / sizeof(int)));
	evennumber(arr, (sizeof(arr) / sizeof(int)));

	printf("\n\n");
	
	// end q1
}

void oddnumber(int*arr, int nLen)
{
	// init
	int i = 0;

	printf("odd numbers : ");

	// calc
	for (i = 0; i < nLen; i++)
	{
		if ((arr[i] % 2) != 0)
		{
			printf("%d ", arr[i]);
		}
	}

	printf("\n");
	
	// end oddnumber
}

void evennumber(int*arr, int nLen)
{
	// init
	int i = 0;

	printf("even numbers : ");

	// calc
	for (i = 0; i < nLen; i++)
	{
		if ((arr[i] % 2) == 0)
		{
			printf("%d ", arr[i]);
		}
	}

	printf("\n");
	
	// end evennumber
}

void q2(void)
{
	// init
	int nNum = 0;

	// enter number
	printf("enter number : ");
	scanf("%d", &nNum);

	// calc
	printf("Binary : %d", calcBinary(nNum));	

	printf("\n\n");
	
	// end q2
}

int calcBinary(int nNum)
{
	// init
	int nBinary = 0;
	int nWillAdded = 1;

	// calc
	while (1)
	{
		if ((nNum % 2) == 1)	// If there is remainder,
		{
			nBinary += nWillAdded;	// add 1
		}

		if (nNum <= 1)	// when adding is over, break while
		{
			break;
		}

		nNum /= 2;		// devide nNum
		nWillAdded *= 10;	// next binary
	}

	return nBinary;
	
	// end calcBinary
}

void q3(void)
{
	// init
	int arr_enter[10], arr_ret[10];
	int i = 0, j = 0;
	int cntOdd = 0, cntEven = 0;

	// enter array
	for (i = 0; i < 10; i++)
	{
		printf("arr [%d] : ", i);
		scanf("%d", &arr_enter[i]);

		if ((arr_enter[i] % 2) == 1)	// if it is odd number
		{
			arr_ret[cntOdd] = arr_enter[i];	// add it forward
			cntOdd++;
		}
		else
		{
			arr_ret[9 - cntEven] = arr_enter[i];	// add it backward
			cntEven++;
		}
	}

	// print
	printf("Return : ");
	for (j = 0; j < (sizeof(arr_enter) / sizeof(int)); j++)
	{
		printf("%d ", arr_ret[j]);
	}

	printf("\n\n");
	
	// end q3
}

void q4(void)
{
	// init
	char Arr[BUF_MAX];
	int i = 0, j = 0;

	// enter arr
	getchar();
	fgets(Arr, BUF_MAX, stdin);
	printf("entered : %s\n", Arr);

	// get length
	while (Arr[j] >= 'A' && Arr[j] <= 'z')
	{
		j++;
	}

	printf("escape!! j = %d\n", j);

	// check palindrome
	for (i = 0; i < (j / 2); i++)	
	{
		if (Arr[i] != Arr[(j - 1) - i])
		{
			printf("It is not palinedrome!!");
			break;
		}

		if (i == ((j / 2) - 1))
		{
			printf("It is palindrome!!");
		}
	}

	printf("\n\n");
	
	// end q4
}

void q5(void)
{
	// init
	int arr[7];
	int i = 0;
	int nLen = 0;
	
	// enter array
	for (i = 0; i < 7; i++)
	{
		printf("Arr[%d] : ", i);
		scanf("%d", &arr[i]);
	}

	nLen = sizeof(arr) / sizeof(int);
	printf("nLen = %d\n", nLen);

	DesSort(arr, nLen);	// bubble sort

	// end q5
}

void DesSort(int*arr, int lenArr)
{
	// init
	int i = 0, j = 0;
	int temp;

	// DesSort
	for (i = 0; i < (lenArr - 1); i++)	// next smallest number
	{
		for (j = 0; j < ((lenArr) - i); j++)	// move smallest to backward
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	// print
	printf("answer : ");	
	for (i = 0; i < (lenArr); i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n\n");
	
	// end DesSort
}