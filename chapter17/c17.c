#include <stdio.h>

void q1(void);
void MaxAndMin(int*, int**, int**);

int main(void)
{
	int nQuest = 1;

	while (nQuest != 0)
	{
		printf("0 to quit\n");
		scanf("%d", &nQuest);

		switch (nQuest)
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
	int *maxPtr;
	int *minPtr;
	int arr[5];
	int i = 0;

	printf("enter number\n");
	for (i = 0; i < 5; i++)
	{
		printf("enter number (%d) ", (i + 1));
		scanf("%d", &arr[i]);
		printf("address : %d\n", &arr[i]);
	}

	MaxAndMin(arr, &maxPtr, &minPtr);	// calc

	printf("Max : %2d, Address : %d\n", *maxPtr, maxPtr);
	printf("Min : %2d, Address : %d\n", *minPtr, minPtr);
	printf("\n\n");
}

void MaxAndMin(int* arr, int **dpMax, int **dpMin)
{
	int i = 0;
	*dpMax = &arr[0];
	*dpMin = &arr[0];

	for (i = 0; i < 4; i++)
	{
		if (**dpMax < arr[i + 1])
		{
			*dpMax = &arr[i + 1];
		}
	}

	for (i = 0; i < 4; i++)
	{
		if (**dpMin > arr[i + 1])
		{
			*dpMin = &arr[i + 1];
		}
	}
}