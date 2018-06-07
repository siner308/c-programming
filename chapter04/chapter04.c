#include <stdio.h>

int q1_1(void);
int q1_2(void);
int q2_1(void);
int q2_2(void);
int q2_3(void);
int q3_1(void);
int q3_2(void);
int q4_1(void);
int q4_2(void);



int main(void)
{
	//select question number
	int nQuest = 0;

	printf("input : Question Number (1~4)\n\n");
	scanf_s("%d", &nQuest);

	if (nQuest == 1)
	{
		printf("Question 04-1\n\n");
		q1_1();
		q1_2();
		main();
	}

	else if (nQuest == 2)
	{
		printf("Question 04-2\n\n");
		q2_1();
		q2_2();
		q2_3();
		main();
	}

	else if (nQuest == 3)
	{
		printf("Question 04-3\n\n");
		q3_1();
		q3_2();
		main();
	}

	else if (nQuest == 4)
	{
		printf("Question 04-4\n\n");
		q4_1();
		q4_2();
		main();
	}

	else
	{
		return 0;
	}

	return 0;
}

int q1_1(void)
{	
	printf("hexadecimal notation\n");

	for (int i = 8; i < 20; i++)
	{
		printf("%d -> %x\n", i, i, i);			//%d to %x
	}

	printf("\n");

	return 0;
}

int q1_2(void)
{
	printf("octal number system\n");

	for (int i = 5; i < 19; i++)
	{
		printf("%d -> %o\n", i, i);				//%d to %o
	}

	printf("\n\n\n\n");

	return 0;
}

int q2_1(void)
{
	printf("4bit can express 2^4 numbers\n");
	printf("1byte can express 2^8 numbers\n");
	printf("4byte can express 2^(8*4) numbers\n\n");

	return 0;
}

int q2_2(void)
{
	printf("1\n2\n4\n8\n16\n32\n64\n128\n\n");

	return 0;
}

int q2_3(void)
{
	printf("00010001 = 16 + 1 = 17\n10100010 = 128 + 32 + 2 = 162\n11110111 = 255 - 16 = 239\n\n\n\n");

	return 0;
}

int q3_1(void)
{
	printf("01001111 = 64 + 8 + 4 + 2 + 1 = 79\n00110011 = 32 + 16 + 2 + 1 = 51\n\n");
	return 0;
}

int q3_2(void)
{
	printf("10101001 = 10101000 + 1 = - 01010111 = - ( 64 + 16 + 4 + 2 + 1 ) = - 87\n11110000 = 11101111 + 1 = - 00010000 = -16\n\n\n\n");
	return 0;
}

int q4_1(void)
{
	int num1 = 0;

	printf("input negative number\n");
	scanf_s("%d\n", &num1);				//input number

	if (num1 >= 0)
	{
		printf("%d\n\n", num1);			//if it is plus, just print it!
	}
	else
	{
		num1 = ~(num1 - 1);				//if it is minus, make it plus!
		printf("%d\n\n", num1);			//print it!
	}


	return 0;
}

int q4_2(void)
{
	int num1 = 3;

	printf("bit calculation 3*8/4");
	num1 = num1 << 3 >> 2;				//num1 * 8 / 4

	printf("°ª : %d", num1);

	return 0;
}