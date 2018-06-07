#include <stdio.h>

void q1(void);
void q1_1(void);
void q1_2(void);
void q1_3(void);
void q1_4(void);

int main(void)
{
	// init
	int nMainQuest = 1;

	// main question number
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

	// sub question number
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
		case 3:
			q1_3();
			break;
		case 4:
			q1_4();
			break;
		default:
			break;
		}
	}
}
void q1_1(void)
{
	// init
	int arr1[5] = { 1, 2, 3, 4, 5 };
	int *ptr1 = arr1;
	int i = 0, j = 0;

	// calc
	while (i < 5)
	{
		*ptr1 += 2;	// value + 2
		ptr1 += 1;	// address + 1
		
		i++;	// cycle count
	}
	
	// print
	for (j = 0; j < 5; j++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n\n\n");	// end q1_1
}

void q1_2(void)
{
	// init
	int arr2[5] = { 1, 2, 3, 4, 5 };
	int *ptr2 = arr2;
	int i = 0, j = 0;

	// calc
	while (i < 5)	// arr[0] to arr[4]
	{
		*(ptr2 + i) += 2;	// add 2
		i++;	// next arr
	}
	
	// print
	for (j = 0; j < 5; j++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n\n");	// end q1_2
}

void q1_3(void)
{
	// init
	int arr[5] = { 1, 2, 3, 4, 5 };
	int *ptr = &arr[4];
	int nTotal = 0;
	int i = 0, j = 0;

	while (i < 5)
	{
		nTotal += *ptr;	// add
		ptr -= 1;	// previous address
		
		i++;
	}

	// print
	for (j = 0; j < 5; j++)
	{
		printf("%d ", arr[i]);
	}

	printf("Total : %d", nTotal);	// print sum

	printf("\n\n");	// end q1_3
}

void q1_4(void)
{
	// init
	int arr[6] = { 1, 2, 3, 4, 5, 6 };
	int *pFront = &arr[0];
	int *pEnd = &arr[5];
	int temp = 0;
	int i = 0, j = 0;

	// calc
	for (i = 0; i < 3; i++)
	{
		temp = *(pFront + i);
		arr[i] = *(pEnd - i);
		arr[5 - i] = temp;
	}

	// print
	for (j = 0; j < 6; j++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n\n");	// end q1_4
}