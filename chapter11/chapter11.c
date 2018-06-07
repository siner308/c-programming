#include <stdio.h>
#include <string.h>

#define	BUF_MAX 50

void q1_1(void);
int SelectBig(int, int, int, int, int);
int SelectSmall(int, int, int, int, int);

void q1_2(void);
void q2_1(void);
void q2_2(void);
void q2_3(void);
int getlength(char[]);
char selectbig(char[]);

void test(void);

int main(void)
{
	// init
	int nQuest = 1;

	// sequence
	while (nQuest != 0)
	{
		printf("enter question number\n");
		scanf("%d", &nQuest);
		getchar();

		switch (nQuest)
		{
		case 1:
			q1_1();
			q1_2();
			break;

		case 2:
			q2_1();
			q2_2();
			q2_3();
			break;

		case 3:
			test();

		default:
			break;
		}

	}
	return 0;
}

void q1_1(void)
{
	// init
	int arr[5];
	int nBig = 0, nSmall = 0;
	int nTotal = 0;

	// enter number
	printf("enter arr[0] : ");
	scanf("%d", &arr[0]);
	printf("enter arr[1] : ");
	scanf("%d", &arr[1]);
	printf("enter arr[2] : ");
	scanf("%d", &arr[2]);
	printf("enter arr[3] : ");
	scanf("%d", &arr[3]);
	printf("enter arr[4] : ");
	scanf("%d", &arr[4]);

	// print result
	printf("Big   : %d\n", SelectBig(arr[0], arr[1], arr[2], arr[3], arr[4]));
	printf("Small : %d\n", SelectSmall(arr[0], arr[1], arr[2], arr[3], arr[4]));
	printf("Total : %d\n", (arr[0] + arr[1] + arr[2] + arr[3] + arr[4]));

	printf("\n\n");	// end q1_1
}

int SelectBig(int num1, int num2, int num3, int num4, int num5)
{
	int retVal = num1;

	if (retVal < num2)
	{
		retVal = num2;
	}
	if (retVal < num3)
	{
		retVal = num3;
	}
	if (retVal < num4)
	{
		retVal = num4;
	}
	if (retVal < num5)
	{
		retVal = num5;
	}

	return retVal;
}

int SelectSmall(int num1, int num2, int num3, int num4, int num5)
{
	int retVal = num1;

	if (retVal > num2)
	{
		retVal = num2;
	}
	if (retVal > num3)
	{
		retVal = num3;
	}
	if (retVal > num4)
	{
		retVal = num4;
	}
	if (retVal > num5)
	{
		retVal = num5;
	}

	return retVal;
}

void q1_2(void)
{
	// init
	char str[] = "Good time";

	printf("%s\n", str);	// print

	printf("\n\n");	// end q1_2
}

void q2_1(void)
{
	// init
	char str1[BUF_MAX];
	int nLength1 = 0;

	// question number, enter string
	printf("Q2_1.\nEnter String\n");
	scanf("%s", str1);

	nLength1 = getlength(str1);

	printf("entered : %s\nlength : %d\n", str1, nLength1);	// print
	printf("\n\n");	// end q2_1
}

void q2_2(void)
{
	// init
	char str2[BUF_MAX], strtemp[BUF_MAX];
	int nLength2 = 0, j = 0;

	// question number, enter string
	printf("Q2_2.\nEnter String\n");
	scanf("%s", str2);

	// length check
	nLength2 = getlength(str2);

	// reverse
	for (j = 0; j <= nLength2; j++)
	{
		strtemp[j] = str2[(nLength2 - 1) - j];
	}

	printf("entered : %s\nreversed : %s", str2, strtemp);	// print
	printf("\n\n");	// end q2_2
}

void q2_3(void)
{
	// init
	char str3[BUF_MAX];
	int nLength3 = 0;
	char chBig = 0;

	printf("Q2_3.\nEnter String\n"); // question number
	getchar();

	fgets(str3, BUF_MAX, stdin);

	chBig = selectbig(str3);
	printf("Entered : %s\nBiggest ASCII : %c", str3, chBig); // enter string

	printf("\n\n");	// end q2_3	
}

int getlength(char strlen[BUF_MAX])
{
	// init
	//char strlen[BUF_MAX];
	int i = 0;

	// get length
	for (i = 0; i < BUF_MAX; i++)
	{
		if (strlen[i] == 0)
		{
			return i;
		}
	}

	// end getlength
}

char selectbig(char strbig[BUF_MAX])
{
	// init
	char chBig2;
	int i = 1, nLength = 0;

	nLength = getlength(strbig);	// get length
	chBig2 = strbig[0];	// set chBig2

	// calc
	while (strbig[i] != '\0')
	{
		if (chBig2 < strbig[i])
		{
			chBig2 = strbig[i];
		}
		i++;
	}

	return chBig2;

	//end selectbig
}

void test(void)
{
	// init
	char str[BUF_MAX];

	printf("this is test mode : ");

	fgets(str, sizeof(str), stdin);

	printf("entered : %s", str);
}