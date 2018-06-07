#include <stdio.h>

void q1(void);
void q1_1(void);
void q1_2(void);
void q1_3(void);

int main(void)
{
	int nMainQuest = 1;

	while (nMainQuest != 0)
	{
		printf("main question number : ");
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
	int nSubQuest = 1;

	while (nSubQuest != 0)
	{
		printf("sub question number : ");
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

		default:
			break;
		}
	}
}

void q1_1(void)
{
	// init
	int multitable[3][9];
	int i = 0, j = 0;

	// init, print
	for (i = 0; i < 3; i++)	// multi table number 2 to 4
	{
		printf("number %d\n", (i + 2));

		for (j = 1; j < 10; j++)	// 1 to 9
		{
			multitable[i][j] = ((i + 2) * j); // init
			printf("%3d ", multitable[i][j]);	// print
		}

		printf("\n");
	}

	printf("\n");	// end q1_1
}

void q1_2(void)
{
	int arr_horizonal[2][4] = {
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 }
	};

	int arr_vertical[4][2];
	int i = 0, j = 0;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			arr_vertical[j][i] = arr_horizonal[i][j];
		}
	}

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("%d ", arr_vertical[i][j]);
		}
		printf("\n");
	}

}

void q1_3(void)
{
	// init
	int ScoreTable[5][5] = { 0 };
	int i = 0, j = 0;

	for (i = 1; i < 5; i++)
	{
		switch (i)	// print student name
		{
		case 1:
			printf("Score of CH\n");
			break;

		case 2:
			printf("Score of CS\n");
			break;

		case 3:
			printf("Score of YH\n");
			break;

		case 4:
			printf("Score of YS\n");
			break;

		default:
			break;
		}

		for (j = 1; j < 5; j++)
		{
			switch (j)	// print subject name
			{
			case 1:
				printf("Korean  : ");
				break;

			case 2:
				printf("English : ");
				break;

			case 3:
				printf("Math    : ");
				break;

			case 4:
				printf("History : ");
				break;

			default:
				break;
			}

			scanf("%d", &ScoreTable[i - 1][j - 1]);	// enter score

			ScoreTable[i - 1][4]	 += ScoreTable[i - 1][j - 1];	// calc total score of each students
			ScoreTable[4]	 [j - 1] += ScoreTable[i - 1][j - 1];	// calc total score of each subjects
		}

		ScoreTable[4][4] += ScoreTable[i - 1][4];	// calc total all score
		printf("\n");
	}

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%4d", ScoreTable[i][j]);
		}
		
		printf("\n\n");
	}

	printf("\n\n");
}