#include <stdio.h>

int q1(void);
int q2(void);
int q3(void);
int q4(void);
int q5(void);

int main(void)
{
	//enter question number
	int nQuest = 0;

	printf("Enter question number\n");
	scanf_s("%d", &nQuest);
	
	switch (nQuest)
	{
	case 1:
		q1();
		main();
		break;

	case 2:
		q2();
		main();
		break;

	case 3:
		q3();
		main();
		break;

	case 4:
		q4();
		main();
		break;

	case 5:
		q5();
		main();
		break;

	default:
		break;
	}	

		return 0;
}

int q1(void)
{
	//declaration
	int nX1 = 0, nY1 = 0, nX2 = 0, nY2 = 0;				//variable number for points

	int nX = 0;											//length between X1,X2
	int nY = 0;											//length between Y1,Y2

	int	nSizeofArea = 0;								//area size between two points

	printf("Question.1 (calculate size of quadrangle)\n");

	printf("Enter two coordinates of points.\n\n");
	

	//enter
	//1st point
	printf("1st point (X)\n");
	scanf_s("%d", &nX1);

	printf("1st point (Y)\n");
	scanf_s("%d", &nY1);

	printf("\n1st point : (%d, %d)\n\n", nX1, nY1);

	//2nd point
	printf("2nd point (X)\n");
	scanf_s("%d", &nX2);

	printf("2nd point (Y)\n");
	scanf_s("%d", &nY2);

	printf("\n2nd point : (%d, %d)\n\n", nX2, nY2);

	//calculate length
	nX = nX2 - nX1;
	nY = nY2 - nY1;

	//check negative length
	if (nX < 0)
	{
		nX = nX * (-1);
	}
	else
	{
		//nX >= 0
	}

	if (nY < 0)
	{
		nY = nY * (-1);
	}
	else
	{
		//nY >= 0
	}

	//calculate area
	nSizeofArea = nX * nY;

	//print
	printf("\n\nSize : %d\n\n\n", nSizeofArea);

	return 0;
}

int q2(void)
{
	//declaration
	int nNum1 = 0, nNum2 = 0;
	int nMultiple = 0, nDivide = 0, nAdd = 0, nSubtract = 0;

	//enter
	printf("Enter two numbers\n\n");
	
	printf("1st number\n");
	scanf_s("%d", &nNum1);

	printf("2nd number\n");
	scanf_s("%d", &nNum2);

	//calculate
	nAdd		= nNum1 + nNum2;
	nSubtract	= nNum1 - nNum2;
	nMultiple	= nNum1 * nNum2;
	nDivide		= nNum1 / nNum2;

	//print
	printf("\nAdd		: %d\n", nAdd);
	printf("Subtract	: %d\n", nSubtract);
	printf("Multiple	: %d\n", nMultiple);
	printf("Divide		: %d\n", nDivide);

	return 0;
}

int q3(void)
{
	//print answer
	printf("q3_1\nASCII Code has a value from 0 to 127\n(Extended Version has a value from 0 to 255\n\n");
	printf("q3_2\nUppercase Alphabet has a value from 65 to 132\n\n");
	printf("q3_3\nlowercase - Uppercase = 32\n\n\n");
	
	return 0;
}

int q4(void)
{
	//declaration
	int nNum;

	//enter integer
	printf("Enter the value of the ASCII code as an integer.\n");
	scanf_s("%d", &nNum);

	//itoa
	printf("%d : %c\n\n\n", nNum, nNum);

	return 0;
}

int q5(void)
{
	//declaration
	char cASCII = 'A';
	
	//enter character
	printf("Enter the value of the ASCII code as an character.\n");
	scanf_s("%*c%c", &cASCII);													//advice by madder

	//atoi
	printf("ASCII : %c, Value : %d\n\n", cASCII, cASCII);

	return 0;
}