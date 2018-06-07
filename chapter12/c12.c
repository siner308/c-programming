#include <stdio.h>

void q1_1(void);
void q1_2(void);

int main(void)
{
	// init
	int nQuest = 1;

	while (nQuest != 0)	// keep running while 0 is entered
	{
		printf("enter question number\n");
		scanf("%d", &nQuest);	// enter question number

		switch (nQuest)
		{
		case 1:
			q1_1();
			q1_2();
			break;

		default:
			break;
		}
	}
	return 0;
}

void q1_1(void)
{
	int num = 10;
	int* ptr1 = &num;
	int* ptr2 = ptr1;
	
	(*ptr1)++;
	(*ptr2)++;

	printf("%d\n", num);	// print
	printf("\n\n");	// end
}

void q1_2(void)
{
	// init
	int num1 = 10, num2 = 20;
	int *ptr1 = &num1;
	int *ptr2 = &num2;

	printf("Q.1_2\n");

	// calc
	*ptr1 += 10;
	*ptr2 -= 10;

	ptr1 = &num2;
	ptr2 = &num1;

	printf("ptr1 : %d\nptr2 : %d\n", *ptr1, *ptr2);	// print

	printf("\n\n");	// end q1_2
}